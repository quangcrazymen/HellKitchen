// TestCppFeatures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <thread>
//std::list<int> some_list;
//std::mutex some_mutex;
//void add_to_list(int new_value)
//{
//    std::lock_guard<std::mutex> guard(some_mutex);
//    some_list.push_back(new_value);
//
//}
//
//bool list_contains(int value_to_find)
//{
//    //std::lock_guard<std::mutex> guard(some_mutex);
//    int s=0;
//    for (int i = 0; i < 100000000; ++i) {
//        s += i;
//    }
//    return std::find(some_list.begin(), some_list.end(), value_to_find)
//        != some_list.end();
//}
//// Define a comparison function that compares pairs based on their second element
//bool CompareSecond(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
//    return p1.second > p2.second; // '>' for ascending order
//}
//#include <exception>
//#include <memory>
//
//struct empty_stack : std::exception
//{
//    const char* what() const throw();
//};
//
//template<typename T>
//class threadsafe_stack
//{
//public:
//    threadsafe_stack();
//    threadsafe_stack(const threadsafe_stack&);
//    threadsafe_stack& operator=(const threadsafe_stack&) = delete;
//
//    void push(T new_value);
//    std::shared_ptr<T> pop();
//    void pop(T& value);
//    bool empty() const;
//};

struct T_MyStruct
{
    char val1;
    char val4;
    char val9;
    short val2;
    short val3;
    char va5;
    char val6;
    double val7;
};

void* operator new(size_t size) {
    return malloc(size* sizeof(char));
}

void operator delete (void* mem)
{
    free(mem);
}

void* operator new[](size_t size)
{
    return malloc(size* sizeof(char));
}

void operator delete[](void* mem)
{
    free(mem);
}
void do_work() {
    std::cout << "Doing some works\n";

}

void iterateThroughThreads()
{
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < 20; ++i)
    {
        threads.push_back(std::thread(do_work));
    }
    std::for_each(threads.begin(), threads.end(),
        std::mem_fn(&std::thread::join));
}
int main() {
    int* newBlock = new int((size_t)2200);
    int* anotherBlock = new int[1215];
    //*(newBlock + 1) = 12;
    //*(newBlock + 2) = 24;
    //*(newBlock + 3) = 14;
    //*(newBlock + 4) = 120;
    //*(newBlock + 5) = 450;
    for (int i = 0; i < 1304;++i) {
        *(anotherBlock + i) = 145;
    }
    size_t someNum = 1200;
    int a;
    char* pInstanceMem = new char[sizeof(int) + 0x0F];

    return 0;
}

//#include <iostream>
//#include <queue>
//#include <vector>
//
//// Define a custom comparator that compares pairs based on their second element
//struct CompareSecond {
//    bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2) const {
//        return p1.second > p2.second; // '>' for ascending order
//    }
//};
//
//int main() {
//    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompareSecond> pq;
//
//    // Insert pairs into the priority queue
//    pq.push({ 1, 5 });
//    pq.push({ 2, 3 });
//    pq.push({ 3, 8 });
//    pq.push({ 4, 1 });
//
//    // Retrieve pairs in ascending order based on the second value
//    while (!pq.empty()) {
//        std::pair<int, int> topPair = pq.top();
//        std::cout << "(" << topPair.first << ", " << topPair.second << ") ";
//        pq.pop();
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//std::mutex mtx;
//std::condition_variable cv;
//bool dataReady = false;
//int realValue = 0;
//
//void loadingThread() {
//    // Simulate loading the real value
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//
//    // Set the real value
//    {
//        std::lock_guard<std::mutex> lock(mtx);
//        realValue = 42;
//        dataReady = true;
//    }
//    
//    // Notify that data is ready
//    cv.notify_one();
//}
//
//int main() {
//    // Start the loading thread
//    std::thread loader(loadingThread);
//
//    // Placeholder value
//    int placeholderValue = 0;
//
//    // Wait for the data to be ready
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//        cv.wait(lock, [] { return dataReady; });
//        placeholderValue = realValue;
//    }
//
//    // Continue with the placeholder value
//    std::cout << "Placeholder Value: " << placeholderValue << std::endl;
//
//    // Wait for the loading thread to finish
//    loader.join();
//
//    // Use the real value
//    std::cout << "Real Value: " << realValue << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <thread>
//#include <string>
//#include <mutex>
//
//std::mutex mtx; // Mutex for synchronization
//
//// Function to read and process a file
//void readFile(const std::string& filename) {
//    std::ifstream file(filename);
//    if (!file.is_open()) {
//        std::cerr << "Error: Failed to open file " << filename << std::endl;
//        return;
//    }
//
//    std::string line;
//    while (std::getline(file, line)) {
//        // Process each line of the file here
//        // For this example, we'll just print the lines
//        std::lock_guard<std::mutex> lock(mtx); // Lock to protect shared output
//        std::cout << line << std::endl;
//    }
//
//    file.close();
//}
//
//int main() {
//    const std::string filename = "data.txt";
//
//    // Create a thread to read the file
//    std::thread fileThread(readFile, filename);
//
//    // Continue with work in the main thread
//    for (int i = 0; i < 5; ++i) {
//        std::lock_guard<std::mutex> lock(mtx); // Lock to protect shared output
//        std::cout << "Main thread working..." << std::endl;
//    }
//
//    // Wait for the file thread to finish
//    fileThread.join();
//
//    return 0;
//}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
