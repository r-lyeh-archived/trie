#include <iostream>
#include <string>
#include <cassert>

#include "trie.hpp"

int main()
{
    trie<std::string> t;

    t.insert("wargame");
    t.insert("wombat");
    t.insert("wolfram");
    t.insert("world");
    t.insert("work");

    assert( t.size() == 5 );
    assert( t.has("war") == false );
    assert( t.has("wargame") == true );

    auto candidates = t.complete("wo");
    assert( candidates.size() == 4 );

    candidates = t.complete("warg");
    assert( candidates.size() == 1 );
    assert( *candidates[0] == "wargame" );

    std::cout << "All ok." << std::endl;
    return 0;
}
