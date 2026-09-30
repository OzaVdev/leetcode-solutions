class MyCircularQueue {
    vector<int> queue;
    
    int frontIndex = 0;      
    int elementCount = 0;    
    int capacity;            
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        int insertIndex = (frontIndex + elementCount) % capacity;

        queue[insertIndex] = value;
        elementCount++;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        frontIndex = (frontIndex + 1) % capacity;
        elementCount--;

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return queue[frontIndex];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        int rearIndex = (frontIndex + elementCount - 1) % capacity;

        return queue[rearIndex];
    }

    bool isEmpty() {
        return elementCount == 0;
    }

    bool isFull() {
        return elementCount == capacity;
    }
};