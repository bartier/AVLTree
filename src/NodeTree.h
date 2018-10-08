#ifndef AVLTREE_NODETREE_H
#define AVLTREE_NODETREE_H

template<class T>
class NodeTree {
public:
    explicit NodeTree<T>();
private:
    T info;
    NodeTree<T> *left;
    NodeTree<T> *right;
    int balanceFactor;

};

#include "NodeTree.cpp"

#endif //AVLTREE_NODETREE_H
