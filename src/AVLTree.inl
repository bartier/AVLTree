#include <stack>
#include <queue>

template<class T>
AVLTree<T>::AVLTree() {
    this->root = nullptr;
}

template<class T>
void AVLTree<T>::insert(const T &info) {
    if (this->contains(info)) {
        // não incluir informações iguais na árvore avl, lançar excessão
    }

    NodeTree<T> *newNode = new NodeTree<T>(info);

    if (this->root == nullptr) {
        this->root = newNode;
        return;
    }

    NodeTree<T> *tmp = root;
    std::stack<NodeTree<T> *> pathInsertion;

    pathInsertion.push(tmp);
    while (!tmp->isLeaf()) {
        tmp = tmp->next(info);
        pathInsertion.push(tmp);
    }

    if (info < tmp->getInfo()) {
        tmp->setLeft(newNode);
    } else if (info > tmp->getInfo()) {
        tmp->setRight(newNode);
    }

    // balancear após inserção normal de BST
    balance(pathInsertion);
}

template<class T>
void AVLTree<T>::balance(std::stack<NodeTree<T> *> &stack) {

}

template<class T>
void AVLTree<T>::remove(const T &) {
    std::cout << "REMOVE" << std::endl;
}

template<class T>
bool AVLTree<T>::contains(const T &info) {
    if (root == nullptr) {
        return false;
    }

    if (root->getInfo() == info) {
        return true;
    }

    if (root->isLeaf()) {
        return false;
    }

    NodeTree<T> *tmp = root->next(info);

    while (!tmp->isLeaf()) {
        if (tmp->getInfo() == info) {
            return true;
        }
        tmp = tmp->next(info);
    }
    return tmp->getInfo() == info;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const AVLTree<U> &avl) {
    std::queue<NodeTree<U> *> queue;
    NodeTree<U> *tmp = avl.root;

    while (tmp != nullptr) {
        os << tmp->getInfo();

        queue.push(tmp->getLeft());
        queue.push(tmp->getRight());

        NodeTree<U> *tmp__2 = queue.front();
        tmp = tmp__2;

        queue.pop();
    }

    return os;
}