#pragma once
#include <memory>

template <class T>
class TreeNode {
private:
    T _value; // This is what the Node holds.
    bool _color; // Red/Black tree stuff.

    // We keep pointers to every node this node touches.
    std::shared_ptr<TreeNode<T>> _left;
    std::shared_ptr<TreeNode<T>> _parent;
    std::shared_ptr<TreeNode<T>> _right;

public:
    TreeNode<T>(T value);

    void set_parent(std::shared_ptr<TreeNode<T>> const& node);
    void set_left(std::shared_ptr<TreeNode<T>> const& node);
    void set_right(std::shared_ptr<TreeNode<T>> const& node);
    void set_color(bool color);
    void set_value(T value);

    std::shared_ptr<TreeNode<T>> get_parent() const;
    std::shared_ptr<TreeNode<T>> get_left() const;
    std::shared_ptr<TreeNode<T>> get_right() const;
    bool get_color();
    T get_value();
};