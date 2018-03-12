#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
    assert( -1 < 1U );
    assert( short(-1) < (unsigned short)(1) );
    return 0; 
}
