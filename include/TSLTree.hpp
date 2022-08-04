#pragma once
#include "TreeNode.hpp"
#include <memory>

template <class T>
class TSLTree {
    friend class TreeNode;

private:
    std::shared_ptr<TreeNode> _root;
    int _num_nodes;

public:
};