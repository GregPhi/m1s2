#ifndef __STACK_TEMPLATE_HPP__
#define __STACK_TEMPLATE_HPP__

template<typename T>
class Stack {
    T *array_;
    int maxsize_ = 4;
    int top_ = 0;
public:
    Stack();
    Stack(Stack &other);
    ~Stack();
    void clear();
    int size() const { return top_; }
    int maxsize() const { return maxsize_; }
    T top() const;
    void pop();
    void push (const T &elem);
};

template<typename T>
Stack<T>::Stack()
{
    // allocate maxsize * sizeof(T) bytes of memory, returns a void*
    // which is then casted into a T*
    // *does not call* the constructor for T
    array_ = static_cast<T*>(operator new(maxsize_*sizeof(T)));
}

template<typename T>
Stack<T>::~Stack()
{
    clear();
    operator delete(array_);
}


template<typename T>
void Stack<T>::clear()
{
    while( size() > 0 ) pop();
}


template<typename T>
T Stack<T>::top() const
{
    if (top_ > 0) 
        return array_[top_ - 1];
    else throw 10;
}

template<typename T>
void Stack<T>::push(const T& elem)
{
    if (top_ < maxsize_) {
        // placement new: calls the construction without allocation
        new(&array_[top_]) T(elem); 
        top_++;
    }
    else throw 12;
}

template<typename T>
void Stack<T>::pop()
{
    if (top_ > 0) {
        top_--;
        // calls the destructor without deallocation
        (&array_[top_])->~T(); 
    }
}


#endif
