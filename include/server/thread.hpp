#ifndef __TY_THREAD_H__
#define __TY_THREAD_H__

#include "cannotCopy.hpp"

#include <functional>

using namespace std;

namespace ty
{

using ThreadCallback = function<void()>;

namespace current_thread
{
extern __thread int __thread_number;
} // end of current_thread

class Thread
: CannotCopy {
public:
    Thread(ThreadCallback&&, int);
    ~Thread();

    void start(); // 启动线程
    void join();  // 回收线程
    // 在类内部实现的函数都是inline函数
    bool isRunning() const { return _is_running; }

    static void* threadFnc(void* arg);

private:
    pthread_t _pth_id;
    bool _is_running;
    ThreadCallback _cb;
    int _thread_number;
};
} // end of namespace ty
#endif