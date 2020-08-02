//
// Created by Dima on 23.03.2017.
//

#pragma once

#include <vector>

// TODO add remove method
// TODO need research
template <typename Key_type>
class Treap {
private:
    struct Node {
        Key_type key;
        int priority;
        Node* left;
        Node* right;
    } *root;

    void split(Node* currentNode, Key_type key, Node*& left, Node*& right) {
        if (!currentNode) {
            left = nullptr;
            right = nullptr;
        } else if (currentNode->key <= key) {
            split(currentNode->right, key, currentNode->right, right);
            left = currentNode;
        } else {
            split(currentNode->left, key, left, currentNode->left);
            right = currentNode;
        }
    }

    Node* merge(Node* left, Node* right) {
        if (!left || !right)
            return !left ? right : left;
        if (left->priority > right->priority) {
            left->right = merge(left->right, right);
            return left;
        }
        right->left = merge(right->left, left);
        return right;
    }


    void _insert(Node*& currentNode, Key_type key, int priority) {
        if (!currentNode) {
            currentNode = new Node;
            currentNode->key = key;
            currentNode->priority = priority;
            currentNode->left = nullptr;
            currentNode->right = nullptr;
        } else if (currentNode->priority < priority) {
            Node *left = nullptr, *right = nullptr;

            split(currentNode, key, left, right);

            currentNode = new Node;

            currentNode->key = key;
            currentNode->priority = priority;
            currentNode->left = left;
            currentNode->right = right;

        } else if (currentNode->key < key) {
            _insert(currentNode->right, key, priority);
        } else {
            _insert(currentNode->left, key, priority);
        }
    }

    int _depth(Node* currentNode, int depth) {
        if (!currentNode) {
            return depth;
        } else {
            return std::max(_depth(currentNode->left, depth + 1), _depth(currentNode->right, depth + 1));
        }
    }


public:
    Treap() : root(nullptr) {}

    void insert(Key_type key, int priority) {
        _insert(root, key, priority);
    }

    int depth() {
        return _depth(root, 0);
    }
};
