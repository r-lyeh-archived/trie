#include "trie.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

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

    {
    trie<std::string, int> count;
    count["/dir1/file1"] = 10;
    count["/dir1/file3"] = 30;
    count["/dir1/file2"] = 20;
    count["/dir2/"];
    assert( count.size() == 4 );
    assert( count["/dir1/file3"] == 30 );
    assert( count.complete("/dir1/").size() == 3 );
    }

    {
    using path = std::vector<std::string>;
    path d1d1 = path{"dir1", "dir1"};
    path d1d2 = path{"dir1", "dir2"};
    path d1d3 = path{"dir1", "dir3"};
    path d1   = path{"dir1"};
    path d2   = path{"dir2"};
    trie< path, std::string > files;
    files[ d1d1 ] = "10";
    files[ d1d3 ] = "30";
    files[ d1d2 ] = "20";
    files[ d2 ];
    assert( files.size() == 4 );
    assert( files[ d1d3 ] == "30" );
    assert( files.complete( d1 ).size() == 3 );
    }

    std::cout << "All ok." << std::endl;
}
