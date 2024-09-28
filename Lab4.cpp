// Mehrabani, Siavash
// CS136, Lab4 Queue by Object

#include <iostream>
#include <stdexcept>
using namespace std;

struct Laptop {
    string brand;
    int ram;
    double price;
};

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* frontNode;
    Node* rearNode;
    
public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Add to the back
    void enqueue(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            frontNode = newNode;
        } else {
            rearNode->next = newNode;
        }
        rearNode = newNode;
    }

    // Remove from the front
    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        delete temp;
    }

    // View the front of the queue
    const T& peek() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return frontNode->data;
    }

    // Check if queue is empty
    bool isEmpty() const {
        return frontNode == nullptr;
    }

    // Print Queue
    void print() const {
        Node* current = frontNode;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    
    // Test with int
    Queue<int> intQueue;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    cout << "Front element: " << intQueue.peek() << endl;
    intQueue.dequeue();
    cout << "Front element after dequeue: " << intQueue.peek() << endl;

    // Test with double
    Queue<double> doubleQueue;
    doubleQueue.enqueue(1.1);
    doubleQueue.enqueue(2.2);
    doubleQueue.enqueue(3.3);
    cout << "Front element: " << doubleQueue.peek() << endl;

    // Test with string
    Queue<string> stringQueue;
    stringQueue.enqueue("Alice");
    stringQueue.enqueue("Bob");
    stringQueue.enqueue("Charlie");
    cout << "Front element: " << stringQueue.peek() << endl;

    // Test with structure (Laptop)
    Queue<Laptop> laptopQueue;
    Laptop l1 = { "Dell", 16, 1200.00 };
    Laptop l2 = { "Apple", 32, 2500.00 };
    laptopQueue.enqueue(l1);
    laptopQueue.enqueue(l2);
    cout << "Front laptop brand: " << laptopQueue.peek().brand << endl;
    cout << "Front laptop RAM: " << laptopQueue.peek().ram << " GB" << endl;
    cout << "Front laptop price: $" << laptopQueue.peek().price << endl;

    return 0;
}
