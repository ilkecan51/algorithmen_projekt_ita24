#ifndef TREETOOLS_HPP
#define TREETOOLS_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>

struct Tree {
    int key;
    Tree* left;
    Tree* right;
    Tree(int k) : key(k), left(nullptr), right(nullptr) {}
};

class TreeTools {
public:
    static int treeHeight(Tree* baum);
    static int anzahlKnoten(Tree* baum);
    static void printTreeInorderWithParenthesis(Tree* baum);
    static void printTreeLevelorder(Tree* baum);
    static std::vector<int> searchTreeSort(const std::vector<int>& zahlen);

private:
    static void tree2SortedStack(Tree* baum, std::stack<int>& s);
};

#endif
