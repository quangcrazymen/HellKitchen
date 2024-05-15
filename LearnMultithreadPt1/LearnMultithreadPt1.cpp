#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <mutex>

std::list<int> some_list;
std::mutex some_mutex;
void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    for (int i = 0; i < new_value; ++i) {
        some_list.push_back(i);
    }
    //std::lock_guard<std::mutex> guard(some_mutex);
}


//class thread_guard
//{
//    std::thread& t;
//public:
//    explicit thread_guard(std::thread& t_) :
//        t(t_)
//    {}
//    ~thread_guard()
//    {
//        if (t.joinable())
//        {
//            t.join();
//        }
//    }
//    thread_guard(thread_guard const&) = delete;
//    thread_guard& operator=(thread_guard const&) = delete;
//};
//
//void do_something(int& i)
//{
//    ++i;
//}
//
//struct func
//{
//    int& i;
//
//    func(int& i_) :i(i_) {}
//
//    void operator()(int b)
//    {
//        for (unsigned j = 0; j < 1000000; ++j)
//        {
//            do_something(i);
//        }
//    std::cout << i << std::endl;
//    }
//};
//
//void do_something_in_current_thread()
//{}
//
//void f()
//{
//    int some_local_state = 0;
//    func my_func(some_local_state);
//    std::thread t(my_func,3);
//    thread_guard g(t);
//
//    do_something_in_current_thread();
//}
static int someNumber = 12;
void hello()
{
    std::cout << "Hello Concurrent World\n";
    for (int i = 0; i < 20000000; ++i) {
		someNumber++;
    }
}
void do_work(int i) {
    std::cout << "Doing some works: "<<i<<std::endl;

}

static int totalSum = 0;
int finalElement = 1000;

void accumulatedSum1() {
    for (int i = 0; i < 50000; i++) {
        totalSum+=i;
    }
}

void accumulatedSum2() {
    for (int i = 50000; i <= 100000; i++) {
        totalSum+= i;
    }
}

void iterateThroughThreads()
{
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < 20; ++i)
    {
        threads.push_back(std::thread(do_work,i));
    }
    std::for_each(threads.begin(), threads.end(),
        std::mem_fn(&std::thread::join));
}

int main()
{
    //f();
    std::thread t(add_to_list,20);
    //t.join();
    t.detach();
    std::thread anotherThread(add_to_list,10);
    //anotherThread.join();
    anotherThread.join();
    for (auto i : some_list) {
        std::cout << i << ' ';
    }
    std::cout << "This is total sum" << totalSum << '\n';
    int singleThreadNormalSum = 0;
    for (int i = 0; i <= 100000; i++) {
        singleThreadNormalSum += i;
    }
    std::cout << "This is total sum" << singleThreadNormalSum << '\n';
    while (true);
    //iterateThroughThreads();


}