#pragma once

#include <cstddef>

namespace dsa {
    template <typename ValueType>
    struct listNode {
        ValueType value;
        listNode * next;
    };

    template <typename ValueType>
    class forwardList {
        listNode<ValueType> * root;
        listNode<ValueType> * far;
        mutable listNode<ValueType> * before;

        void locate(std::size_t index_) const {
            if (size() + 1 < index_) {
                before = nullptr;

                return;
            }

            before = root;
            
            for (std::size_t i {1}; i != index_; ++i) {
                before = before->next;
            }
        }

        auto reversing(listNode<ValueType> * from_, listNode<ValueType> * to_)
        -> listNode<ValueType> * {
            if (from_ != to_) {
                reversing(from_->next, to_)->next = from_;
            }

            return from_;
        }

    public:
        ~forwardList() {
            while (root) {
                listNode<ValueType> * tmp {root};
                root = root->next;

                delete tmp;
            }
        }

        forwardList(forwardList const &) = delete;
        forwardList & operator=(forwardList const &) = delete;

        forwardList()
        : root {new listNode<ValueType>} {
            far = root;
        }

        auto size() const -> std::size_t {
            std::size_t cnt {};

            listNode<ValueType> * moving {root->next};

            while (moving) {
                ++cnt;

                moving = moving->next;
            }

            return cnt;
        }

        void insert(ValueType const & value_) {
            far->next = new listNode<ValueType> {value_, nullptr};

            far = far->next;
        }

        void insert(std::size_t index_, ValueType const & value_) {
            locate(index_);

            before->next = new listNode<ValueType> {value_, before->next};

            if (far->next) {
                far = far->next;
            }
        }

        void remove() {
            locate(size());

            delete before->next;

            before->next = nullptr;
            far = before;
        }

        void remove(std::size_t index_) {
            locate(index_);

            if (before->next == far) {
                far = before;
            }

            listNode<ValueType> * tmp {before->next};
            before->next = tmp->next;

            delete tmp;
        }

        auto getValue(std::size_t index_) const -> ValueType const & {
            locate(index_);

            return before->next->value;
        }

        void setValue(std::size_t index_, ValueType const & value_) {
            locate(index_);

            before->next->value = value_;
        }

        void reverse(std::size_t from_, std::size_t to_) {
            locate(from_);
            listNode<ValueType> * front = before;
            listNode<ValueType> * from = before->next;

            locate(to_);
            listNode<ValueType> * to = before->next;
            listNode<ValueType> * back = to->next;

            reversing(from, to)->next = back;
            front->next = to;
        }
    };
}