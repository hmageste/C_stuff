#include <iostream>
#include <thread>

// compile: g++ <file_name> -std=c++11 -pthread

void threadFunc()
{
    std::cout << "Hello World" << std::endl;
}

int main()
{
    std::thread t (threadFunc);

    // this line is needed to make the main
    // thread wait for this child thread
    t.join();

    return 0;
}
