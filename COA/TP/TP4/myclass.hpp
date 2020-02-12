class MyClass {
    int x;
 public:
    MyClass(int d) : x(d) {}
    MyClass() : x(0) {}

    MyClass(const MyClass &other) :  x(other.x) {}

    bool operator==(const MyClass &other) { return x == other.x; }
    MyClass &operator=(const MyClass &other) { x = other.x; return *this; }

    int get() { return x; }
};

