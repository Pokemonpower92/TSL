#include "TreeNode.hpp"
#include "memory"

template <class T>
TreeNode<T>::TreeNode(T value)
{
    this->_value = value;
    this->_parent = NULL;
    this->_left = NULL;
    this->_right = NULL;
    this->_color = 0;
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
void TreeNode<T>::set_color(bool color)
{
    this->_color = color;
}

template <class T>
void TreeNode<T>::set_value(T value)
{
    this->_value = value;
}

/* @ Accessors
 */
template <class T>
std::shared_ptr<TreeNode<T>> TreeNode<T>::get_parent() const
{
    return this->_parent;
}

template <class T>
std::shared_ptr<TreeNode<T>> TreeNode<T>::get_left() const
{
    return this->_left;
}

template <class T>
std::shared_ptr<TreeNode<T>> TreeNode<T>::get_right() const
{
    return this->_right;
}

template <class T>
bool TreeNode<T>::get_color()
{
    return this->_color;
}

template <class T>
T TreeNode<T>::get_value()
{
    return this->_value;
}