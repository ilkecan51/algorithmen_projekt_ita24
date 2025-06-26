#ifndef TREETOOLSTEST_HPP
#define TREETOOLSTEST_HPP

#include "TreeTools.cpp"
#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>

class TreeToolsTest {
public:
    static void run();

private:
    static Tree* buildSearchTree(const std::vector<int>& zahlen);
};

#endif
