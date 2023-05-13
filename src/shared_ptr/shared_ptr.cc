#include <iostream>

template<class T>
class my_shared_ptr{
public:
    //默认构造函数 
    my_shared_ptr():ptr(new T),count(new int(0)){}

    //有参构造函数
    my_shared_ptr(T* p):ptr(p),count(new int(0)){
        if(p){
            *count = 1;
        }else{
            *count = 0;
        }
    }

    //拷贝构造函数（浅拷贝）
    my_shared_ptr(const my_shared_ptr& p){
        ptr = p.ptr;
        count = p.count;
        ++(*count);
    }

    // 赋值函数重载
    my_shared_ptr& operator=(const my_shared_ptr& p){
        if(this == &p){
            return *this;
        }
        this->~my_shared_ptr();

        ptr = p.ptr;
        count = p.count;
        ++(*count);
    }

    // 析构函数
    ~my_shared_ptr(){
        if(--(*count) == 0){
            delete ptr;
            ptr =nullptr;
            delete count;
            count = nullptr;
        }
    }

    // 获取对象计数值
    int use_count(){
        return *count;
    }

private:
    T* ptr;
    int* count;
};

int main(int argc, char* argv[]){
    my_shared_ptr<int> p1(new int(1));
    std::cout << "p1 count: " << p1.use_count() << std::endl;

    my_shared_ptr<int> p2;
    std::cout << "p2 count: " << p2.use_count() << std::endl;
    p2 = p1;
    std::cout << "p2 count: " << p2.use_count() << std::endl;

    my_shared_ptr<int> p3(p2);
    std::cout << "p1 count: " << p1.use_count() << std::endl;
    std::cout << "p3 count: " << p3.use_count() << std::endl;

    p1.~my_shared_ptr();
    std::cout << "p1 count: " << p1.use_count() << std::endl;
    std::cout << "p3 count: " << p3.use_count() << std::endl;

    return 0;
}