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

    /**
     * Verifica se a informação existe na árvore.
     * @param info
     * @return true se ela existe na árvore, caso contrário false.
     */
    bool contains(T const &info);

    /**
     * Overload <<
     * @see https://www.geeksforgeeks.org/level-order-tree-traversal/
     * @details Usado Level Order Tree Traversal
     */
    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const AVLTree<U> &avl);

private:
    NodeTree<T> *root;

    void balance(std::stack<NodeTree<T> *> &stack);

    void rse(NodeTree<T> *father, NodeTree<T> *child);

    void rsd(NodeTree<T> *father, NodeTree<T> *child);
};

#include "AVLTree.inl"

#endif //AVLTREE_AVLTREE_H
