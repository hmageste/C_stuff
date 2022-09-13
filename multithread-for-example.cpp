#include <iostream>
#include <thread>

static const int num_of_threads = 10;

void thread_method (int thread_id) {
   std::cout << "Function running in thread " << thread_id << std::endl;
}

int main () {
    std::thread threads[num_of_threads];
    for (int i = 0; i < num_of_threads; i++)
        threads[i] = std::thread(thread_method, i);

    std::cout << "The main function execution\n";

    for (int i = 0; i < num_of_threads; i++)
        threads[i].join();

    return 0;
}
