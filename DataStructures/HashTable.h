//
// Created by Dima on 23.03.2017.
//

#ifndef ALGORITHM_HASHTABLE_H
#define ALGORITHM_HASHTABLE_H

#include <vector>


template <typename Key>
struct Hasher {};

template <>
struct Hasher<std::string> {
    size_t operator()(const std::string& string, size_t m) const {
        size_t hash = 0;
        for (auto& i : string)
            hash = (hash * 7 + i) % m;
        return hash;
    }
};

template <>
struct Hasher<int> {
    size_t operator()(int id, size_t m) const {
        return id % m;
    }
};


// TODO add iterators, make unordered_map
template <typename Key, class HasherFn = Hasher<Key> >
class HashTable {
private:
    struct Node {
        Key data;
        bool empty;

        Node() : empty(true) {}

        void set(const Key& key) {
            this->data = key;
            this->empty = false;
        }
    };

    std::vector<Node> table;
    size_t currentSize;
    const float rate = 3.0f/4.0f;
    HasherFn hasher;

    void resize() {
        std::vector<Node> tmp = table;
        table.resize(2*table.size());
        for (auto& i : table)
            i.empty = true;

        for (auto& i : tmp) // ???
            if (i.empty == false)
                insert(i.data);
    }

public:
    HashTable() : table(8), currentSize(0) {}

    bool insert(const Key& key) {
        size_t hash = hasher(key, table.size());
        for (int i = 0; i < table.size(); i++) {

            if (table[hash].empty) {
                table[hash].set(key);
                break;
            }

            if (table[hash].data == key)
                return false;

            hash = (hash + i + 1) % table.size();
        }

        currentSize++;
        float a = ((float) currentSize) / table.size();
        if (a >= rate)
            resize();
        return true;
    }

    bool find(const Key& key) const {
        size_t hash = hasher(key, table.size());
        for (unsigned i = 0; i < table.size(); i++) {
            if (table[hash].empty == false && table[hash].data == key)
                return true;
            hash = (hash + i + 1) % table.size();
        }
        return false;
    }

    bool remove(const Key& key) {
        size_t hash = hasher(key, table.size());
        for (unsigned i = 0; i < table.size(); i++) {
            if (table[hash].empty == false && table[hash].data == key) {
                table[hash].empty = true;
                currentSize--;
                return true;
            }
            hash = (hash + i + 1) % table.size();
        }
        return false;
    }
};


#endif //ALGORITHM_HASHTABLE_H
