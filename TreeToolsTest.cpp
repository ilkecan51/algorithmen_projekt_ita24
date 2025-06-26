#include "TreeToolsTest.h"


Tree* TreeToolsTest::buildSearchTree(const std::vector<int>& zahlen) {
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
    return root;
}

void TreeToolsTest::run() {
    int n, runs;
    std::cout << "Anzahl der Knoten: ";
    std::cin >> n;
    std::cout << "Anzahl der Durchlaeufe: ";
    std::cin >> runs;

    std::vector<int> basis(n);
    for (int i = 0; i < n; ++i) basis[i] = i + 1;

    std::default_random_engine rng(static_cast<unsigned>(std::time(nullptr)));
    double sumHeight = 0.0;

    std::cout << "\nErzeuge " << runs << " Suchbaeume mit je " << n << " Knoten\n\n";

    for (int i = 1; i <= runs; ++i) {
        std::vector<int> zufall = basis;
        std::shuffle(zufall.begin(), zufall.end(), rng);
        Tree* tree = buildSearchTree(zufall);
        int height = TreeTools::treeHeight(tree);
        std::cout << "Hoehe Suchbaum " << i << ": " << height << "\n";
        sumHeight += height;
    }

    double avg = sumHeight / runs;
    double c = avg / (std::log2(n));
    std::cout << "\nDurchschnittliche Hoehe: " << avg << " (entspricht " << std::round(c * 100) / 100 << " * log2 n)\n";
}
