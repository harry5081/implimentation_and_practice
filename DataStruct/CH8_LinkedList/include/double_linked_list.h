# ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

template <typename T>
struct Node{
    T Data;
    Node *Next;
    Node *Previous;
};
//08_03 14:48
template <typename T>
class Double_Linked_List{
    private:
        Node<T>* First;
        Node<T>* Last;        
    public:
        class Iterator{
            private:
                T* ptr;
            public:
                Iterator(T* = nullptr);
                void operator++(); // ++Iterator
                void operator--(); // --Iterator
                void operator++(int); // Iterator++
                void operator--(int); // Iterator--
                bool operator==(Iterator); //faster by passing reference
                bool operator!=(Iterator); // call by reference does not work why?
                void operator=(Iterator);
                bool operator>(Iterator);
                bool operator>=(Iterator);
                bool operator<(Iterator);
                bool operator<=(Iterator);
                Iterator operator+(int);
                Iterator operator-(int);
                int operator-(Iterator);
                T& operator*();
        };

        Double_Linked_List();
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