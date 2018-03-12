#include <iostream>

int* getNull ()
{
    return nullptr;
}

int* getInt ()
{
    int *a = new int(1);
    return a;
}

int main ()
{
    int a = 1, b =2;
    int *a_ptr, *b_ptr;

    if ( a_ptr = &a )
    {
        std::cout << "assignment 1 executed" << std::endl;
    }

    if ( !(b_ptr = getNull()) )
    {
        std::cout << "assignment 2 executed" << std::endl;
    }

    if ( b_ptr = getInt() )
    {
        std::cout << "assignment 3 executed" << std::endl;
    }

    return 0;
}
