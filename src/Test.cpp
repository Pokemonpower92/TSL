#include "TreeNode.cpp"
#include "TreeNode.hpp"
#include "TSLTree.cpp"
#include "TSLTree.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char** argv)
{
    TSLTree<int> tsl;

    tsl.insert_value(1);
    tsl.insert_value(2);
    tsl.insert_value(-30);

    tsl.inspect_tree();

    return 0;
}