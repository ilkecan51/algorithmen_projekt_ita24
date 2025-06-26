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
    for (int i = 0; i < n; ++i)
    {
        basis[i] = i + 1;
    }

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
    std::cout << "\nDurchschnittliche Hoehe: " << avg << " (entspricht " << std::round(c) << " * log2 n)\n";
}

void TreeToolsTest::testAllFeatures() {
    std::cout << "\n--- Teste TreeTools-Funktionen ---\n";

    TreeTools tester;

    Tree* root = buildSearchTree(numberInput());

    std::cout << "Baumhoehe: " << tester.treeHeight(root) << "\n";
    std::cout << "Anzahl Knoten: " << tester.anzahlKnoten(root) << "\n";

    std::cout << "Inorder mit Klammern: ";
    tester.printTreeInorderWithParenthesis(root);
    std::cout << "\n";

    std::cout << "Levelorder: ";
    tester.printTreeLevelorder(root);

    std::vector<int> unsortiert = {6,1,9,4,2,8,3};
    std::vector<int> sortiert = tester.searchTreeSort(unsortiert);

    std::cout << "Sortiere {6,1,9,4,2,8,3}" << std::endl;
    for (int x : sortiert) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "--- Ende der Tests ---\n";
}

std::vector<int> TreeToolsTest::numberInput()
{
    int n;
    std::cout << "Aus wie vielen Elementen besteht der Baum? ";
    std::cin >> n;

    std::vector<int> zahlen(n);
    std::cout << "Bitte geben Sie " << n << " Zahlen ein:\n";

    for (int i = 0; i < n; ++i) {
        std::cin >> zahlen[i];
    }

    return zahlen;
}

