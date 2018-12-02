#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <iostream>
#include <stack>
#include "NodeTree.h"

template<class T>
class AVLTree {
public:
    AVLTree<T>();

    void insert  (T info);
    void remove  (T info);
    bool contains(T info);
    T    matches (T info);

    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const AVLTree<U> &avl);

private:
    NodeTree<T> *root;

    void balance(std::stack<NodeTree<T> *> &stack);
    void leftRotation(NodeTree<T> *father, NodeTree<T> *child);
    void rightRotation(NodeTree<T> *father, NodeTree<T> *child);
};

#include "AVLTree.inl"

#endif //AVLTREE_AVLTREE_H
