#include <iostream>
using namespace std;

class LinkedLists {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    LinkedLists() : head(nullptr) { // Using member initializer list
    }
    void append(int value) {
        Node* newNode = new Node;
        newNode->data = value; // Correct usage
        newNode->next = nullptr; // Correct usage

        if (head == nullptr) {
            head = newNode;
            cout << "No Nodes Found, Creating new list..." << endl;
        } else {
            cout << "Nodes Found, appending to list..." << endl;
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void insertAt(int value, int position) {
        Node* newNode = new Node ;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            cout << "Empty list, Append a value first!" << endl ;
            return ;
        }
        

        if (position == 0)
        {
            newNode->next = head ;
            head = newNode ;
            return ;
        }

        Node* temp = head ;

        for (int i = 0; i < position - 1 && temp->next !=  nullptr; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next ; // finish lines
        temp->next = newNode ; // finish lines

    }
    void remove(int value) {
        if (head == nullptr)
        {
            cout << "Deletion unsuccessful, Empty List." << endl;
            return ; // otherwise program won't continue
        }

        Node* temp = head;
        Node* prev = nullptr;

        if (temp->data == value)
        {
            head = temp->next ; // or head->next 
            delete temp;
            return ; // otherwise program won't continue
        }

        while (temp != nullptr && temp->data != value)
        {
            prev = temp; // to keep it on track of the previous 'temp' node
            temp = temp->next; // then move to the next node
        }
        
        if (temp == nullptr)
        {
            cout << "Element Not Present in List. Deletion Terminated.." << endl ;
            return ; // otherwise program won't continue
        }
        
        // finish lines
        prev->next = temp->next ;// Unlink the node from linked list
        
    }
    void display() {
        Node* temp = head ;
        while (temp != nullptr)
        {
            cout << "List: " << temp->data << " " ;
            temp = temp->next ; // to get the loop to end
        }
        
    }
    void removeAt(int position){
        if (head == nullptr)
        {
            cout << "Empty List, Remove Terminated." << endl ;
            return; 
        }

        if (position == 0) // always keep in this order 
        {
            Node* temp = head ;
            head = head->next ;
            delete temp ;
            return ;
        }else
        {
            Node* temp = head ;
            for (int i = 0; i < position - 1 && temp->next != nullptr && temp != nullptr; i++)
            {
                temp = temp->next ;
            }
            
            if (temp->next == nullptr)
            {
                return ;
            }
            
            // finish lines
            Node* temp2 = temp->next ;
            temp->next = temp2->next ; // or temp->next->next ; either way it's the same
            delete temp2 ;
        }
        
        
        
    }
    void reverseList(){
        if (head == nullptr)
        {
            cout << "Empty List." ;
            return ;
        }

        Node* temp = head ;
        Node* prev = nullptr;
        Node* next = nullptr; 

        while (temp != nullptr) // Must be in this Order
        {
            next = temp->next ; // 1
            temp->next = prev ; // 2
            prev = temp ; // 3
            temp = next ; // 4
        }

        // final lines
        head = prev ;       
    }
    // space for future functions
};

int main() {
    LinkedLists newList;
    int input; 
    cout << "Choose an operation: [1] Append value [2] Remove value [3] insert at position [4] Remove at position [5] Display list [6] Reverse list [0] Exit" << endl ;
    cin >> input ;
    while (true)
    {

        if (input == 1)
        {
            int value;
            cout << "Enter the value you want to append: " << endl ;
            cin >> value ;
            newList.append(value) ;
        }else if(input == 2){
            int value;
            cout << "Enter the value you want to remove: " << endl ;
            cin >> value ;
            newList.remove(value) ;
        }else if(input == 3){
            int value, position;
            cout << "Enter Position: " << endl ;
            cin >> position ;
            cout << "Enter value: " << endl ;
            cin >> value ;
            newList.insertAt(value, position) ;
        }else if(input == 4){
            int value ;
            cout << "Enter the desired position: " << endl ;
            cin >> value ;
            newList.removeAt(value) ;
        }else if (input == 5)
        {
            newList.display() ;
        }else if (input == 6)
        {
            cout << "Reversing the list.." << endl ;
            newList.reverseList(); 
            newList.display();
        }
        
        else if(input == 0){
            cout << "Terminating.." ;
            break;
        }else
        {
            cout << "Invalid Input!" << endl ;
        }
        
        cout << endl << "Choose an operation: [1] Append value [2] Remove value [3] insert at position [4] Remove at position [5] Display list [6] Reverse list [0] Exit" << endl ;
        cin >> input ;
    }
    
    
}
