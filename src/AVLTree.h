#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include "NodeTree.h"

template<class T>
class AVLTree {
public:
    explicit AVLTree<T>();

    void insert(T const &);

    void remove(T const &);

    void contains(T const &);
    //TODO: overload <<
private:
    NodeTree<T> *root;

};

#include "AVLTree.cpp"

#endif //AVLTREE_AVLTREE_H
