#ifndef __VAR_PRINTF__
#define __VAR_PRINTF__

#include <iostream>
#include <mutex>

void safe_fprintf(std::ostream &out, const char *s);

template<typename T, typename... Args>
void safe_fprintf(std::ostream &out, const char *s, T& value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                out << value;
                safe_fprintf(out, s + 1, args...); 
		// call even when *s == 0 to detect extra arguments
                return;
            }
        }
        out << *s++;
    }
    throw "extra arguments provided to printf";
}

template<typename... Args>
void safe_printf(const char *s, Args... args)
{
    safe_fprintf(std::cout, s, args...);
}

std::unique_lock<std::mutex> lock_printf();

template<typename... Args>
void unique_printf(const char *s, Args... args)
{
    auto lck = lock_printf();
    safe_fprintf(std::cout, s, args...);
}

#endif
