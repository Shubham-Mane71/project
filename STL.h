#define STL_H
#include<iostream>
using namespace std;


// Singly LLL
template<class T>
struct node
{
    T data;
    node<T>* next;
};

template<class T>
class SinglyLL
{
public:
    node<T>* first;
    int count;

    SinglyLL()
    {
        first = NULL;
        count = 0;
    }

    void InsertFirst(T no)
    {
        node<T>* newn = new node<T>;
        newn->data = no;
        newn->next = first;
        first = newn;
        count++;
    }

    void InsertLast(T no)
    {
        node<T>* newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            node<T>* temp = first;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        count++;
    }

    void InsertAtPos(T no, int ipos)
    {
        if(ipos < 1 || ipos > count+1) return;
        if(ipos == 1) InsertFirst(no);
        else if(ipos == count+1) InsertLast(no);
        else
        {
            node<T>* newn = new node<T>;
            newn->data = no;
            node<T>* temp = first;
            for(int i = 1; i < ipos-1; i++) temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
            count++;
        }
    }

    void DeleteFirst()
    {
        if(first == NULL) return;
        node<T>* temp = first;
        first = first->next;
        delete temp;
        count--;
    }

    void DeleteLast()
    {
        if(first == NULL) return;
        if(first->next == NULL)
        {
            delete first;
            first = NULL;
        }
        else
        {
            node<T>* temp = first;
            while(temp->next->next != NULL) temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
        count--;
    }

    void DeleteAtPos(int ipos)
    {
        if(ipos < 1 || ipos > count) return;
        if(ipos == 1) DeleteFirst();
        else if(ipos == count) DeleteLast();
        else
        {
            node<T>* temp = first;
            for(int i = 1; i < ipos-1; i++) temp = temp->next;
            node<T>* target = temp->next;
            temp->next = target->next;
            delete target;
            count--;
        }
    }

    void Display()
    {
        node<T>* temp = first;
        cout<<"First -> ";
        while(temp != NULL)
        {
            cout <<"| "<< temp->data << " | -> ";
            temp = temp->next;
        }
        cout << " NULL\n";
    }

    int Count()
    {
        return count;
    }
};

// Singly circular Linked List

template<class T>
struct SCnode
{
    T data;
    SCnode<T>* next;
};

template<class T>
class SinglyCLL
{
public:
    SCnode<T>* first;
    SCnode<T>* last;
    int count;

    SinglyCLL()
    {
        first = NULL;
        last = NULL;
        count = 0;
    }

    void InsertFirst(T no)
    {
        SCnode<T>* newn = new SCnode<T>;
        newn->data = no;
        newn->next = NULL;
        if(first == NULL && last == NULL)
        {
            first = last = newn;
            last->next = first;
        }
        else
        {
            newn->next = first;
            first = newn;
            last->next = first;
        }
        count++;
    }

    void InsertLast(T no)
    {
        SCnode<T>* newn = new SCnode<T>;
        newn->data = no;
        newn->next = NULL;
        if(first == NULL && last == NULL)
        {
            first = last = newn;
            last->next = first;
        }
        else
        {
            last->next = newn;
            last = newn;
            last->next = first;
        }
        count++;
    }

    void InsertAtPos(T no, int ipos)
    {
        if(ipos < 1 || ipos > count+1) return;
        if(ipos == 1) InsertFirst(no);
        else if(ipos == count+1) InsertLast(no);
        else
        {
            SCnode<T>* newn = new SCnode<T>;
            newn->data = no;
            SCnode<T>* temp = first;
            for(int i = 1; i < ipos-1; i++) temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
            count++;
        }
    }

    void DeleteFirst()
    {
        if(first == NULL && last == NULL) return;
        if(first == last)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            SCnode<T>* temp = first;
            first = first->next;
            delete temp;
            last->next = first;
        }
        count--;
    }

