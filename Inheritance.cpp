// Example program
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define FLERR __FILE__,__LINE__


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

class GodFather {
    public:
       GodFather(Parent *& _parent, derived *& _drvd, float *& _flt):  vito(1), sonny(0), fredo(2), parent(_parent), drvd(_drvd), flt(_flt) {
           cout << "GodFather constructor" << endl;
       }
       GodFather(const GodFather & _godfather): vito(_godfather.vito), sonny(_godfather.sonny), fredo(_godfather.fredo), 
                                                 parent(_godfather.parent), drvd(_godfather.drvd), flt(_godfather.flt) {}
    private:
       int vito;
       int sonny;
       int fredo;
       Parent *& parent;
       derived *& drvd;
       float *& flt;
};
    
int testFunc1(Parent* parent2)
{
    Parent* parent3 = parent2;
    cout << parent3 << endl;
    cout << parent2 << endl;
    return 0;
}

int testFunc2(Parent*& parent2)
{
    Parent* parent4 = parent2;
    cout << parent2 << endl;
    cout << parent4 << endl;
    delete [] parent4;
    return 0;
}

int main()
{
  cout << "line 59" << endl;
  Parent testc[2];
  cout << "line 61" << endl;
  testFunc1(testc);
  cout << "line 63" << endl;
  Parent* testc2 = new Parent[2];
  cout << "line 65" << endl;
  testFunc2(testc2);
  cout << "line 67" << endl;
  derived* drv = new derived [2];
  float flt = 0.2;
  GodFather godfather(testc2,drv,flt);
  cout << "line 69" << endl;
}
