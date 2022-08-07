#pragma once
#include "TreeNode.hpp"
#include <memory>
#include <mutex>

template <class T>
class TSLTree {
    friend class TreeNode<T>;

private:
    std::shared_ptr<TreeNode<T>> _root;
    std::mutex _mutex;
    int _num_nodes;

    void _insert_node(std::shared_ptr<TreeNode<T>> const& node);
    void _recursive_insert_helper(
        std::shared_ptr<TreeNode<T>> curr,
        std::shared_ptr<TreeNode<T>> node);

    void _recursive_inspect_tree_helper(std::shared_ptr<TreeNode<T>> node) const;

public:
    TSLTree<T>();
    TSLTree(TSLTree<T> const& other);
    TSLTree<T>& operator=(TSLTree<T> const& other);

    std::shared_ptr<TreeNode<T>> insert_value(T value);
    std::shared_ptr<TreeNode<T>> find_value(T value) const;

    void inspect_tree() const;
};