    void DeleteLast()
    {
        if(first == NULL && last == NULL) return;
        if(first == last)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            SCnode<T>* temp = first;
            while(temp->next != last) temp = temp->next;
            delete last;
            last = temp;
            last->next = first;
        }
        count--;
    }

    void DeleteAtPos(int ipos)
    {
        if(ipos < 1 || ipos > count) return;
        if(ipos == 1) DeleteFirst();
        else if(ipos == count) DeleteLast();
        else
        {
            SCnode<T>* temp = first;
            for(int i = 1; i < ipos-1; i++) temp = temp->next;
            SCnode<T>* target = temp->next;
            temp->next = target->next;
            delete target;
            count--;
        }
    }

    void Display()
    {
        if(first == NULL) return;
        SCnode<T>* temp = first;
        cout<<"First -> ";
        do
        {
            cout <<"| "<< temp->data << " | -> ";
            temp = temp->next;
        } while(temp != first);
        cout << " Head\n";
    }

    int Count()
    {
        return count;
    }
};

// Doubly Linear LL

template<class T>
struct dnode
{
    T data;
    dnode<T>* next;
    dnode<T>* prev;
};

template<class T>
class DoublyLL
{
public:
    dnode<T>* first;
    int count;

    DoublyLL()
    {
        first = NULL;
        count = 0;
    }

    void InsertFirst(T no)
    {
        dnode<T>* newn = new dnode<T>;
        newn->data = no;
        newn->next = first;
        newn->prev = NULL;
        if(first != NULL) first->prev = newn;
        first = newn;
        count++;
    }

    void InsertLast(T no)
    {
        dnode<T>* newn = new dnode<T>;
        newn->data = no;
        newn->next = NULL;
        if(first == NULL)
        {
            newn->prev = NULL;
            first = newn;
        }
        else
        {
            dnode<T>* temp = first;
            while(temp->next != NULL) temp = temp->next;
            temp->next = newn;
            newn->prev = temp;
        }
        count++;
    }

    void InsertAtPos(T no, int ipos)
    {
        if(ipos < 1 || ipos > count+1) return;
        if(ipos == 1) InsertFirst(no);
        else if(ipos == count+1) InsertLast(no);
        else
        {
            dnode<T>* newn = new dnode<T>;
            newn->data = no;
            dnode<T>* temp = first;
            for(int i = 1; i < ipos-1; i++) temp = temp->next;
            newn->next = temp->next;
            newn->prev = temp;
            temp->next->prev = newn;
            temp->next = newn;
            count++;
        }
    }

    void DeleteFirst()
    {
        if(first == NULL) return;
        if(first->next == NULL)
        {
            delete first;
            first = NULL;
        }
        else
        {
            dnode<T>* temp = first;
            first = first->next;
            first->prev = NULL;
            delete temp;
        }
        count--;
    }

    void DeleteLast()
    {
        if(first == NULL) return;
        if(first->next == NULL)
        {
            delete first;
            first = NULL;
        }
        else
        {
            dnode<T>* temp = first;
            while(temp->next != NULL) temp = temp->next;
            temp->prev->next = NULL;
            delete temp;
        }
        count--;
    }

    void DeleteAtPos(int ipos)
    {
        if(ipos < 1 || ipos > count) return;
        if(ipos == 1) DeleteFirst();
        else if(ipos == count) DeleteLast();
        else
        {
            dnode<T>* temp = first;
            for(int i = 1; i < ipos; i++) temp = temp->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            count--;
        }
    }

    void Display()
    {
        dnode<T>* temp = first;
        cout<<"Last -> ";
        while(temp != NULL)
        {
            cout <<"| "<< temp->data << " | -> ";
            temp = temp->next;
        }
        cout << "Head\n";
    }

    int Count()
    {
        return count;
    }
};

//Doubly Circular LL

template<class T>
struct DCnode
{
    T data;
    DCnode<T>* next;
    DCnode<T>* prev;
};

template<class T>
class DoublyCLL
{
public:
    DCnode<T>* first;
    int count;

    DoublyCLL()
    {
        first = NULL;
        count = 0;
    }

    void InsertFirst(T no)
    {
        DCnode<T>* newn = new DCnode<T>;
        newn->data = no;
        if(first == NULL)
        {
            first = newn;
            newn->next = newn;
            newn->prev = newn;
        }
        else
        {
            DCnode<T>* last = first->prev;
            newn->next = first;
            newn->prev = last;
            last->next = newn;
            first->prev = newn;
            first = newn;
        }
        count++;
    }

