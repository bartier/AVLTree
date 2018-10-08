#include <iostream>

template<class T>
AVLTree<T>::AVLTree() {
    this->root = nullptr;
}

template<class T>
void AVLTree<T>::insert(const T &) {
    std::cout << "INSERT" << std::endl;
}

template<class T>
void AVLTree<T>::remove(const T &) {
    std::cout << "REMOVE" << std::endl;
}

template<class T>
void AVLTree<T>::contains(const T &) {
    std::cout << "CONTAINS" << std::endl;
}