// std::string -> But what is string?


#include <iostream>
#include <string>


int main()
{
    // - String literal in C++ are const char[].
    // - They are copied to other arrays but non-const pointer cannot point to
    //   them

    char firstname[6] = "Bjarn"; // name is mutable
    const char* lastname = "Stroustrup"; // immutable

    // ISO C++11 does not allow conversion from string literal to 'char *'
    // char *lastname = "Stroustrup";


    // C++ strings!
    std::string s = "Hello"; // s = [ 'H', 'e', 'l', 'l', 'o', '\0' ]

    // std::string is just a special case of std::basic_string
    //
    // std::string == std::basic_string<char>
    // std::wstring == std::basic_string<wchar_t>
    // std::u8string == std::basic_string<char8_t>           C++20
    // std::u16string == std::basic_string<char16_t>         C++11
    // std::u32string == std::basic_string<char32_t>         C++11

    std::cout << "firstname: " << firstname << std::endl;
    std::cout << "lastname: " << lastname << std::endl;
    std::cout << "s: " << s << std::endl;
}
