// Example program
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Parent {
    public:
        Parent()
        {cout << "empty constructor" << endl;}
        Parent(int arg_a,int arg_b):
        a(arg_a), b(arg_b)
        {cout << "constructor" << endl;}
        Parent(const Parent &parent):
        a(parent.a), b(parent.b)
        {cout << "copy constructor" << endl;}
        ~Parent()
        {cout << "destructor" << endl;}
    private:
        int a;
        int b;
    };
    
class derived: protected Parent {
    public:
        derived()
        {
            cout << "derived constructor" << endl;
        }
        ~derived()
       {
           cout << "derived class destructor" << endl;
       }
    private:
        int c;
    };
    
int testFunc1(Parent* parent)
{
    Parent* testc3 = testc2;
    cout << testc2 << endl;
    cout << testc3 << endl;
    return 0;
}

int testFunc2(Parent*& testc2)
{
    Parent* testc4 = testc2;
    cout << testc2 << endl;
    cout << testc4 << endl;
    delete [] testc4;
    return 0;
}

int main()
{
  Parent testc[2];
  testFunc1(testc);
  Parent* testc2 = new Parent[2];
  cout << "line1" << endl;
  testFunc2(testc2);
  cout << "linen" << endl;
  derived drv[2];
}
