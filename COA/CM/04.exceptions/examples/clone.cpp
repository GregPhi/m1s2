class Base {
public:
    Base() {}
    Base(const Base &other) ;
    
    virtual Base *clone() {
        return new Base(*this);
    }
};

class Derived : public Base {
public:
    Derived() : Base() {}
    Derived(const Derived &other);
    
    virtual Derived *clone() {
        return new Derived(*this);
    }
};

int main()
{
    Base *p = create("MyObject");
    
    Base *q = p->clone();
}