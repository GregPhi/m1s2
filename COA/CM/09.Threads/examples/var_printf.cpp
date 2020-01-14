#include "var_printf.hpp"

std::unique_lock<std::mutex> lock_printf()
{
    static std::mutex m;
    return std::unique_lock<std::mutex>(m);
}

void safe_fprintf(std::ostream &out, const char *s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw "invalid format string: missing arguments";
            }
        }
        out << *s++;
    }
}
