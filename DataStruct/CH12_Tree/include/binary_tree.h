# ifndef BINARY_TREE_H
# define BINARY_TREE_H

template<typename T>
struct Node{
    int index;
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
};

template<typename T>
class BinaryTree{
public:
    Node<T>* root;
    BinaryTree();
    void Print(Node<T>);
    bool Insert(int ,T);
    Node<T>* Search(int);
    bool Delete(int);

    void Pre_Order(Node<T>*);
    void In_Order(Node<T>*);
    void Post_Order(Node<T>*);
    void Level_Order(Node<T>*);

    Node<T>* Left_Most(Node<T>*);
    Node<T>* Right_Most(Node<T>*);
    Node<T>* Predecessor(Node<T>*);
    Node<T>* Successor(Node<T>*);

};

#endif