class MyQueue {
public:

    // Using Arrays 
    int front;
    vector<int>arr;
    MyQueue() {
        front=0;
    }
    
    void push(int x) {
        arr.push_back(x);
    }
    
    int pop() {
        if(empty()) return -1;
        int val= arr[front++];
        return val;
    }
    
    int peek() {
        if(empty()) return -1;
        return arr[front];
    }
    
    bool empty() {
        return front == arr.size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */