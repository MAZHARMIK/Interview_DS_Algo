/*
    Company Tags  : Google, Facebook, Apple, Goldman Sachs, Amazon
    Leetcode Link : https://leetcode.com/problems/design-circular-queue/
*/

class MyCircularQueue {
public:
    vector<int> que;
    int n;
    int len;
    int front, rear;
    MyCircularQueue(int k) {
        que   = vector<int>(k);
        n     = k;
        len   = 0;
        front = 0;
        rear  = -1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        rear = (rear+1)%n;
        len++;
        que[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        front = (front+1)%n;
        len--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : que[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : que[rear];
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == n;
    }
};
