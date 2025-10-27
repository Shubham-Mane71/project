#include<iostream>
#include "STL.h"
using namespace std;

/////////////////////// Singly Linear Linked List ///////////////////////
void SinglyLLMenu()
{
    SinglyLL<int> sll;
    int ch, val, pos;

    while (true)
    {
        cout << "\n----- Singly Linked List (int) -----\n";
        cout << "1. Insert First\n2. Insert Last\n3. Insert At Position\n";
        cout << "4. Delete First\n5. Delete Last\n6. Delete At Position\n";
        cout << "7. Display\n8. Count\n0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1: cout << "Enter value: "; cin >> val; sll.InsertFirst(val); break;
        case 2: cout << "Enter value: "; cin >> val; sll.InsertLast(val); break;
        case 3: cout << "Enter value & position: "; cin >> val >> pos; sll.InsertAtPos(val, pos); break;
        case 4: sll.DeleteFirst(); break;
        case 5: sll.DeleteLast(); break;
        case 6: cout << "Enter position: "; cin >> pos; sll.DeleteAtPos(pos); break;
        case 7: sll.Display(); break;
        case 8: cout << "Node Count: " << sll.Count() << endl; break;
        case 0: return;
        default: cout << "Invalid choice!\n";
        }
    }
}

////////////////////// Singly Circular Linked List //////////////////////
void SinglyCLLMenu()
{
    SinglyCLL<int> scll;
    int ch, val, pos;

    while (true)
    {
        cout << "\n----- Singly Circular Linked List (int) -----\n";
        cout << "1. Insert First\n2. Insert Last\n3. Insert At Position\n";
        cout << "4. Delete First\n5. Delete Last\n6. Delete At Position\n";
        cout << "7. Display\n8. Count\n0. Back\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1: 
            cout << "Enter value: "; cin >> val; 
            scll.InsertFirst(val); 
            break;
        case 2: 
            cout << "Enter value: "; 
            cin >> val; scll.InsertLast(val); 
            break;
        case 3: 
            cout << "Enter value & pos: "; 
                cin >> val >> pos; scll.InsertAtPos(val, pos); 
                break;
        case 4: 
            scll.DeleteFirst(); 
            break;
        case 5: 
            scll.DeleteLast(); 
            break;
        case 6: 
            cout << "Enter position: "; 
            cin >> pos; scll.DeleteAtPos(pos); 
            break;
        case 7: 
            scll.Display(); 
            break;
        case 8: 
            cout << "Count: " << scll.Count() << endl; 
            break;
        case 0: 
            return;
        default: 
            cout << "Invalid!\n";
        }
    }
}

///////////////////// Doubly Linear Linked List ///////////////////////
void DoublyLLMenu()
{
    DoublyLL<int> dll;
    int ch, val, pos;

    while (true)
    {
        cout << "\n----- Doubly Linked List (int) -----\n";
        cout << "1. Insert First\n2. Insert Last\n3. Insert At Position\n";
        cout << "4. Delete First\n5. Delete Last\n6. Delete At Position\n";
        cout << "7. Display\n8. Count\n0. Back\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1: cin >> val; dll.InsertFirst(val); break;
        case 2: cin >> val; dll.InsertLast(val); break;
        case 3: cin >> val >> pos; dll.InsertAtPos(val, pos); break;
        case 4: dll.DeleteFirst(); break;
        case 5: dll.DeleteLast(); break;
        case 6: cin >> pos; dll.DeleteAtPos(pos); break;
        case 7: dll.Display(); break;
        case 8: cout << "Count: " << dll.Count() << endl; break;
        case 0: return;
        default: cout << "Invalid!\n";
        }
    }
}

////////////////////// Doubly Circular Linked List ///////////////////////
void DoublyCLLMenu()
{
    DoublyCLL<int> dcll;
    int ch, val, pos;

    while (true)
    {
        cout << "\n----- Doubly Circular Linked List (int) -----\n";
        cout << "1. Insert First\n2. Insert Last\n3. Insert At Position\n";
        cout << "4. Delete First\n5. Delete Last\n6. Delete At Position\n";
        cout << "7. Display\n8. Count\n0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            dcll.InsertFirst(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            dcll.InsertLast(val);
            break;
        case 3:
            cout << "Enter value & position: ";
            cin >> val >> pos;
            dcll.InsertAtPos(val, pos);
            break;
        case 4:
            dcll.DeleteFirst();
            break;
        case 5:
            dcll.DeleteLast();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            dcll.DeleteAtPos(pos);
            break;
        case 7:
            dcll.Display();
            break;
        case 8:
            cout << "Count: " << dcll.Count() << "\n";
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}

////////////////////// Stack ///////////////////////
void StackMenu()
{
    Stack<int> st;
    int ch, val;
    while (true)
    {
        cout << "\n----- Stack (int) -----\n";
        cout << "1. Push\n2. Pop\n3. Top Element\n4. Display\n5. Count\n0. Back\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1: cin >> val; st.Push(val); break;
        case 2: st.Pop(); break;
        case 3: cout << "Top: " << st.TopElement() << endl; break;
        case 4: st.Display(); break;
        case 5: cout << "Count: " << st.Count() << endl; break;
        case 0: return;
        default: cout << "Invalid!\n";
        }
    }
}

////////////////////// Queue ///////////////////////
void QueueMenu()
{
    Queue<int> q;
    int ch, val;
    while (true)
    {
        cout << "\n----- Queue (int) -----\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Front Element\n4. Display\n5. Count\n0. Back\n";
        cin >> ch;

        switch (ch)
        {
        case 1: cin >> val; q.Enqueue(val); break;
        case 2: q.Dequeue(); break;
        case 3: cout << "Front: " << q.FrontElement() << endl; break;
        case 4: q.Display(); break;
        case 5: cout << "Count: " << q.Count() << endl; break;
        case 0: return;
        }
    }
}

int main()
{
    int choice = 0;
    while (true)
    {
        cout << "\n================ Data Structure Menu ================\n";
        cout << "1. Singly Linear Linked List\n";
        cout << "2. Singly Circular Linked List\n";
        cout << "3. Doubly Linear Linked List\n";
        cout << "4. Doubly Circular Linked List\n";
        cout << "5. Stack\n";
        cout << "6. Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: SinglyLLMenu(); break;
        case 2: SinglyCLLMenu(); break;
        case 3: DoublyLLMenu(); break;
        case 4: DoublyCLLMenu(); break;
        case 5: StackMenu(); break;
        case 6: QueueMenu(); break;
        case 0: cout << "\nExiting..."; return 0;
        default: cout << "\nInvalid choice! Try again.\n";
        }
    }
}