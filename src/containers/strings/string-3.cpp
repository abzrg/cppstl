// std::string -> Iterate and iterators

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>


int main()
{
    std::string const s{ "Emplary" };


    // -- Looping over elements

    for (auto element: s) {
        std::cout << element << std::endl;
    }


    // -------------------------------------------------------------------------
    std::cout << std::endl;
    // -------------------------------------------------------------------------


    // -- .cbegin()/.cend(): const iterator

    for (auto it = s.cbegin(), end = s.cend(); it != end; ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;


    // -------------------------------------------------------------------------
    std::cout << std::endl;
    // -------------------------------------------------------------------------


    // -- .begin()/.end(): non-const iterator

    std::string exm("Exemplar");
    *exm.begin() = 'e';
    *(exm.end() - 1) = 'R';
    std::cout << exm << '\n';

    auto it = exm.cbegin();
    std::cout << *it << '\n';
    //  *it = 'E'; // error: i is a constant iterator


    // -------------------------------------------------------------------------
    std::cout << std::endl;
    // -------------------------------------------------------------------------


    std::string perm("Exemparl");
    // calculates the next lexiographic permutation
    std::next_permutation(perm.begin(), perm.end());

    std::string c;
    // `back_inserter` calls the push_back for a variable of a type that
    // supports it
    std::copy(perm.cbegin(), perm.cend(), std::back_inserter(c));
    std::cout << c << '\n'; // "Exemplar"
}
