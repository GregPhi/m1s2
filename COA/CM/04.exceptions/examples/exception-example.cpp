#include <iostream>
#include <exception>
#include <cmath>
#include <sstream>

using namespace std;

class MathErr : public exception {
    string str;
public:
    MathErr(const string &err) : exception(), str(err) {}
    string what() { return str; }
    ~MathErr() throw() {}
};

class LogErr : public MathErr {
    
public:
    LogErr() : MathErr("LogErr exception") {}
};

class DivByZero : public MathErr {
public:
    DivByZero() : MathErr("Division by zero") {}
};

double mylog(int a) throw()
{
    if (a <= 0) throw LogErr();
    else return log(double(a));
}

void f(int i)
{
    mylog(i);
}

int main()
{
    try {
        f(-5);
    } catch(MathErr &e) {
        cout << e.what() << endl;
    }
}
