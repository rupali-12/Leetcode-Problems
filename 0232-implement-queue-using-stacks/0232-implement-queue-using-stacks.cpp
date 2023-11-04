// class MyQueue {
//     private:
//      int *arr;
//       int size;
//       int frnt, rear;
// public:
//     MyQueue() {
//          size= 100001;
//        arr= new int[size];
//        frnt=rear=0;
//     }
    
//     void push(int x) {
//           if(rear==size)
//            return;
        
//         arr[rear]=x;
//         rear++;
//         return;
//     }
    
//     int pop() {
//         if(frnt==rear){
//             return -1;
//         }
//         int temp=arr[frnt];
//         arr[frnt]=-1;
//         frnt++;
//         return temp;
//     }
    
//     int peek() {
//             if(frnt==-1){
//             return -1;
//         }
//         return arr[frnt];
//     }
    
//     bool empty() {
//           if(frnt==rear){
//             return true;
//         }
//         return false;
//     }
// };

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */


// ***************************************************************************
class MyQueue {
    private:
    stack<int>s;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stack<int>temp;
     while(!s.empty()){
         temp.push(s.top());
         s.pop();
     }
        s.push(x);
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        return;
    }
    
    int pop() {
        int temp= s.top();
        s.pop();
        return temp;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
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