#pragma once

namespace DataStructures {

template <typename Key>
class AVLTree {
private:
    struct Node {
        Key key;
        int height;
        Node *left, *right;

        explicit Node(const Key& key) {
            this->key = key;
            this->height = 1;
            this->left = this->right = nullptr;
        }
    } *root;

    int height(Node* node) {
        if (!node)
            return 0;
        return node->height;
    }

    void fixHeight(Node* node) {
        int l = height(node->left);
        int r = height(node->right);
        node->height = (l < r ? r : l) + 1;
    }

    int bfactor(Node* node) {
        return height(node->right) - height(node->left);
    }

    Node* rightRotation(Node* a) {
        Node* b = a->left;
        a->left = b->right;
        b->right = a;
        fixHeight(a);
        fixHeight(b);
        return b;
    }

    Node* leftRotation(Node* a) {
        Node* b = a->right;
        a->right = b->left;
        b->left = a;
        fixHeight(a);
        fixHeight(b);
        return b;
    }

    Node* balance(Node* node) {
        fixHeight(node);
        if (bfactor(node) == 2) {
            if (bfactor(node->right) < 0)
                node->right = rightRotation(node->right);
            return leftRotation(node);
        }
        if (bfactor(node) == -2) {
            if (bfactor(node->left) > 0)
                node->left = leftRotation(node->left);
            return rightRotation(node);
        }
        return node;
    }

    Node* _insert(Node* node, const Key& k) {
        if (!node)
            return new Node(k);
        if (k < node->key)
            node->left = _insert(node->left, k);
        else
            node->right = _insert(node->right, k);
        return balance(node);
    }

    Node* findMin(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* removeMin(Node* node) {
        if (!node->left)
            return node->right;
        node->left = removeMin(node->left);
        return balance(node);
    }

    Node* _remove(Node* node, const Key& k) {
        if (!node)
            return nullptr;
        if (k < node->key)
            node->left = _remove(node->left, k);
        else if (k > node->key)
            node->right = _remove(node->right, k);
        else {
            Node* left = node->left;
            Node* right = node->right;
            delete node;
            if (!right)
                return left;
            Node* min = findMin(right);
            min->right = removeMin(right);
            min->left = left;
            return balance(min);
        }
        return balance(node);
    }

    Node* _find(Node* root, const Key& key) const {
        if (!root) {
            return nullptr;
        }
        if (root->key == key) {
            return root;
        }
        if (key < root->key) {
            return _find(root->left, key);
        }
        return _find(root->right, key);
    }
public:
    AVLTree() : root(nullptr) {}

    void insert(const Key& key) {
        root = _insert(root, key);
    }

    const Key* find(const Key& key) const {
        if (const auto* data = _find(root, key)) {
            return &data->key;
        }
        return nullptr;
    }

    void remove(const Key& key) {
        root = _remove(root, key);
    }

    int getHeight() {
        return height(root);
    }
};

}
