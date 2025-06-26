#include "TreeTools.hpp"

int TreeTools::treeHeight(Tree* baum) {
    if (!baum) return 0;
    return 1 + std::max(treeHeight(baum->left), treeHeight(baum->right));
}

int TreeTools::anzahlKnoten(Tree* baum) {
    if (!baum) return 0;
    return 1 + anzahlKnoten(baum->left) + anzahlKnoten(baum->right);
}

void TreeTools::printTreeInorderWithParenthesis(Tree* baum) {
    if (!baum) return;
    if (baum->left || baum->right) std::cout << "(";
    printTreeInorderWithParenthesis(baum->left);
    std::cout << baum->key;
    printTreeInorderWithParenthesis(baum->right);
    if (baum->left || baum->right) std::cout << ")";
}

void TreeTools::printTreeLevelorder(Tree* baum) {
    if (!baum) return;
    std::queue<Tree*> q;
    q.push(baum);
    while (!q.empty()) {
        Tree* node = q.front();
        q.pop();
        std::cout << node->key << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    std::cout << std::endl;
}

std::vector<int> TreeTools::searchTreeSort(const std::vector<int>& zahlen) {
    Tree* root = nullptr;
    for (int zahl : zahlen) {
        Tree** current = &root;
        while (*current) {
            if (zahl < (*current)->key) {
                current = &(*current)->left;
            } else {
                current = &(*current)->right;
            }

        }
        *current = new Tree(zahl);
    }

    std::stack<int> s;
    tree2SortedStack(root, s);
    std::vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void TreeTools::tree2SortedStack(Tree* baum, std::stack<int>& s) {
    if (!baum) return;
    tree2SortedStack(baum->right, s);
    s.push(baum->key);
    tree2SortedStack(baum->left, s);
}
