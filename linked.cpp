#include <iostream>
using namespace std ;

class linked{

    struct Node
    {
        int data ;
        Node* next ;
    };
    Node* head ;

public: 
    linked() : head(nullptr){}
    void append(int value){
        Node* newNode = new Node ;
        newNode->data = value ;
        newNode->next = nullptr ;

        if (head == nullptr)
        {
            head = newNode ;
            cout << "Empty list, Creating New List.." << endl ;
        }else
        {
            Node* temp = head ;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode ;
        }
        
    }
    void remove(int value){

        if (head == nullptr)
        {
            cout << "No Elements in list, Deletion unsuccessful." << endl ;
            return;
        }

        Node* temp = head ;
        Node* prev = nullptr ;

        if (temp->data == value)
        {
            head = temp->next ;
            delete temp ;
            cout << "Element Deleted successfully." << endl ;
            return ;
        }
        

        while (temp != nullptr && temp->data != value)
        {
            prev = temp ;
            temp = temp->next ;
        }
        
        if (temp == nullptr)
        {
            cout << "Element Not in List, Deletion returned." << endl ;
            return ;
        }
        
        prev->next = temp->next ;
        
    }
    void display(){
        Node* temp = head ; 
        while (temp != nullptr)
        {
            cout << temp->data << " " ;
            temp = temp->next ;
        }
        
    }


};

int main(){

    linked newlist ;

    newlist.append(5) ;
    newlist.append(59) ;
    newlist.append(2) ;
    newlist.append(120) ; 
    newlist.display() ;
    newlist.remove(2) ;
    newlist.display() ;

}
