class MyCircularQueue {
    int q[1000];
    int front = 0;
    int rear = 0;
    int size = 0;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
    }

    bool enQueue(int value) {
        if (size == capacity)
            return false;

        q[rear] = value;
        rear = (rear + 1) % capacity;
        size++;

        return true;
    }

    bool deQueue() {
        if (size == 0)
            return false;

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    int Front() {
        return size == 0 ? -1 : q[front];
    }

    int Rear() {
        return size == 0 ? -1 : q[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};