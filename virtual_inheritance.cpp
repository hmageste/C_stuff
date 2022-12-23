#include <exception>
#include <iostream>

// If the virtual keyword is inserted in front of the my_exc* inheritance, the example will work as expected
// since this will prevent ambiguity issues with the exception handler, which will then lead to the default catch block
// being executed
struct my_exc1 : std::exception { const char* what() const throw() {return "my_exc1";}; };
struct my_exc2 : std::exception { const char* what() const throw() {return "my_exc2";}; };
struct problematic_exception : my_exc1, my_exc2 { const char* what() const throw() {return "problematic_exception";}; };

int main ()
{
    try {
        throw problematic_exception();
    } catch (const std::exception& ex) {
        std::cout << "Worked as expected!" << std::endl;
    }
    catch(...) {
        // without the virtual keyword, conversion to std::exception
        // is ambiguous
        std::cout << "Not expected!" << std::endl;
    }

    return 0;
}