    void InsertLast(T no)
    {
        DCnode<T>* newn = new DCnode<T>;
        newn->data = no;
        if(first == NULL)
        {
            first = newn;
            newn->next = newn;
            newn->prev = newn;
        }
        else
        {
            DCnode<T>* last = first->prev;
            last->next = newn;
            newn->prev = last;
            newn->next = first;
            first->prev = newn;
        }
        count++;
    }

    void InsertAtPos(T no, int ipos)
    {
        if(ipos < 1 || ipos > count+1) return;
        if(ipos == 1) InsertFirst(no);
        else if(ipos == count+1) InsertLast(no);
        else
        {
            DCnode<T>* newn = new DCnode<T>;
            newn->data = no;
            DCnode<T>* temp = first;
            for(int i = 1; i < ipos-1; i++) temp = temp->next;
            newn->next = temp->next;
            newn->prev = temp;
            temp->next->prev = newn;
            temp->next = newn;
            count++;
        }
    }

    void DeleteFirst()
    {
        if(first == NULL) return;
        if(first->next == first)
        {
            delete first;
            first = NULL;
        }
        else
        {
            DCnode<T>* last = first->prev;
            DCnode<T>* temp = first;
            first = first->next;
            last->next = first;
            first->prev = last;
            delete temp;
        }
        count--;
    }

    void DeleteLast()
    {
        if(first == NULL) return;
        if(first->next == first)
        {
            delete first;
            first = NULL;
        }
        else
        {
            DCnode<T>* last = first->prev;
            DCnode<T>* pl = last->prev;
            pl->next = first;
            first->prev = pl;
            delete last;
        }
        count--;
    }

    void DeleteAtPos(int ipos)
    {
        if(ipos < 1 || ipos > count) return;
        if(ipos == 1) DeleteFirst();
        else if(ipos == count) DeleteLast();
        else
        {
            DCnode<T>* temp = first;
            for(int i = 1; i < ipos; i++) temp = temp->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            count--;
        }
    }

    void Display()
    {
        if(first == NULL) return;
        DCnode<T>* temp = first;
        cout<<"Last -> ";
        do
        {
            cout <<"| "<< temp->data << " | -> ";
            temp = temp->next;
        } while(temp != first);
        cout << "head\n";
    }

    int Count()
    {
        return count;
    }
};

// Stack
template<class T>
struct stnode
{
    T data;
    stnode<T>* next;
};

template<class T>
class Stack
{
public:
    stnode<T>* top;
    int count;

    Stack()
    {
        top = NULL;
        count = 0;
    }

    void Push(T no)
    {
        stnode<T>* newn = new stnode<T>;
        newn->data = no;
        newn->next = top;
        top = newn;
        count++;
    }

    void Pop()
    {
        if(top == NULL) return;
        stnode<T>* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    T TopElement()
    {
        if(top == NULL) return -1; 
        return top->data;
    }

    bool IsEmpty()
    {
        return top == NULL;
    }

    int Count()
    {
        return count;
    }

    void Display()
    {
        stnode<T>* temp = top;
        cout<<"top -> ";
        while(temp != NULL)
        {
            cout <<"| "<< temp->data << " | -> ";
            temp = temp->next;
        }
        cout << "\n";
    }
};


// Queue
template<class T>
struct qnode
{
    T data;
    qnode<T>* next;
};

template<class T>
class Queue
{
public:
    qnode<T>* front;
    qnode<T>* rear;
    int count;

    Queue()
    {
        front = rear = NULL;
        count = 0;
    }

    void Enqueue(T no)
    {
        qnode<T>* newn = new qnode<T>;
        newn->data = no;
        newn->next = NULL;
        if(rear == NULL)
        {
            front = rear = newn;
        }
        else
        {
            rear->next = newn;
            rear = newn;
        }
        count++;
    }

    void Dequeue()
    {
        if(front == NULL) return;
        qnode<T>* temp = front;
        front = front->next;
        if(front == NULL) rear = NULL;
        delete temp;
        count--;
    }

    T FrontElement()
    {
        if(front == NULL) return -1;
        return front->data;
    }

    bool IsEmpty()
    {
        return front == NULL;
    }

    int Count()
    {
        return count;
    }

    void Display()
    {
        qnode<T>* temp = front;
        cout<<"front -> ";
        while(temp != NULL)
        {
            cout <<"| "<< temp->data << " | -> ";
            temp = temp->next;
        }
        cout << "Rear\n";
    }
};