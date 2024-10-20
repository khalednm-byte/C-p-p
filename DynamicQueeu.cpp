#include <iostream>
#include <vector>

/*
    *This is an AI generated code by - Copilot
*/

class DynamicQueue {
private:
    std::vector<int> arr;

public:
    DynamicQueue() {
        // Initialize an empty queue
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
    dq.display_queue(); // Output: 10 20 30
    dq.dequeue();
    dq.display_queue(); // Output: 20 30
    return 0;
}
