#include <queue>

template<class T>
AVLTree<T>::AVLTree() {
    this->root = nullptr;
}

template<class T>
void AVLTree<T>::insert(T info) {
    if (this->contains(info)) {
        throw std::invalid_argument("Info already exists in AVL Tree");
    }

    NodeTree<T> *newNode = new NodeTree<T>(info);

    if (this->root == nullptr) {
        this->root = newNode;
        return;
    }

    NodeTree<T> *currentNode = root;
    std::stack<NodeTree<T> *> pathInsertion;

    pathInsertion.push(currentNode);
    while (!currentNode->isLeaf()) {
        if (currentNode->next(info) == nullptr) {
            break;
        }
        currentNode = currentNode->next(info);
        pathInsertion.push(currentNode);
    }
    pathInsertion.push(newNode);

    if (info < currentNode->getInfo()) {
        currentNode->setLeft(newNode);
    } else if (info > currentNode->getInfo()) {
        currentNode->setRight(newNode);
    }
    balance(pathInsertion);
}

template<class T>
void AVLTree<T>::remove(T info) {
    if (!this->contains(info)) {
        throw std::invalid_argument("Info does not exists in AVL Tree");
    }

    NodeTree<T> *targetFather = nullptr;
    NodeTree<T> *target = this->root;

    std::stack<NodeTree<T> *> pathDeletion;

    pathDeletion.push(target);
    while (target->getInfo() != info) {
        targetFather = target;
        target = target->next(info);
        pathDeletion.push(target);
    }

    if (target->isLeaf()) {
        if (targetFather != nullptr) {
            if (targetFather->getLeft() == target) {
                targetFather->setLeft(nullptr);
            } else {
                targetFather->setRight(nullptr);
            }
        } else {
            this->root = nullptr;
        }

        delete target;
        return;
    }

    NodeTree<T> *rightChildTarget = target->getRight();
    NodeTree<T> *leftChildTarget = target->getLeft();

    // pode ser o maior dos menores
    if (leftChildTarget != nullptr) {
        NodeTree<T> *fatherOfTmpNode = target;
        NodeTree<T> *currentNode = leftChildTarget;
        T tmpInfo;

        while (!currentNode->isLeaf()) {
            fatherOfTmpNode = currentNode;
            pathDeletion.push(currentNode);

            if (currentNode->getRight() != nullptr) {
                currentNode = currentNode->getRight();
            } else {
                currentNode = currentNode->getLeft();
            }
        }
        target->setInfo(currentNode->getInfo());

        if (fatherOfTmpNode->getLeft() == currentNode) {
            fatherOfTmpNode->setLeft(nullptr);
        } else {
            fatherOfTmpNode->setRight(nullptr);
        }

        delete currentNode;
    } else {

        // pode ser o menor dos maiores
        if (rightChildTarget != nullptr) {
            NodeTree<T> *tmpNode = target->getRight();

            target->setInfo(rightChildTarget->getInfo());
            target->setRight(rightChildTarget->getRight());

            delete tmpNode;
        }
    }
    balance(pathDeletion);
}

template<class T>
bool AVLTree<T>::contains(T info) {
    if (root == nullptr) {
        return false;
    }

    if (root->getInfo() == info) {
        return true;
    }

    if (root->isLeaf()) {
        return false;
    }

    NodeTree<T> *currentNode = root->next(info);

    while (currentNode != nullptr && !currentNode->isLeaf()) {
        if (currentNode->getInfo() == info) {
            return true;
        }

        currentNode = currentNode->next(info);
    }

    if (currentNode == nullptr) {
        return false;
    }

    return currentNode->getInfo() == info;
}

template<class T>
T AVLTree<T>::matches(T info) {
    if (root == nullptr) {
        return T();
    }

    if (root->getInfo() == info) {
        return root->getInfo();
    }

    if (root->isLeaf()) {
        return T();
    }

    NodeTree<T> *tmp = root->next(info);

    while (tmp != nullptr && !tmp->isLeaf()) {
        if (tmp->getInfo() == info) {
            return tmp->getInfo();
        }

        tmp = tmp->next(info);
    }

    if (tmp == nullptr) {
        return T();
    }

    return tmp->getInfo();
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const AVLTree<U> &avl) {
    std::queue<NodeTree<U> *> queue;
    NodeTree<U> *currentNode = avl.root;

    if (currentNode == nullptr) {
        os << "{"; // return coloca o "}"
    } else {
        os << "{";
        while (currentNode != nullptr) { // currentNode é igual a nullptr quando a fila fica vazia
            os << currentNode->getInfo();

            // adiciona os filhos do nó atual na fila
            if (currentNode->getLeft() != nullptr) {
                queue.push(currentNode->getLeft());
            }

            if (currentNode->getRight() != nullptr) {
                queue.push(currentNode->getRight());
            }

            if (queue.size() > 0) {
                currentNode = queue.front();
                queue.pop();
            } else {
                currentNode = nullptr;
            }

            os << (currentNode == nullptr ? "" : ","); // currentNode == nullptr indica que é o ultimo
        }                                              // e portanto não coloca ','
    }
    return os << "}";
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
                leftRotation(currentNode, rightChild);
                if (nextNode != nullptr) {
                    nextNode->setRight(rightChild);
                } else {
                    this->root = rightChild;
                }

            } else { // situação joelho, filho com sinal diferente
                NodeTree<T> *leftChildOfRightChild = rightChild->getLeft();
                rightRotation(rightChild, leftChildOfRightChild);
                currentNode->setRight(leftChildOfRightChild);

                leftRotation(currentNode, leftChildOfRightChild);
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
                rightRotation(currentNode, leftChild);

                if (nextNode != nullptr) {
                    nextNode->setLeft(leftChild);
                } else {
                    this->root = leftChild;
                }
            } else { // situação joelho, filho com sinal diferente
                NodeTree<T> *rightChildOfLeftChild = leftChild->getRight();
                leftRotation(leftChild, rightChildOfLeftChild);
                currentNode->setLeft(rightChildOfLeftChild);

                rightRotation(currentNode, rightChildOfLeftChild);
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
void AVLTree<T>::leftRotation(NodeTree<T> *father, NodeTree<T> *child) {
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
void AVLTree<T>::rightRotation(NodeTree<T> *father, NodeTree<T> *child) {
    if (child->getRight() != nullptr) {
        NodeTree<T> *tmp = child->getRight();
        father->setLeft(tmp);
        child->setRight(father);
    } else {
        child->setRight(father);
        father->setLeft(nullptr);
    }
}