#include <iostream>
#include "functions.h"

int main() {
    Queue<int> myQueue;

    int choice;
    int value;

    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Enqueue element" << endl;
        cout << "2. Dequeue element" << endl;
        cout << "3. Get front element" << endl;
        cout << "4. Check if the queue is empty" << endl;
        cout << "5. Get the total number of elements in the queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> value;
                myQueue.enqueue(value);
                cout << "Element enqueued." << endl;
                break;
            case 2:
                if (!myQueue.isEmpty()) {
                    value = myQueue.dequeue();
                    cout << "Dequeued element: " << value << endl;
                } else {
                    cout << "The queue is empty." << endl;
                }
                break;
            case 3:
                if (!myQueue.isEmpty()) {
                    value = myQueue.front();
                    cout << "Front element: " << value << endl;
                } else {
                    cout << "The queue is empty." << endl;
                }
                break;
            case 4:
                cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 5:
                cout << "Total elements in the queue: " << myQueue.size() << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }
}
