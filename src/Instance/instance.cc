#include <iostream>
#include <memory>
#include <mutex>

class Singleton_v1{
public:
    ~Singleton_v1(){
        std::cout << "~Singleton_v1: " << std::endl;
    }
    Singleton_v1(const Singleton_v1&) = delete;
    Singleton_v1& operator=(const Singleton_v1&)= delete;
    static std::shared_ptr<Singleton_v1> Instance(){
        std::lock_guard<std::mutex> lk(m_mutex);
        if(m_pInstance == nullptr){
            m_pInstance = std::shared_ptr<Singleton_v1>(new Singleton_v1());
        }
        return m_pInstance;
    }
private:
    Singleton_v1(){
        std::cout << "Singleton_v1: " << std::endl;
    }
    static std::shared_ptr<Singleton_v1> m_pInstance;
    static std::mutex m_mutex;
};

std::shared_ptr<Singleton_v1> Singleton_v1::m_pInstance = nullptr;
std::mutex Singleton_v1::m_mutex;


class Singleton_v2{
public:
    ~Singleton_v2(){
        std::cout << "~Singleton_v2: " << std::endl;
    }
    Singleton_v2(const Singleton_v2&)=delete;
    Singleton_v2& operator=(const Singleton_v2&)=delete;
    static Singleton_v2& Intance(){
        static Singleton_v2 m_pInstance;

        return m_pInstance;
    }
private:
    Singleton_v2(){
        std::cout << "Singleton_v2: " << std::endl;
    }
};

int main(int argc, char* argv[]){
    std::shared_ptr<Singleton_v1> p1 = Singleton_v1::Instance();
    std::shared_ptr<Singleton_v1> p2 = Singleton_v1::Instance();

    Singleton_v2& p3 = Singleton_v2::Intance();
    Singleton_v2& p4 = Singleton_v2::Intance();
    return 0;
}