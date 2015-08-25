#include <iostream>
#include "../headder/Tree.h"

using namespace std;

int main() {
    srand(time(NULL));
    Tree* binaryTree = new Tree();
    clock_t insertStart = clock();
    for (int i = 0; i<200; i++){
        int number = rand() % 80 +1;
        binaryTree->insert(number);
    }
    printf("Time taken for insert: %.5fs\n", (double)(clock() - insertStart)/CLOCKS_PER_SEC);
    clock_t start = clock();
    binaryTree->search(80);
    binaryTree->print();
    cout << "Depth of tree " << binaryTree->getDepth() << endl;
    printf("Time taken for search: %.6fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    printf("Total time taken: %.5fs\n", (double)(clock() - insertStart)/CLOCKS_PER_SEC);

}