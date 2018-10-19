#include <iostream>
#include "AVLTree.h"

int main() {

    std::cout << "AVLTree" << std::endl;

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

    std::cout << myAVLTree->contains(15);
    std::cout << myAVLTree->contains(27);
    std::cout << myAVLTree->contains(49);
    std::cout << myAVLTree->contains(10);
    std::cout << myAVLTree->contains(8);
    std::cout << myAVLTree->contains(67);
    std::cout << myAVLTree->contains(59);
    std::cout << myAVLTree->contains(9);
    std::cout << myAVLTree->contains(13);
    std::cout << myAVLTree->contains(20);
    std::cout << myAVLTree->contains(14);
    std::cout << std::endl;

    std::cout << myAVLTree->contains(-55);
    std::cout << myAVLTree->contains(0);
    std::cout << myAVLTree->contains(1000);
    std::cout << myAVLTree->contains(1231);
    std::cout << myAVLTree->contains(-999);
    std::cout << myAVLTree->contains(555);
    std::cout << myAVLTree->contains(666);
    std::cout << myAVLTree->contains(0x123);
    std::cout << myAVLTree->contains(0x0);
    std::cout << myAVLTree->contains(-666);
    std::cout << myAVLTree->contains(133);
    std::cout << std::endl;

//    myAVLTree->remove(9);
//    myAVLTree->remove(13);
//    myAVLTree->remove(20);
    myAVLTree->remove(10);

    std::cout << "Árvore em nível: " << *myAVLTree << std::endl;

    return 0;
}