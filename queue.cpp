#include <iostream>
using namespace std ;

class queue{

    struct queueStr
    {
        int front = -1 , rear = -1, arr[10];
    };
    typedef queueStr Queue ; 
    typedef int meow ;

public: 
    Queue que ;
    bool isEmpty(){
        if (que.front == -1 && que.rear == -1)
        {
            return true ;
        }
        
        return false ;
    }
    int top(){
        return que.front ;
    }
    int rear(){
        return que.rear ;
    }
    void display_queue(){
        int i ;
        for (i = 0; i <= que.rear; i++)
        {
            cout << que.arr[i] << " " ;
        }
        
    }
    void enqueue(int value) {
    if (que.rear >= 9) {
        cout << "Queue is full!" << endl;
        return;
    }
    if (isEmpty()) {
        que.front = 0; // Initialize front when adding the first element
    }
    que.rear++;
    que.arr[que.rear] = value;
}
    void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    if (que.front == que.rear) {
        // Queue becomes empty after dequeue
        que.front = que.rear = -1;
    } else {
        que.front++;
        cout << "Queue front served." << endl;
    }
}
};

int main(){

    queue que ;

    for (int i = 0; i < 10; i++)
    {
        que.enqueue(i) ;
        cout << que.top() << endl ; 
        cout << que.rear() << endl ; 
    }

    que.display_queue() ;

    for (int i = 0; i < 10; i++) 
    {
        que.dequeue();
        cout << que.top() << endl ; 
        cout << que.rear() << endl ; 
    }

    que.display_queue() ; 
    

}