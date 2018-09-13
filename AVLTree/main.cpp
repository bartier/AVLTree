#include <iostream>
#include "AVLTree.h"

int main() {
    std::cout << "AVLTree Project" << std::endl;

    AVLTree<int> *myAVLTree = new AVLTree<int>();

    myAVLTree->insert(1);
    myAVLTree->contains(2);
    myAVLTree->remove(3);

    return 0;
}