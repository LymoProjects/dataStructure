#pragma once

#include <algorithm>
#include <cstddef>

namespace dsa {
    template <typename KeyType, typename ValueType>
    struct bstNode {
        KeyType key;
        ValueType value;
        bstNode * left;
        bstNode * right;
    };

    template <typename keyType, typename valueType>
    class bst {
        bstNode<keyType, valueType> * root;
        std::size_t nodeSum;

    public:
        ~bst() {
            destory(root);
        }

        explicit bst() : root(nullptr), nodeSum {} {}

        auto size() const -> std::size_t {
            return nodeSum;
        }

        auto empty() const -> bool {
            return nodeSum == 0;
        }

        void insert(keyType key, valueType value) {
            root = insert(root, key, value);
        }

        auto contain(keyType const & key) const -> bool {
            return find(root, key) != nullptr;
        }

        auto getValue(keyType key) const -> valueType const & {
            return find(root, key)->value;
        }

        void remove(keyType const & key) {
            if (contain(key)) {
                root = remove(root, key);

                --nodeSum;
            }
        }

    private:
        void destory(bstNode<keyType, valueType> * node) {
            if (node) {
                destory(node->left);
                destory(node->right);

                delete node;
            }
        }

        auto insert(bstNode<keyType, valueType> * node, keyType & key, valueType & value)
        -> bstNode<keyType, valueType> * {
            if (!node) {
                ++nodeSum;
                return new bstNode<keyType, valueType> {std::move(key), std::move(value)};
            }

            if (node->key < key) {
                node->right = insert(node->right, key, value);
            } else if (key < node->key) {
                node->left = insert(node->left, key, value);
            } else {
                node->value = std::move(value);
            }

            return node;
        }

        auto find(bstNode<keyType, valueType> * node, keyType const & key) const
        -> bstNode<keyType, valueType> * {
            if (!node) {
                return nullptr;
            }

            if (node->key < key) {
                return find(node->right, key);
            } else if (key < node->key) {
                return find(node->left, key);
            } else {
                return node;
            }
        }

        auto findMaxNode(bstNode<keyType, valueType> * node)
        -> bstNode<keyType, valueType> * {
            if (!node) {
                return nullptr;
            }

            if (node->right) {
                return findMaxNode(node->right);
            } else {
                return node;
            }
        }

        auto findMinNode(bst<keyType, valueType> * node)
        -> bstNode<keyType, valueType> * {
            if (!node) {
                return nullptr;
            }

            if (node->left) {
                return findMinNode(node->left);
            } else {
                return node;
            }
        }

        auto remove(bstNode<keyType, valueType> * node, keyType const & key)
        -> bstNode<keyType, valueType> * {
            if (node->key < key) {
                node->right = remove(node->right, key);
            } else if (key < node->key) {
                node->left = remove(node->left, key);
            } else {
                if (!node->left) {
                    bstNode<keyType, valueType> * tmp {node};
                    node = node->right;

                    delete tmp;
                } else if (!node->right) {
                    bstNode<keyType, valueType> * tmp {node};
                    node = node->left;

                    delete tmp;
                } else {
                    bstNode<keyType, valueType> * tmp {findMaxNode(node->left)};

                    keyType key_ {tmp->key};
                    valueType value_ {tmp->value};

                    node->left = remove(node->left, key_);

                    node->key = std::move(key_);
                    node->value = std::move(value_);
                }
            }

            return node;
        }
    };
}