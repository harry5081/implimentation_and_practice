#include <linked_list.h>
#include <iostream>

template<typename T>
Linked_List<T>::Linked_List(){
    First = nullptr;
}

template<typename T>
void Linked_List<T>::Print_List(){
    if(First == nullptr){
        std::cout<< "The linked list is empty"<<std::endl;
        return;
    }

    Node<T> *ptr_tmp = First;
    while(ptr_tmp != nullptr){
        std::cout<< ptr_tmp-> Data << " ";
        ptr_tmp = ptr_tmp->Next;
    }

    std::cout<<std::endl;
}

template<typename T>
int Linked_List<T>::Search_List(T target_value){
    int index = 0;
    Node<T> *ptr_tmp = First;
    
    while(ptr_tmp != nullptr){
        if(ptr_tmp->Data == target_value){
            return index;
        }
        index++;
        ptr_tmp = ptr_tmp->Next;
    }
    return -1;
}

template<typename T>
void Linked_List<T>::Insert(int Index, T value){

    Node<T> *new_node_ptr;
    new_node_ptr = new Node<T>;
    new_node_ptr->Data = value;

    Node<T> *ptr_tmp = First;
    int index_tmp = 0;
    while(index_tmp < Index-1){
        std::cout<<ptr_tmp->Data<< " ";
        ptr_tmp = ptr_tmp->Next;
        index_tmp++;
    }
    std::cout<<std::endl;
    std::cout<<ptr_tmp->Data<<std::endl;
    new_node_ptr->Next = ptr_tmp->Next;
    ptr_tmp->Next=new_node_ptr;
}

template<typename T>
void Linked_List<T>::Insert_Start(T value){
    // Node<T> *new_node_ptr;
    // new_node_ptr = new Node<T>;
    // new_node_ptr->Data = value;

    // new_node_ptr->Next = First;
    // First = new_node_ptr;

    Node<T> *new_node_ptr= new Node<T>{value, First};
    First = new_node_ptr;
}

template<typename T>
void Linked_List<T>::Insert_End(T value){

    if(First == nullptr){
        Insert_Start(value);
        return;
    }

    Node<T> *ptr_tmp = First;
    while(ptr_tmp->Next != nullptr){
        ptr_tmp = ptr_tmp->Next;
    }

    ptr_tmp->Next = new Node<T>{value, nullptr};
}

template<typename T>
void Linked_List<T>::Remove_Start(){
    if(First == nullptr){
        return;
    }
    Node<T> *ptr_tmp = First;
    First = First->Next;
    delete ptr_tmp;
}

template<typename T>
void Linked_List<T>::Remove_End(){
    if(First == nullptr){
        return;
    }

    Node<T> *ptr_tmp = First;
    if(ptr_tmp->Next == nullptr){
        // only one data in linked list
        delete First;
        First = nullptr;
        return;
    }
    while(ptr_tmp->Next->Next != nullptr){
        ptr_tmp = ptr_tmp->Next;
    }
    // ptr_tmp is the last second node
    // ptr_tmp->Next is the last node
    // ptr_tmp->Next->Next is nullptr

    delete ptr_tmp->Next;
    ptr_tmp->Next = nullptr;
}

template<typename T>
void Linked_List<T>::Clear(){
    Node<T> *ptr_tmp = First;
    while(First != nullptr){
        First = First->Next;
        delete ptr_tmp;
        ptr_tmp = First;
    }    
}

template<typename T>
void Linked_List<T>::Reverse(){
    if(First == nullptr){
        // emtpy linked list
        return;
    }
    if(First->Next == nullptr){
        // there is only one node, reversing is the same
        return;
    }
    
    Node<T> *previous_ptr = nullptr;
    Node<T> *current_ptr = First;
    Node<T> *preceding_ptr = current_ptr->Next;
    
    while(preceding_ptr != nullptr){
        current_ptr->Next = previous_ptr;
        previous_ptr = current_ptr;
        current_ptr = preceding_ptr;
        preceding_ptr = preceding_ptr->Next;
    }
    First = current_ptr;
    current_ptr->Next = previous_ptr;
    
}
   
    

