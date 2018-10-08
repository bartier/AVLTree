#include <stack>
#include <queue>

template<class T>
AVLTree<T>::AVLTree() {
    this->root = nullptr;
}

template<class T>
void AVLTree<T>::insert(const T &info) {
    if (this->contains(info)) {
        throw std::invalid_argument("Info already exists in AVL Tree");
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
        NodeTree<T> *tmp__2 = tmp->next(info);
        if (tmp__2 == nullptr) {
            break;
        }

        tmp = tmp__2;
        pathInsertion.push(tmp);
    }

    if (info < tmp->getInfo()) {
        tmp->setLeft(newNode);
    } else if (info > tmp->getInfo()) {
        tmp->setRight(newNode);
    }
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

    while (tmp != nullptr && !tmp->isLeaf()) {
        if (tmp->getInfo() == info) {
            return true;
        }

//        NodeTree<T> *tmp__2 = tmp->next(info);
//        if (tmp__2 == nullptr) {
//            break;
//        }
//        tmp = tmp__2;
        tmp = tmp->next(info);
    }
    if (tmp == nullptr) {
        return false;
    }
    return tmp->getInfo() == info;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const AVLTree<U> &avl) {
    std::queue<NodeTree<U> *> queue;
    NodeTree<U> *tmp = avl.root;

    while (tmp != nullptr) {
        os << tmp->getInfo() << " ";

        if (tmp->getLeft() != nullptr) {
            queue.push(tmp->getLeft());
        }

        if (tmp->getRight() != nullptr) {
            queue.push(tmp->getRight());
        }

        NodeTree<U> *tmp__2 = nullptr;
        if (queue.size() > 0) {
            tmp__2 = queue.front();
            queue.pop();
        }

        tmp = tmp__2;
    }

    return os;
}