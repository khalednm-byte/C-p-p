#include <iostream>
#include <vector>


class DynamicQueue {
private:
    std::vector<int> arr;

public:
    DynamicQueue() {
        
    }

    bool isEmpty() const {
        return arr.empty();
    }

    void enqueue(int value) {
        arr.push_back(value);
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        arr.erase(arr.begin());
        std::cout << "Queue front served." << std::endl;
    }

    void display_queue() const {
        for (const auto& elem : arr) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicQueue dq;
    dq.enqueue(10);
    dq.enqueue(20);
    dq.enqueue(30);
    dq.display_queue(); 
    dq.dequeue();
    dq.display_queue(); 
    return 0;
}
