# ifndef LINKED_LIST_H
# define LINKED_LIST_H

template <typename T>
struct Node{
    T Data;
    Node *Next;
};

template <typename T>
class Linked_List{
    private:
        Node<T>* First;
        
    public:
        Linked_List();
        void Print_List();
        int Search_List(T);

        void Insert(int index, T data);
        void Insert_Start(T data);
        void Insert_End(T data);

        void Remove(int index);
        void Remove_Start();
        void Remove_End();

        void Clear();
        void Reverse();
};
#endif