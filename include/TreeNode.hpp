#pragma once
#include <memory>

template <class T>
class TreeNode {
private:
    T _value;
    bool _color;

    std::shared_ptr<TreeNode<T>> _left;
    std::shared_ptr<TreeNode<T>> _parent;
    std::shared_ptr<TreeNode<T>> _right;

public:
    TreeNode<T>(T value);

    void set_parent(std::shared_ptr<TreeNode<T>> const& node);
    void set_left(std::shared_ptr<TreeNode<T>> const& node);
    void set_right(std::shared_ptr<TreeNode<T>> const& node);

    std::shared_ptr<TreeNode<T>> get_parent();
    std::shared_ptr<TreeNode<T>> get_left();
    std::shared_ptr<TreeNode<T>> get_right();

    T get_value();
};