#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <iostream>
#include <stack>
#include "NodeTree.h"

template<class T>
class AVLTree {
public:
    explicit AVLTree<T>();

    void insert(T const &info);

    void remove(T const &info);

    bool contains(T const &info);

    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const AVLTree<U> &avl);

private:
    NodeTree<T> *root;

    void balance(std::stack<NodeTree<T> *> &stack);
};

#include "AVLTree.inl"

#endif //AVLTREE_AVLTREE_H
