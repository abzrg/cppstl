// std::string -> Accessors: s.c_str, s.data, operator[]

#include <algorithm> // std::equal()
#include <cassert> // assert()
#include <cstdio>
#include <cstring> // strlen()
#include <iostream>
#include <ostream>
#include <string>

extern "C" {
void c_func(const char* c_str)
{
    printf("c_func called with '%s'\n", c_str);
}
}

int main()
{
    std::string s = "Emplary";


    // -- operator[]

    std::cout << "s[1]: " << s[1] << std::endl;


    // -------------------------------------------------------------------------
    std::cout << std::endl;
    // -------------------------------------------------------------------------


    // --  .c_str() -> const char*
    // Use-case: when you need compatibility with a C library
    // meaning when a function expecting a null-terminated string.
    // This is important as std::string operations (iteration, concatenation,
    // element mutation, ...) don't need the null-terminator.

    const char* p = s.c_str();

    assert(s.size() == strlen(p));
    assert(std::equal(s.begin(), s.end(), p));
    assert(std::equal(p, p + s.size(), s.begin(), s.end()));
    assert('\0' == *(p + s.size()));

    c_func(s.c_str());


    // -------------------------------------------------------------------------
    std::cout << std::endl;
    // -------------------------------------------------------------------------


    // -- .data() -> (until C++17) const char* / (since C++17) char*
    // wasn't null terminated prior to C++11
    // null-terminated (from C++11) [data(), data() + size())
    // if .empty() = ture then: returns single null character.

    assert(s.size() == std::strlen(s.data()));
    assert(std::equal(s.begin(), s.end(), s.data()));
    assert(std::equal(s.data(), s.data() + s.size(), s.begin()));
    assert(0 == *(s.data() + s.size()));

    // src: https://stackoverflow.com/a/38456243/13041067
    // g++ -x c++ -std=c++17 -dM -E - </dev/null | grep __cplusplus
    static_assert(__cplusplus >= 201703L,
                  "Following expects a C++17 compiler.");

    std::cout << "s: " << s << std::endl;
    char* ptr = s.data();
    ptr[1] = 'x';
    std::cout << "s.data()[1] = x -> s:  " << s << std::endl;


    // NOTE:
    //
    // strings (std::basic_string) don't necessarily have to be composed of
    // character data, they could be composed with elements of any type. In
    // those cases data() is more meaningful. c_str() in my opinion is only
    // really useful when the elements of your string are character based.
    //
    // src: https://stackoverflow.com/a/194638/13041067
}
