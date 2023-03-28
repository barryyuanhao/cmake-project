#include <iostream>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    std::string node_name = "/shm/test";
    int shm_size =4096;

    std::hash<std::string> gethash;
    auto key = gethash(node_name);

    int shmid = shmget(key, shm_size, 0644 |IPC_CREAT);
    if(shmid == -1){
        std::cout << "Failed to creat shm" << std::endl;
    }
    void* shmaddr = shmat(shmid,nullptr,0);
    if(shmaddr == (void*)-1){
        std::cout << "Failed to connect shm" << std::endl;
    }
    while (true)
    {
        std::cout << static_cast<char*>(shmaddr) << std::endl;
        if (strcmp(static_cast<char*>(shmaddr),"end") == 0)
        {
            break;
        }
        usleep(500000);
    }

    std::cout << "Finish the shm reader" << std::endl;
    

    return 0;
}