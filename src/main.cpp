#include <iostream>
#include "AVLTree.h"

int main() {

    std::cout << "AVLTree Project" << std::endl;

    auto *myAVLTree = new AVLTree<int>();

    myAVLTree->insert(15);
    myAVLTree->insert(27);
    myAVLTree->insert(49);
    myAVLTree->insert(10);
    myAVLTree->insert(8);
    myAVLTree->insert(67);
    myAVLTree->insert(59);
    myAVLTree->insert(9);
    myAVLTree->insert(13);
    myAVLTree->insert(20);
    myAVLTree->insert(14);

    std::cout << *myAVLTree << std::endl;

    return 0;
}