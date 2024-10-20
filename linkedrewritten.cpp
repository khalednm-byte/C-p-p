#include <iostream>
using namespace std;

/*
This code is written again by me. 
for Practice purposes. 
*/

class linked{

    struct Node
    {
        int data ;
        Node* next;
    };
    Node* head; 

public:
    linked() : head(nullptr) {}
    void append(int value){

        Node* newNode = new Node;
        newNode->data = value ;
        newNode->next = NULL ;

        if (head == nullptr)
        {
            head = newNode ;
            cout << "No Nodes Found, Creaing new List, Appending " << value << endl ;
        }else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            cout << "Nodes Found, Appending " << value << " started..." << endl ;
        }
        
        
    }
    void remove(int value) {
        
        if (head == nullptr)
        {
            cout << "Empty list, Remove rejected." << endl ;
            return ;
        }

        Node* temp = head ;
        Node* prev = nullptr ;

        if (temp->data == value)
        {
            head = temp->next ;
            delete temp ;
            return;
        }

        while (temp != nullptr && temp->data != value)
        {
            prev = temp ;
            temp = temp->next ;
        }

        if (temp == nullptr)
        {
            cout << "Value not present in list, " << value << " Remove Terminated!" << endl ;
            return ;
        }
        
        prev->next = temp->next ;
        
        
    }
    void display(){
        if (head == nullptr)
        {
            cout << "List's Empty!" << endl ;
            return ;
        }else
        {
            Node* temp = head ;
            while (temp != nullptr)
            {
                cout << "List " << temp->data << " " ;
                temp = temp->next ;
            }
            
        }
        
        
    }
    void insertAt(int value, int position){
        Node* insertedNode = new Node ;
        insertedNode->data = value ;
        insertedNode->next = nullptr ;

        if (position == 0)
        {
            head = insertedNode ;
            insertedNode->next = head ;
            return ;
        }

        Node* temp = head ;

        for (int i = 0; i < position - 1 && temp->next != nullptr; i++)
        {
            temp = temp->next ;
        }
        
        insertedNode->next = temp->next ;
        temp->next = insertedNode ;
        
    }
    // More Methods go here..

};


int main(){
    linked list ;

    list.append(5);
    list.append(10);
    list.append(3);
    
    list.insertAt(19, 0);
    list.display();

}