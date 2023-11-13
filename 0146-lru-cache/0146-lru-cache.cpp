// **********Approach-1: using Queue ***********************
// typedef pair<int, int> ii;
// class LRUCache {
// public:
//    // (key, frequency)
//     queue<ii>q;
//     // key, (value, frequency)
//     unordered_map<int, ii>mp; 
//     int csize;
//     LRUCache(int capacity) {
//         csize= capacity;
//     }
    
//     int get(int key) {
//         if(mp.find(key)==mp.end()){
//             return -1;
//         }
//         mp[key].second++;
//         q.push(ii(key, mp[key].second));
//         return mp[key].first;
//     }
    
//     void put(int key, int value) {
//         // if key exist
//         if(mp.find(key)!=mp.end()){
//                 // delete least frequently used 
//               mp[key].first=value;
//             mp[key].second++;
//             q.push(ii(key, mp[key].second));
//             return;
//             }
//             // present
//          // key does not exist. Evict if necessary before adding.
//            if(csize==mp.size()){
//                while(q.front().second != mp[q.front().first].second){
//                    q.pop();
//                }
//                ii temp= q.front();
//                q.pop();
//                mp.erase(temp.first);
//            }
//         mp[key]= ii(value, 1);
//         q.push(ii(key, mp[key].second));
//     }
// };


// ****************Approach-2: Using Linked list *************************
class LRUCache
{
public:
    class node{
        public:
        int key, value;
        node* next, *prev;
        node(int _key, int _value){
            key= _key;
            value= _value;
        }
    };

    node* head= new node(-1, -1);
    node* tail= new node(-1, -1);
    int cap;
    unordered_map<int, node*>mp;     //  <key, node>
    LRUCache(int capacity)
    {
        // Write your code here
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }

    void addnode(node* newnode){
       node* temp= head->next;
       newnode->next= temp;
       head->next= newnode;
       temp->prev= newnode;
       newnode->prev= head;
       return;
    }

    void deletenode(node* delnode){
       node* delprev= delnode->prev;
       node* delnext= delnode->next;
       delprev->next= delnext;
       delnext->prev= delprev;
       return;
    }

    int get(int _key)
    {
        // Write your code here
        if(mp.find(_key)!=mp.end()){
            node* resnode= mp[_key];
            int res= resnode->value;
            deletenode(resnode);
            addnode(resnode);
            mp[_key]= head->next;
            return res;
        }
      return -1;
    }

    void put(int _key, int _value)
    {
        // Write your code here
        if(mp.find(_key)!=mp.end()){
           node* exitnode = mp[_key];
           mp.erase(_key);
           deletenode(exitnode);
        }

        if(mp.size()==cap){
           mp.erase(tail->prev->key);
           deletenode(tail->prev);
        }

        addnode(new node(_key, _value));
        mp[_key]= head->next;
        return;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */