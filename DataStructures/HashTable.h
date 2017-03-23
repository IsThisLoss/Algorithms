//
// Created by Dima on 23.03.2017.
//

#ifndef ALGORITHM_HASHTABLE_H
#define ALGORITHM_HASHTABLE_H

#include <vector>
#include <cstdlib>
#include <stdexcept>

// TODO add external hash() support, add iterators, make unordered_map
template <typename Key_type>
class HashTable
{
private:
    struct Node
    {
        enum State {empty, deleted, busy};
        Key_type data;
        State state;

        Node() : state(empty) {}

        void set(const Key_type& string)
        {
            this->data = string;
            this->state = busy;
        }

        inline bool isInsertable() const
        {
            return state == empty || state == deleted;
        }
    };

    std::vector<Node> table;
    size_t currentSize;
    const float rate = 3.0f/4.0f;
public:
    HashTable()
    {
        table.resize(8);
        currentSize = 0;
    }

    void resize()
    {
        std::vector<Node> tmp = table;
        table.resize(2*table.size());
        for (auto& i : table)
            i.state = Node::empty;

        for (auto& i : tmp)
            if (i.state == Node::busy)
                insert(i.data);
    }

    void insert(const Key_type& string)
    {
        size_t h = hash(string, table.size());
        for (int i = 0; i < table.size(); i++)
        {
            if (table[h].isInsertable())
            {
                table[h].set(string);
                break;
            }
            else if (table[h].data == string)
                throw std::runtime_error("Already exist");
            h = (h + i + 1) % table.size();
        }
        currentSize++;
        float a = ((float) currentSize) / table.size();
        if (a >= rate)
            resize();
    }

    bool find(const Key_type& string) const
    {
        size_t h = hash(string, table.size());
        for (int i = 0; i < table.size(); i++)
        {
            if (table[h].state == Node::busy && table[h].data == string)
                return true;
            h = (h + i + 1) % table.size();
        }
        return false;
    }

    void remove(const Key_type& string)
    {
        size_t h = hash(string, table.size());
        for (int i = 0; i < table.size(); i++)
        {
            if (table[h].state == Node::busy && table[h].data == string)
            {
                table[h].state = Node::deleted;
                currentSize--;
                return;
            }
            h = (h + i + 1) % table.size();
        }
        throw std::runtime_error("No such key");
    }

    size_t hash(const std::string& string, size_t m) const
    {
        size_t hash = 0;
        for (auto& i : string)
            hash = (hash * 7 + i) % m;
        return hash;
    }
};


#endif //ALGORITHM_HASHTABLE_H
