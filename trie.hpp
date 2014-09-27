// Simple trie data structure using STL. Based on code by Vivek Narayanan.
// - rlyeh, 2013 BOOST licensed ~~ listening to Baroness / March to the Sea.

#pragma once

#include <map>
#include <vector>

template<typename T>
class trie
{
    public:

    trie() : flag(false)
    {}

    bool has( const T &collection ) const {
        for( const auto &it : children )
            if( it.second.has(collection) )
                return true;
        return flag && collection == value ? true : false;
    }

    void insert( const T &collection ) {
        trie *node = this;
        for( auto &c : collection ) {
            auto found = node->children.find( c );
            if( found == node->children.end() )
                node->children[c] = trie( node->value + c );
            node = &(node->children[c]);
        }
        node->flag = true;
    }

    std::vector<const T *> list() const {
        std::vector<const T *> results;

        if( flag )
            results.push_back( &value );

        for( const auto &it : children ) {
            auto values = it.second.list();
            for( const auto &value : values )
                results.push_back( value );
        }

        return results;
    }

    std::vector<const T *> complete( const T &prefix ) const {
        const trie *node = this;

        for( auto &elem : prefix ) {
            const auto found = node->children.find( elem );
            if( found == node->children.end() )
                return std::vector<const T *>();
            else
                node = &found->second;
        }

        return node->list();
    }

    unsigned size() const {
        return list().size();
    }

    protected:

    trie( const T &_value ) : value(_value), flag(false)
    {}

    T value;
    bool flag;
    std::map< typename T::value_type, trie > children;
};

