#include "TSLTree.hpp"
#include <iostream>
#include <memory>
#include <mutex>

// ******** @Constructors.
template <class T>
TSLTree<T>::TSLTree()
{
    this->_root = NULL;
    this->_num_nodes = 0;
}

template <class T>
TSLTree<T>::TSLTree(TSLTree<T> const& other)
{
}

template <class T>
TSLTree<T>& TSLTree<T>::operator=(TSLTree<T> const& other)
{
    // lock both objects
    std::unique_lock<std::mutex> lock_this(this->_mutex, std::defer_lock);
    std::unique_lock<std::mutex> lock_other(other._mutex, std::defer_lock);

    // ensure no deadlock
    std::lock(lock_this, lock_other);

    // TODO copy constructor.
    this->_root = other->_root;
}

// ******** @Insertion.
template <class T>
void TSLTree<T>::_recursive_insert_helper(
    std::shared_ptr<TreeNode<T>> curr,
    std::shared_ptr<TreeNode<T>> node)
{
    if (node->get_value() < curr->get_value()) {
        if (curr->get_left() == NULL) {
            curr->set_left(node);
            return;
        }
        _recursive_insert_helper(curr->get_left(), node);
    }
    if (node->get_value() > curr->get_value()) {
        if (curr->get_right() == NULL) {
            curr->set_right(node);
            return;
        }
        _recursive_insert_helper(curr->get_right(), node);
    }
}

template <class T>
void TSLTree<T>::_insert_node(std::shared_ptr<TreeNode<T>> const& node)
{
    std::shared_ptr<TreeNode<T>> curr_node = this->_root;

    if (this->_root == NULL) {
        this->_root = node;
        return;
    }

    this->_recursive_insert_helper(curr_node, node);
}

template <class T>
std::shared_ptr<TreeNode<T>> TSLTree<T>::insert_value(T value)
{
    std::unique_lock<std::mutex> lock(this->_mutex);
    std::shared_ptr<TreeNode<int>> node_to_insert(new TreeNode<T>(value));

    this->_insert_node(node_to_insert);

    return node_to_insert;
}

// ******** @Query.
template <class T>
std::shared_ptr<TreeNode<T>> TSLTree<T>::find_value(T value) const
{
    return this->_root;
}

// ******** @Inspect.
template <class T>
void TSLTree<T>::_recursive_inspect_tree_helper(
    std::shared_ptr<TreeNode<T>> node) const
{
    if (node == NULL)
        return;

    _recursive_inspect_tree_helper(node->get_left());
    std::cout << "Value: " << node->get_value() << std::endl;
    _recursive_inspect_tree_helper(node->get_right());
}

template <class T>
void TSLTree<T>::inspect_tree() const
{
    _recursive_inspect_tree_helper(_root);
}