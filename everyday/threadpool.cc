#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <chrono>

class SafeQueue {
public:
    void push(int value) {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            q_.push(value);
        }
        cv_.notify_one();   // 唤醒消费者
    }

    int pop() {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [&]{ return !q_.empty(); }); // 条件变量等待
        int val = q_.front();
        q_.pop();
        return val;
    }

private:
    std::queue<int> q_;
    std::mutex mtx_;
    std::condition_variable cv_;
};


void producer(SafeQueue& sq, int id) {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        sq.push(i + id * 100);
        std::cout << "Producer " << id << " produced " << (i + id * 100) << std::endl;
    }
}

void consumer(SafeQueue& sq, int id) {
    for (int i = 0; i < 5; ++i) {
        int value = sq.pop();
        std::cout << "Consumer " << id << " consumed " << value << std::endl;
    }
}

int main() {
    SafeQueue sq;

    std::vector<std::thread> threads;

    // 创建生产者线程
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(producer, std::ref(sq), i);
    }

    // 创建消费者线程
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(consumer, std::ref(sq), i);
    }

    // 等待所有线程结束
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All threads finished.\n";

    return 0;
}
