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
    // 5:55



    std::cout << *myAVLTree << std::endl;


    return 0;
}