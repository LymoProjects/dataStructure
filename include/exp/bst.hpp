#pragma once

#include <memory>

template <typename keyType, typename valueType>
class bst {
    struct treeNode {
        keyType key;
        valueType value;

        treeNode * left {};
        treeNode * right {};
    };

    treeNode * root {};
    std::size_t length {};

    auto insert__(treeNode * node, keyType const & key, valueType const & value) -> treeNode * {
        if (node) {
            if (node->key < key) {
                node->right = insert__(node->right, key, value);
            } else if (key < node->key) {
                node->left = insert__(node->left, key, value);
            } else {
                node->value = value;
            }
        } else {
            node = new treeNode(key, value);

            ++length;
        }

        return node;
    }

    auto find__(treeNode * node, keyType const & key) -> treeNode * {
        if (node) {
            if (node->key < key) {
                return find__(node->right, key);
            } else if (key < node->key) {
                return find__(node->left, key);
            } else {
                return node;
            }
        } else {
            return nullptr;
        }
    }

    auto findMaxNode(treeNode * node) -> treeNode * {
        if (node) {
            return node->right ? findMaxNode(node->right) : node;
        }

        return nullptr;
    }

    auto findMinNode(treeNode * node) -> treeNode * {
        if (node) {
            return node->left ? findMinNode(node->left) : node;
        }

        return nullptr;
    }

    auto remove__(treeNode * node, keyType const & key) -> treeNode * {
        if (node->key < key) {
            node->right = remove__(node->right, key);
        } else if (key < node->key) {
            node->left = remove__(node->left, key);
        } else {
            if (!node->left) {
                treeNode * tmp {node};

                node = node->right;

                delete tmp;
            } else if (!node->right) {
                treeNode * tmp {node};

                node = node->left;

                delete tmp;
            } else {
                treeNode * toDelete {findMaxNode(node->left)};

                keyType newKey {toDelete->key};
                valueType newValue {toDelete->value};

                node->left = remove__(node->left, newKey);

                node->key = std::move(newKey);
                node->value = std::move(newValue);
            }

            --length;
        }

        return node;
    }

    auto destroy(treeNode * node) -> void {
        if (node) {
            destroy(node->left);
            destroy(node->right);

            delete node;
        }
    }
public:
    ~bst() {
        destroy(root);
    }

    bst(bst const &) = delete;
    auto operator=(bst const &) = delete;

    explicit
    bst() = default;

    auto size() const -> std::size_t {
        return length;
    }

    auto empty() const -> bool {
        return size() == 0;
    }

    auto insert(keyType const & key, valueType const & value) -> void {
        root = insert__(root, key, value);
    }

    auto get(keyType const & key) const -> valueType {
        treeNode * target {find__(root, key)};

        return target ? target->value : valueType {};
    }

    auto contain(keyType const & key) const -> bool {
        return find__(root, key) ? true : false;
    }

    auto remove(keyType const & key) -> void {
        if (!contain(key)) {
            return;
        }

        root = remove__(root, key);
    }
};

namespace exp__ {
    template <typename keyType, typename valueType>
    class bst {
        struct bstNode {
            keyType key {};
            valueType value {};

            bstNode * left {};
            bstNode * right {};
        };

        bstNode * root {};

        auto destroy(bstNode * node) -> void {
            if (node) {
                destroy(node->left);
                destroy(node->right);

                delete node;
            }
        }

        auto insert__(bstNode * node, keyType const & key, valueType const & value) -> bstNode * {
            if (node) {
                if (key < node->key) {
                    node->left = insert__(node->left, key, value);
                } else if (node->key < key) {
                    node->right = insert__(node->right, key, value);
                } else {
                    node->value = value;
                }
            } else {
                node = new bstNode {key, value};
            }

            return node;
        }

        auto find__(bstNode * node, keyType const & key) const -> bstNode * {
            if (node) {
                if (node->key < key) {
                    return find__(node->right, key);
                } else if (key < node->key) {
                    return find__(node->left, key);
                } else {
                    return node;
                }
            } else {
                return nullptr;
            }
        }

        auto findMaxNode(bstNode * node) -> bstNode * {
            if (node) {
                return node->right ? findMaxNode(node->right) : node;
            } else {
                return nullptr;
            }
        }

        auto findMinNode(bstNode * node) ->bstNode * {
            if (node) {
                return node->left ? findMinNode(node->left) : node;
            }

            return nullptr;
        }

        auto remove__(bstNode * node, keyType const & key) -> bstNode * {
            if (node->key < key) {
                node->right = remove__(node->right, key);
            } else if (key < node->key) {
                node->left = remove__(node->left, key);
            } else {
                if (!node->left) {
                    bstNode * tmp {node};

                    node = node->right;

                    delete tmp;
                } else if (!node->right) {
                    bstNode * tmp {node};

                    node = node->left;

                    delete tmp;
                } else {
                    bstNode * tmp {findMinNode(node->right)};

                    keyType tmpKey {std::move(tmp->key)};
                    valueType tmpValue {std::move(tmp->value)};

                    node->right = remove__(node->right, tmpKey);

                    node->key = std::move(tmpKey);
                    node->value = std::move(tmpValue);
                }
            }
        }

    public:
        ~bst() {
            destroy(root);
        }

        bst(bst const &) = delete;
        auto operator=(bst const &) -> bst & = delete;

        explicit
        bst() = default;

        auto insert(keyType const & key, valueType const & value) -> void {
            root = insert__(root, key, value);
        }

        auto find(keyType const & key) const -> valueType {
            bstNode * target {find__(root, key)};

            return target ? *target : valueType {};
        }

        auto contain(keyType const & key) const -> bool {
            return find__(root, key) != nullptr;
        }

        auto remove(keyType const & key) -> void {
            if (contain(key)) {
                root = remove__(root, key);
            }
        }
    };
}