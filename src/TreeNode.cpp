#include "TreeNode.hpp"
#include "memory"

template <class T>
TreeNode<T>::TreeNode(T value)
{
    this->_value = value;
    this->_parent = NULL;
    this->_left = NULL;
    this->_right = NULL;
}

/* @ Mutators.
 */
template <class T>
void TreeNode<T>::set_parent(std::shared_ptr<TreeNode<T>> const& node)
{
    this->_parent = node;
}

template <class T>
void TreeNode<T>::set_left(std::shared_ptr<TreeNode<T>> const& node)
{
    this->_left = node;
}

template <class T>
void TreeNode<T>::set_right(std::shared_ptr<TreeNode<T>> const& node)
{
    this->_right = node;
}

template <class T>
T TreeNode<T>::get_value()
{
    return this->_value;
}

/* @ Accessors
 */
template <class T>
std::shared_ptr<TreeNode<T>> TreeNode<T>::get_parent()
{
    return this->_parent;
}

template <class T>
std::shared_ptr<TreeNode<T>> TreeNode<T>::get_left()
{
    return this->_left;
}

template <class T>
std::shared_ptr<TreeNode<T>> TreeNode<T>::get_right()
{
    return this->_right;
}
