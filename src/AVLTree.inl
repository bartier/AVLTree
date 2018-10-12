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
    pathInsertion.push(newNode);

    if (info < tmp->getInfo()) {
        tmp->setLeft(newNode);
    } else if (info > tmp->getInfo()) {
        tmp->setRight(newNode);
    }
    balance(pathInsertion);
}

template<class T>
void AVLTree<T>::balance(std::stack<NodeTree<T> *> &stack) {
    // 0, -1 e 1 são valores válidos para o BalanceFactor
    // se BalanceFactor < 0
    // subárvore da direita tem mais peso
    // se BalanceFactor > 0
    // subárvore da esquerda tem mais peso

    int currentBalanceFactor;
    NodeTree<T> *currentNode = nullptr;
    NodeTree<T> *nextNode = nullptr;

    while (stack.size() > 0) {
        currentNode = stack.top();
        stack.pop();
        if (stack.size() > 0) {
            nextNode = stack.top();
        } else {
            nextNode = nullptr;
        }

        currentBalanceFactor = currentNode->getBalanceFactor();

        NodeTree<T> *rightChild;
        if (currentBalanceFactor < -1) { // pendendo para a direita
            rightChild = currentNode->getRight();
            if (rightChild->getBalanceFactor() < 0) { // filho com mesmo sinal
                // R.S.E(15,27)
                rse(currentNode, rightChild);
                if (nextNode != nullptr) {
                    nextNode->setRight(rightChild);
                } else {
                    this->root = rightChild;
                }

            } else { // situação joelho
                NodeTree<T> *leftChildOfRightChild = rightChild->getLeft();
                rsd(rightChild, leftChildOfRightChild);
                currentNode->setRight(leftChildOfRightChild);

                rse(currentNode, leftChildOfRightChild);
                if (nextNode != nullptr) {
                    nextNode->setRight(leftChildOfRightChild);
                } else {
                    this->root = leftChildOfRightChild;
                }
            }
        }

        NodeTree<T> *leftChild;
        if (currentBalanceFactor > 1) { // pendendo para a esquerda
            leftChild = currentNode->getLeft();
            if (leftChild->getBalanceFactor() > 0) { // filho com mesmo sinal
                rsd(currentNode, leftChild);

                if (nextNode != nullptr) {
                    nextNode->setLeft(leftChild);
                } else {
                    this->root = leftChild;
                }
            } else {
                NodeTree<T> *rightChildOfLeftChild = leftChild->getRight();
                rse(leftChild, rightChildOfLeftChild);
                currentNode->setLeft(rightChildOfLeftChild);

                rsd(currentNode, rightChildOfLeftChild);
                if (nextNode != nullptr) {
                    nextNode->setLeft(rightChildOfLeftChild);
                } else {
                    this->root = rightChildOfLeftChild;
                }
            }

        }


    }

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

template<class T>
void AVLTree<T>::rse(NodeTree<T> *father, NodeTree<T> *child) {
    if (child->getLeft() != nullptr) {
        NodeTree<T> *tmp = child->getLeft();
        father->setRight(tmp);
        child->setLeft(father);
    } else {
        child->setLeft(father);
        father->setRight(nullptr);
    }
}

template<class T>
void AVLTree<T>::rsd(NodeTree<T> *father, NodeTree<T> *child) {
    if (child->getRight() != nullptr) {
        NodeTree<T> *tmp = child->getRight();
        father->setLeft(tmp);
        child->setRight(father);
    } else {
        child->setRight(father);
        father->setLeft(nullptr);
    }

}
