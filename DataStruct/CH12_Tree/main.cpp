#include <iostream>

#include "binary_tree.h"
#include "src/binary_tree.cpp"

using namespace std;

int main(){

    BinaryTree<string> first_tree;
    first_tree.Insert(58, "H");
    first_tree.Insert(24, "B");
    first_tree.Insert(97, "HAHA");
    first_tree.Insert(12, "HAHA");
    first_tree.Insert(49, "HAHA");
    
    Node<string>* found = first_tree.Search(12);
    first_tree.Print(*found);

    first_tree.Pre_Order(first_tree.root);
    cout<< "---"<< endl;
    first_tree.In_Order(first_tree.root);
    cout<< "---"<< endl;
    first_tree.Post_Order(first_tree.root);
    cout<< "---"<< endl;
    first_tree.Level_Order(first_tree.root);

    cout<< "---"<< endl;
    cout<<first_tree.Left_Most(first_tree.root)->index<< endl;
    cout<<first_tree.Right_Most(first_tree.root)->index<< endl;
    cout<<first_tree.Predecessor(first_tree.Search(58))->index<< endl;
    cout<<first_tree.Successor(first_tree.Search(58))->index<< endl;
    cout<< "---"<< endl;
    first_tree.Delete(58);
    first_tree.In_Order(first_tree.root);
    
    return 0;


}