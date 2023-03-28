#include <iostream>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int shmid =0;
void* shmaddr =nullptr;

void shm_close(int sig){
    std::cout << "Receive SIGINT " << std::endl;
    if(shmaddr != nullptr){
        shmdt(shmaddr);
        std::cout << "disconnect shm" << std::endl;
    }
    if(shmid != 0){
        shmctl(shmid,IPC_RMID,0);
        std::cout << "destory shm" << std::endl;
    } 
}

int main(int argc, char*argv[]){

    signal(SIGINT,shm_close);
    std::string node_name = "/shm/test";
    int shm_size = 4096;

    std::hash<std::string> gethash;
    auto key = gethash(node_name);

    shmid = shmget(key,shm_size,0644|IPC_CREAT |IPC_EXCL);
    if(shmid == -1){
        std::cout << "Failed to creat shm" << std::endl;
    }

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

    if(shmdt(shmaddr) == -1){
        std::cout << "Failed to disconnect shm" << std::endl;
    }
    if(shmctl(shmid,IPC_RMID,0) == -1){
        std::cout << "Failed to destory shm" << std::endl;
    }

    std::cout << "Finish shm writer" << std::endl;
    return 0;
}