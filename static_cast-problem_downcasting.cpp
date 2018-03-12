#include <iostream>

using namespace std;

class CBase { virtual void dummy() {} };
class CDerived1: public CBase 
{ 
    int a; 
public :
    void hello() { cout << "hello" << endl; }
};

class CDerived2: public CBase 
{ 
    int a; 
public :
    virtual void hello() { cout << "hello" << endl; }
};

int main () 
{
    try {
        CBase * pbb = new CBase;
        CDerived1 * pd1;
        CDerived2 * pd2;

        pd1 = static_cast<CDerived1*>(pbb);
        pd2 = static_cast<CDerived2*>(pbb);
        if (pd1==0) cout << "Null pointer on second type-cast" << endl;
        if (pd2==0) cout << "Null pointer on second type-cast" << endl;
        (*pd1).hello();
        (*pd2).hello();
    } catch (exception& e) {cout << "Exception: " << e.what();}

    return 0;

}