class MyCircularQueue {
    vector<int> q; int head = 0, cnt = 0, cap;
public:
    MyCircularQueue(int k) : q(k), cap(k) {}
    bool enQueue(int value) {
        if (isFull()) return false;
        q[(head + cnt) % cap] = value; cnt++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % cap; cnt--;
        return true;
    }
    int Front() { return isEmpty() ? -1 : q[head]; }
    int Rear() { return isEmpty() ? -1 : q[(head + cnt - 1) % cap]; }
    bool isEmpty() { return cnt == 0; }
    bool isFull() { return cnt == cap; }
};