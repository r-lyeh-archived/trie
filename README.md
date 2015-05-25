Trie <a href="https://travis-ci.org/r-lyeh/trie"><img src="https://api.travis-ci.org/r-lyeh/trie.svg?branch=master" align="right" /></a>
====

- Trie is a lightweight and simple autocompletion data structure written in C++11.
- Trie is tiny, cross-platform and header-only.
- Trie is zlib/libpng licensed.

## API
- construct `trie<K>` or `trie<K,V>` as desired.
- `.insert(element)` or `[element]` to create/access elements.
- `.has(element)` returns `true` if `element` is in trie.
- `.complete(element)` autocompletes partially provided `element` then returns vector of candidate pointers.
- `.list()` returns a vector of hosted pointers in trie.
- `.size()` returns number of elements in trie.

## Sample
```c++
#include "trie.hpp"

#include <iostream>
#include <string>
#include <cassert>

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
}
```

## Possible output
```
~/trie>g++ sample.cc trie.cpp -std=c++11
All ok.
~/trie>
```

## Changelog
- v1.0.1 (2015/05/25)
  - Additional tree implementation.
- v1.0.0 (2013/07/18)
  - Initial commit
