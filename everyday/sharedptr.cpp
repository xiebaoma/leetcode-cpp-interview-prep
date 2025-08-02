#include <iostream>

template <typename T>
class SharedPtr
{
private:
    T *ptr;         // 原始指针
    int *ref_count; // 引用计数指针

    void release()
    {
        if (ref_count)
        {
            (*ref_count)--;
            if (*ref_count == 0)
            {
                delete ptr;
                delete ref_count;
                std::cout << "[SharedPtr] Resource deleted\n";
            }
        }
    }

public:
    // 默认构造
    SharedPtr() : ptr(nullptr), ref_count(nullptr) {}

    // 构造函数
    explicit SharedPtr(T *p) : ptr(p), ref_count(new int(1)) {}

    // 拷贝构造
    SharedPtr(const SharedPtr<T> &other)
    {
        ptr = other.ptr;
        ref_count = other.ref_count;
        if (ref_count)
        {
            (*ref_count)++;
        }
    }

    // 赋值运算符
    SharedPtr &operator=(const SharedPtr<T> &other)
    {
        if (this != &other)
        {
            release(); // 先释放当前资源
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count)
            {
                (*ref_count)++;
            }
        }
        return *this;
    }

    // 析构函数
    ~SharedPtr()
    {
        release();
    }

    // 获取原始指针
    T *get() const
    {
        return ptr;
    }

    // 获取引用计数
    int use_count() const
    {
        return ref_count ? *ref_count : 0;
    }

    // 重载 * 和 ->
    T &operator*() const
    {
        return *ptr;
    }

    T *operator->() const
    {
        return ptr;
    }
};
