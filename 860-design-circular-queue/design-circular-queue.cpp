class MyCircularQueue {
    vector<int> q;
    int front = 0, rear = 0, count = 0, capacity;

public:
    MyCircularQueue(int k) : q(k), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;

        q[rear] = value;
        rear = (rear + 1) % capacity;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    int Front() {
        return isEmpty() ? -1 : q[front];
    }

    int Rear() {
        return isEmpty() ? -1 : q[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};