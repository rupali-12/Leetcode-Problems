class MyCircularDeque {
public:
    int maxSize;
    deque<int>dq;
    
    MyCircularDeque(int k) {
        maxSize = k;    
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
         if(isFull()) return false;
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
         if(isEmpty()) return false;
        dq.pop_front();
        return true;
    }
    
    bool deleteLast() {
         if(isEmpty()) return false;
        dq.pop_back();
        return true; 
    }
    
    int getFront() {
        if(!isEmpty()) return dq.front();
        return -1;
    }
    
    int getRear() {
        if(!isEmpty()) return dq.back();
        return -1;
    }
    
    bool isEmpty() {
        if(dq.size()==0) return true;
        return false;
    }
    
    bool isFull() {
        if(dq.size()==maxSize) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */