/**
 * xiebaoma
 * 2025-09-28
 */

#include <iostream>
#include <thread>
#include <mutex>

class Singleton {
public:
    static Singleton& getInstance() {
        std::call_once(initFlag, [](){
            instance = new Singleton();
        });
        return *instance;
    }

private:
    Singleton() { std::cout << "构造函数执行\n"; }
    ~Singleton() { }

    static Singleton* instance;
    static std::once_flag initFlag;
};

Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::initFlag;

void worker() {
    Singleton& s = Singleton::getInstance();
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);
    std::thread t3(worker);

    t1.join();
    t2.join();
    t3.join();
}
