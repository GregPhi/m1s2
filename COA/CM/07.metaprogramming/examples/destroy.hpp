template<class T>
void destroy_at(T* p) 
{ 
    p->~T(); 
}

template<class ForwardIt>
void destroy(ForwardIt first, ForwardIt last )
{
  for (; first != last; ++first)
    destroy_at(std::addressof(*first));
}


template<class T1, class T2>
void construct(T1* p, const T2& value)
{
    new (p) T1(value);
}

