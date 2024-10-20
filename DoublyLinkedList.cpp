#include <iostream> 
using namespace std ; 

class DoublyLinkedList {

    struct Node
    {
        int data ;
        Node* next ;
        Node* prev ; // makes it a Doubly Linked List

        // struct constructer
        Node(){
            prev = nullptr ;
            next = nullptr ;
        }

    };

    Node* head ;
    
public: 
    DoublyLinkedList() : head(nullptr) {

    }
    void append(int value){
        Node* newNode = new Node; 
        newNode->data = value ;
        // newNode->next = nullptr ;
        // newNode->prev = nullptr ;

        if (head == nullptr)
        {
            cout << "New list Created!" << endl ;
            head = newNode ;
            return ;
        }else
        {
            Node* temp = head; 
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode ;
            newNode->prev = temp ;
            cout << "Value appended to list!" << endl ;
        }
        
        

    }
    void remove(int value) {
    if (head == nullptr) {
        cout << "Empty List, Remove Returned." << endl;
        return;
    }

    Node* temp = head;

    if (temp->data == value) {
        head = temp->next;
        if (head != nullptr)
        {
            head->prev = nullptr ;
        }
        delete temp;
        cout << "Element Removed!" << endl;
        return;
    }

    while (temp->next != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Element isn't in list." << endl;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    cout << "Element Removed!" << endl;
}

    void insertAt(int value, int pos){
        Node* newNode = new Node;
        newNode->data = value ;

        if (head == nullptr)
        {
            cout << "Inserting into an Empty list." ;
            head = newNode ;
            return ;
        }

        if (pos == 0)
        {
            newNode->next = head ;
            head->prev = newNode ;
            head = newNode ;
            cout << "Insert Completed." << endl ;
            return ;
        }

        Node* temp = head ;

        for (int i = 0; i < pos - 1 && temp != nullptr && temp->next != nullptr; i++)
        {
            temp = temp->next ;
        }

        newNode->next = temp->next ;
        temp->next = newNode ;   
        newNode->prev = temp ;
        if (newNode->next != nullptr)
        {
            newNode->next->prev = newNode ;
        }
        cout << "Insert Completed." << endl ;
    }
    void removeAt(int pos){}
    void print_list(){
        Node* temp = head ;
        while (temp != nullptr)
        {
            cout << "List: " << temp->data << " " ;
            temp = temp->next ; // to get the loop to end
        }
    }
};


int main(){

    DoublyLinkedList list ;

    list.append(2) ;
    list.print_list(); 
    list.remove(2) ;
    cout << "\n" ;
    list.print_list();
    list.append(4); 
    list.append(44); 
    list.append(444); 
    list.append(4444); 
    list.print_list();
    //list.remove(4) ;
    //list.remove(44) ;
    list.insertAt(7, 1) ;
    //list.remove(444) ;
    //list.remove(4444) ;
    //list.remove(44) ;
    list.append(5);
    list.remove(7) ;
    list.print_list();


}