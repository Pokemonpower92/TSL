#include "TSLTree.cpp"
#include "TSLTree.hpp"
#include "TreeNode.cpp"
#include "TreeNode.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void insert_thread(string name, int counter, TSLTree<int>* tsl)
{
    tsl->insert_value(counter);
}

int main(int argc, char** argv)
{
    TSLTree<int> tsl;
    vector<thread> threads;

    for (int i = 0; i <= 25; i++) {
        threads.push_back(thread(&insert_thread, to_string(i), i, &tsl));
    }

    for (auto& t : threads) {
        t.join();
    }

    tsl.inspect_tree();

    return 0;
}