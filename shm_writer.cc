#include <iostream>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int shmid =0;
void* shmaddr =nullptr;

// 接收到 SIGINT (Ctrl + C)后，关闭进程空间地址映射 以及销毁共享内存
void shm_close(int sig){
    std::cout << "Receive SIGINT " << std::endl;
    if(shmaddr != nullptr){
        // 关闭进程空间地址映射
        shmdt(shmaddr);
        std::cout << "disconnect shm" << std::endl;
    }
    if(shmid != 0){
        // 销毁共享内存
        shmctl(shmid,IPC_RMID,0);
        std::cout << "destory shm" << std::endl;
    } 
}

int main(int argc, char*argv[]){
    // 系统信号处理，避免接收到 SIGINT (Ctrl + C)后，shm无法关闭的问题
    signal(SIGINT,shm_close);
    std::string node_name = "/shm/test";
    int shm_size = 4096;

    // 创建哈希变量，根据channel信息生成哈希值，用于创建共享内存的唯一标识key
    std::hash<std::string> gethash;
    auto key = gethash(node_name);

    // 原型： int shmget(key_t key, size_t size, int shmflg);
    // 创建共享内存
    // key ：唯一标识ID，各进程通过该key识别共享内存
    // size：设置共享内存大小，用户设置，系统会自动设置为4096的整数倍，超过用户部分设置为0且禁用
    // 0644：设置共享内存使用权限 （创建用户，用户组，其他）
    // IPC_CREAT：检查有无该共享内存，没有就创建；
    // IPC_EXCL：检查共享内存是否存在，与IPC_CREAT配合使用，存在共享内存返回错误
    shmid = shmget(key,shm_size,0644|IPC_CREAT |IPC_EXCL);
    if(shmid == -1){
        std::cout << "Failed to creat shm" << std::endl;
    }

    // 原型： void *shmat(int shmid, const void *shmaddr, int shmflg);
    // 链接共享内存，启动对共享内存的访问，并且讲共享内存连接到进程的地址空间
    // shmid: 共享内存ID
    // shmaddr：设置共享内存内核地址；一般填写nullptr，委托内核制定
    // shmflg： 标识进程连接后对共享内存的操作权限，通常设置为0，读写模式
    shmaddr = shmat(shmid,nullptr,0);
    if(shmaddr == (void *)-1){
        std::cout << "Failed to connect shm" << std::endl;
        shmctl(shmid,IPC_RMID,0);
    }

    for (int i = 0; i < 50; i++)
    {
        std::string temp = "The value is " + std::to_string(i);
        memcpy(shmaddr, temp.c_str(),strlen(temp.c_str()));
        // strcpy(static_cast<char*>(shmaddr),temp.c_str());

        std::cout << temp << std::endl;
        sleep(1);
    }

    strcpy(static_cast<char*>(shmaddr),"end");

    // 将shmat关联的共享内存脱离目前的进程
    if(shmdt(shmaddr) == -1){
        std::cout << "Failed to disconnect shm" << std::endl;
    }
    // 控制共享内存的各种操作函数
    // IPC_STAT ： 获取共享内存的状态
    // IPC_SET ： 如果进程有足够权限，设置共享内存状态
    // IPC_RMID ： 标记共享内存被销毁
    if(shmctl(shmid,IPC_RMID,0) == -1){
        std::cout << "Failed to destory shm" << std::endl;
    }

    std::cout << "Finish shm writer" << std::endl;
    return 0;
}