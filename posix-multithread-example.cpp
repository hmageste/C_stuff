#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

// compile with g++ <file_name> -lpthread

#define NUM_THREADS     10

void *PrintHello(void *threadid) {
   int tid;
   tid = static_cast<int> (threadid);
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;

   for (int i=0; i < NUM_THREADS; i++) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create( &threads[i], NULL, PrintHello, (void *)i );

      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }

   pthread_exit(NULL);
}
