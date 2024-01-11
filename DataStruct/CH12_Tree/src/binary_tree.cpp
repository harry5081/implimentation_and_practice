#include <binary_tree.h>
#include <iostream>
#include <queue>

using namespace std;

template<typename T>
BinaryTree<T>::BinaryTree(){
    root = nullptr;
}

template<typename T>
void BinaryTree<T>::Print(Node<T> node){
    cout<< "Index: "<< node.index << endl;
    cout<< "Data: "<< node.data << endl;
}

template<typename T>
bool BinaryTree<T>::Insert(int i, T data){
    if(root == nullptr){
        root = new Node<T>{i, data, nullptr, nullptr, nullptr};
        return true;
    }

    Node<T>* cur = root;
    while(true){
        if(i == cur->index){
            return false;
        }
        else if(i < cur->index){
            if(cur->left == nullptr){
                cur->left = new Node<T>{i, data, nullptr, nullptr, cur};
                return true;
            }
            cur = cur->left;
        }
        else{
            if(cur->right == nullptr){
                cur->right = new Node<T>{i, data, nullptr, nullptr, cur};
                return true;
            }
            cur = cur->right;
        }

    }
}

template<typename T>
Node<T>* BinaryTree<T>::Search(int target){
    if(root == nullptr){
        return nullptr;
    }
    Node<T>* cur = root;
    while(true){
        if(target == cur->index){
            return cur;
        }
        else if(target < cur->index){
            if(cur->left == nullptr){
                return nullptr;
            }
            cur = cur->left;
        }
        else{
            if(cur->right == nullptr){
                return nullptr;
            }
            cur = cur->right;
        }
    }
    return nullptr;
}

template<typename T>
bool BinaryTree<T>::Delete(int target){
    Node<T>* delete_node = Search(target);

    if(delete_node == nullptr){
        return false;
    }

    //case 1: the node is a leaf node
    if(delete_node->left == nullptr && delete_node->right == nullptr){
        if(delete_node == root){
            root = nullptr;
        }
        if(delete_node == delete_node->parent->left){
            delete_node->parent->left = nullptr;
        }
        else{
            delete_node->parent->right = nullptr;
        }
        delete delete_node;
    }

    //case 3: the node has 2 child nodes
    else if(delete_node->left != nullptr && delete_node->right != nullptr){
        Node<T>* successor = Left_Most(delete_node->right);
        
        int index_tmp = successor->index;
        T tmp = successor->data;
        
        Delete(successor->index);
        
        delete_node->index = index_tmp;
        delete_node->data = tmp;
    }

    //case 2: the node has a child node
    else{
        Node<T>* child = (delete_node->left != nullptr)?delete_node->left:delete_node->right;
        
        if(delete_node == root){
            root = child;
        }

        if(delete_node == delete_node->parent->left){
            delete_node->parent->left = child;
        }
        else{
            delete_node->parent->right = child;
        }
        delete delete_node;
    }
    return true;
}

template<typename T>
void BinaryTree<T>::Pre_Order(Node<T>* node){
    if(node == nullptr){
        return;
    }
    Node<T>* cur = node;
    cout<< cur->index <<endl;
    Pre_Order(cur->left);
    Pre_Order(cur->right);
}

template<typename T>
void BinaryTree<T>::In_Order(Node<T>* node){
    if(node == nullptr){
        return;
    }
    Node<T>* cur = node;    
    In_Order(cur->left);
    cout<< cur->index <<endl;
    In_Order(cur->right);
}

template<typename T>
void BinaryTree<T>::Post_Order(Node<T>* node){
    if(node == nullptr){
        return;
    }
    Node<T>* cur = node;    
    Post_Order(cur->left);    
    Post_Order(cur->right);
    cout<< cur->index <<endl;
}

template<typename T>
void BinaryTree<T>::Level_Order(Node<T>* node){
    queue<Node<T>*> Q;

    Q.push(node);
    while(!Q.empty()){
        Node<T>* cur = Q.front();
        cout << cur->index << endl;
        Q.pop();
        if (cur->left){
            Q.push(cur->left);
        }
        if (cur->right){
            Q.push(cur->right);
        }
    }
}

template<typename T>
Node<T>* BinaryTree<T>::Left_Most(Node<T>* node){
    if(node==nullptr){
        return nullptr;
    }
    
    while(node->left!=nullptr){
        node = node->left;
    }
    return node;
}

template<typename T>
Node<T>* BinaryTree<T>::Right_Most(Node<T>* node){
    if(node==nullptr){
        return nullptr;
    }

    while(node->right!=nullptr){
        node = node->right;
    }
    return node;
}

template<typename T>
Node<T>* BinaryTree<T>::Predecessor(Node<T>* node){
    if(node->left!=nullptr){
        return Right_Most(node->left);
    }
    Node<T>* cur = node->parent;
    while(cur != nullptr && node == cur->left){
        node = cur;
        cur = node->parent;
    }
    return cur;
}

template<typename T>
Node<T>* BinaryTree<T>::Successor(Node<T>* node){
    if(node->right!=nullptr){
        return Left_Most(node->right);
    }
    Node<T>* cur = node->parent;
    while(cur != nullptr && node == cur->right){
        node = cur;
        cur = node->parent;
    }
    return cur;
}

