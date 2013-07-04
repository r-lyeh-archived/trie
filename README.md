Trie
====

- Trie is a lightweight and simple autocompletion data structure written in C++11.
- Easy to integrate. One header and one source file.
- Cross-platform. No extra dependencies.
- MIT licensed.

API
---
- `.insert(element)`
- `.has(element)` returns `true` if `element` is in trie.
- `.complete(element)` autocompletes partially provided `element` then returns vector of candidate pointers.
- `.list()` returns a vector of hosted pointers in trie.
- `.size()` returns number of elements in trie.

Sample
------
```c++
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
```

Possible output
---------------
```
~/trie>g++ sample.cc trie.cpp -std=c++11
All ok.
~/trie>
```
