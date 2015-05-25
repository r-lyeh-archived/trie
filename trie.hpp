// Simple trie data structure using STL. Based on code by Vivek Narayanan.
// - rlyeh, 2013-2015 zlib/libpng licensed ~~ listening to Baroness / March to the Sea.

#pragma once
#include <map>
#include <vector>
#include <algorithm>

#define   TRIE_VERSION "1.0.1" // additional tree implementation
//#define TRIE_VERSION "1.0.0" // initial commit

template<typename K, typename V = int>
class trie
{
    public:

    trie() : flag(false)
    {}

    bool has( const K &collection ) const {
        for( const auto &it : children ) {
            if( it.second.has(collection) ) {
                return true;
            }
        }
        return flag && collection == branch ? true : false;
    }

    V& insert( const K &collection ) {
        trie *node = this;
        for( auto &c : collection ) {
            auto found = node->children.find( c );
            if( found == node->children.end() ) {
                auto copy = node->branch;
                std::back_inserter( copy ) = c;
                node->children[c] = trie( copy );
            }
            node = &(node->children[c]);
        }
        node->flag = true;
        return node->leaf;
    }

    V& operator[]( const K &collection ) {
        return insert( collection );
    }

    std::vector<const K *> list() const {
        std::vector<const K *> results;
        if( flag ) {
            results.push_back( &branch );
        }
        for( const auto &it : children ) {
            auto keys = it.second.list();
            for( const auto &key : keys ) {
                results.push_back( key );
            }
        }
        return results;
    }

    std::vector<const K *> complete( const K &prefix ) const {
        const trie *node = this;
        for( auto &elem : prefix ) {
            const auto found = node->children.find( elem );
            if( found == node->children.end() ) {
                return std::vector<const K *>();
            }
            node = &found->second;
        }
        return node->list();
    }

    unsigned size() const {
        return list().size();
    }

    protected:

    trie( const K &branch ) : branch(branch), flag(false)
    {}

    K branch;
    V leaf;
    bool flag;
    std::map< typename K::value_type, trie > children;
};

