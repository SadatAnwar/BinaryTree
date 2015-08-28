#include <iostream>
#include "../headder/BinaryTree.h"
#include "../headder/AVLTree.h"

using namespace std;

int main() {
    srand((unsigned int) time(NULL));
    BinaryTree *binaryTree = new BinaryTree();
    clock_t insertBinStart = clock();
    for (int i = 0; i < 50000; i++) {
        int number = rand() % 80 +1;
        binaryTree->insert(number);
    }
    printf("Time taken for insert in Binary: %.5fms\n", (double) (clock() - insertBinStart) * 1000 / CLOCKS_PER_SEC);
    cout << "Depth of BinaryTree: " << binaryTree->getDepth() << endl;
    cout << "Bin Tree root at:  " << binaryTree->getRoot()->getValue() << endl;
    AVLTree *avlTree = new AVLTree();
    clock_t insertAVLStart = clock();
    for (int i = 0; i < 100000; i++) {
        int number = rand() % 80 + 1;
        avlTree->insert(number);
    }

    printf("Time taken for insert in AVLTree: %.5fms\n", (double) (clock() - insertAVLStart) * 1000 / CLOCKS_PER_SEC);
    cout << "Depth of AVLtree: " << avlTree->getDepth() << endl;
    printf("Total time taken: %.5fs\n", (double) (clock() - insertBinStart) / CLOCKS_PER_SEC);
    cout << "AVL Tree root at:  " << avlTree->getRoot()->getValue() << endl;
    return 0;

}