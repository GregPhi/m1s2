#include <iostream>

using namespace std;

class ArrayWrapper
{
public:
    // default constructor produces a moderately sized array
    ArrayWrapper ()
        : _p_vals( new int[ 64 ] )
        , _size( 64 )
    {
	cout << "Default constructor" << endl;
    }
 
    ArrayWrapper (int n)
        : _p_vals( new int[ n ] )
        , _size( n )
    {
	cout << "Constructor with " << n << endl;
    }
 
    // move constructor
    ArrayWrapper (ArrayWrapper&& other)
        : _p_vals( other._p_vals  )
        , _size( other._size )
    {
	cerr << "Move constructor" << endl;
        other._p_vals = NULL;
    }

    // copy constructor
    ArrayWrapper (const ArrayWrapper& other)
        : _p_vals( new int[ other._size  ] )
        , _size( other._size )
    {
	cout << "Copy constructor" << endl;
        for ( int i = 0; i < _size; ++i )
        {
            _p_vals[ i ] = other._p_vals[ i ];
        }
    }

    ~ArrayWrapper ()
    {
	cout << "Destructor with _p_vals = " << _p_vals << endl;
        delete [] _p_vals;
    }
 

    int getSize() const { return _size; }
private:
    int *_p_vals;
    int _size;
};

ArrayWrapper myArrayCreation() 
{
    ArrayWrapper temp(10); 
    
    cout << "temp.getSize() " << temp.getSize() << endl;

    return temp;
}


int main()
{
    ArrayWrapper a;
    ArrayWrapper b = myArrayCreation(); 

    cout << "a.size() = " << a.getSize() << endl;
    cout << "b.size() = " << b.getSize() << endl;
}
