#include "TreeNode.cpp"
#include "TreeNode.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char** argv)
{
    unique_ptr<TreeNode<int>> tr(new TreeNode<int>(1));
    shared_ptr<TreeNode<int>> p(new TreeNode<int>(2));
    shared_ptr<TreeNode<int>> l(new TreeNode<int>(3));
    shared_ptr<TreeNode<int>> r(new TreeNode<int>(4));

    tr->set_parent(p);
    tr->set_left(l);
    tr->set_right(r);

    cout << "TR value: " << tr->get_value() << endl;
    cout << "TR P value: " << tr->get_parent()->get_value() << endl;
    cout << "TR L value: " << tr->get_left()->get_value() << endl;
    cout << "TR R value: " << tr->get_right()->get_value() << endl;

    return 0;
}