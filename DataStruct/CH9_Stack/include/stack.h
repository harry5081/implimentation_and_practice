# ifndef STACK_H
# define STACK_H

template<typename T>
class Stack{
    private:
        int Capacity;
        int Top_Index;
        T* Pointer;
        void Double_Capacity();
    public:
        Stack(int=0);
        bool Empty();
        int Size();
        T Top();
        void Push(T);
        void Pop();
        void Print_Stack();
};

#endif