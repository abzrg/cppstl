// strings -> Operations: erase(), .clear()

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

int main()
{
    // -- (1) .erase(indx, count=npos) -> *this
    // -- (2) .erase(it first) -> .end()/last
    // -- (3) .erase(it first, [it last]) -> .end()/last
    //
    // NOTE: npos (static std::string::npos = -1) is used to denote the end of a
    // string

    std::string s_er = "This Is An Example";
    std::cout << "1) " << s_er << '\n';

    // erases " An"; overload (1)
    s_er.erase(7, 3);
    std::cout << "2) " << s_er << '\n';

    // erases first ' '; overload (2)
    s_er.erase(std::find(s_er.begin(), s_er.end(), ' '));
    std::cout << "3) " << s_er << '\n';

    // trims from ' ' to the end of the string; overload (3)
    s_er.erase(s_er.find(' '));
    std::cout << "4) " << s_er << '\n';

    // obtains iterator to the first 's'
    auto it = std::next(s_er.begin(), s_er.find('s'));
    // erases "sI"; overload (3)
    s_er.erase(it, std::next(it, 2));
    std::cout << "5) " << s_er << '\n';


    // -------------------------------------------------------------------------
    std::cout << std::endl;
    // -------------------------------------------------------------------------


    // -- .clear() -> None
    // Removes all characters
    // Equiv: erase(begin(), end())
    // All pointers, references, and iterators are invalidated.
    // Capacity is unchanged.

    std::string s_clr{ "Emplary" };
    std::string::size_type const capacity = s_clr.capacity();

    std::cout << "1) " << s_clr << std::endl; // prints: Emplary
    s_clr.clear();
    std::cout << "2) " << s_clr << std::endl; // prints:

    assert(s_clr.capacity() == capacity); // <- not guaranteed
    assert(s_clr.empty());
    assert(s_clr.size() == 0);
}
