
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Queue {
private:
    queue<T> data; // underlying data structure

public:
    void enqueue(const T& element) {
        data.push(element); // Inserts a new element at the rear of the queue.
    }

    T dequeue() {
        T frontElement = data.front(); // Stores the front element to return later.
        data.pop(); // Removes the front element of the queue.
        return frontElement;
    }

    T front() {
        return data.front(); // Returns the front element present in the queue without removing it.
    }

    bool isEmpty() {
        return data.empty(); // Checks if the queue is empty.
    }

    int size() {
        return data.size(); // Returns the total number of elements present in the queue.
    }
};
