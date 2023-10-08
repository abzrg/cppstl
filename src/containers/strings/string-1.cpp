// std::string -> .empty(), .capacity(), .size()/.length(), .shrink_to_fit()

#include <cassert>
#include <iostream>
#include <string>
#include <ios> // boolalpha

int main()
{
    // -- .empty()

    std::string s;
    std::boolalpha(std::cout);
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";

    s = "Exemplar";
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";

    s = "";
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";


    // -------------------------------------------------------------------------
    std::cout << std::endl;
    // -------------------------------------------------------------------------


    // -- .capacity(), .size()/.length()

    std::string name = "Pele";
    std::cout << "name: " << name << std::endl;

    // Capacity: number of characters that can be held in currently allocated
    // storage
    std::cout << "capacity: " << name.capacity() << std::endl;

    // Size/Length: number of characters
    std::cout << "size: " << name.size() << std::endl;
    std::cout << "length: " << name.length() << std::endl;


    // -------------------------------------------------------------------------
    std::cout << std::endl;
    // -------------------------------------------------------------------------


    // -- .shrink_to_fit()

    name += "/Edson Arantes do Nascimento";
    name += " (his friends: Diego Armando Maradona,";
    name += " Cristiano Ronaldo dos Santos Aveiro,";
    name += " Lionel Andrés Messi)";

    std::cout << "name: " << name << std::endl;
    std::cout << "size before shrink " << name.size() << std::endl;
    std::cout << "capacity before shrink " << name.capacity() << std::endl;

    // Does not shrink if string is small
    name.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit: " << name.capacity()
              << std::endl;
}
