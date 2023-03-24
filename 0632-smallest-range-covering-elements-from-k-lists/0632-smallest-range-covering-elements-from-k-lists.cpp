
class node{
public:
   int data;
   int listNumber;
   int valueInCurrList;

   node(int data, int row, int col){
       this->data = data;
       listNumber =row;
       valueInCurrList = col;
   }
};
class compare{
    public:
    bool operator()(node* a, node*  b){
        return a->data > b->data;
    }
};
class Solution {
public:
    
    vector<int> smallestRange(vector<vector<int>>& a) {
        int k= a.size();
         int mn =INT_MAX;
    int mx =INT_MIN;
    int range;
    priority_queue<node*, vector<node*>, compare>minHeap;
    // step-1 :: insert first element of all lists and track min/ max element
    for(int i=0;i <k; i++){
        node* temp = new node(a[i][0],i,0);
        mn = min(a[i][0], mn);
        mx = max(a[i][0], mx);
        minHeap.push(temp);
    }

    // step-2:: process for min and max;
    int rangeStart =mn, rangeEnd =mx;

    // process ranges  
    while(!minHeap.empty()){

    // mn fetch 
       node* temp = minHeap.top();
       minHeap.pop();
       mn= temp->data;    // min update

    //    range and ans updation 
       if((mx-mn)< (rangeEnd-rangeStart)){
        //    range = rangeEnd - rangeStart;
        rangeEnd = mx;
        rangeStart =mn;
       }

    //    now update mx 
    int r =temp->listNumber;
    int c =temp->valueInCurrList;

    // next element exits 
    if((c+1) < a[r].size()){
      node* newNode =new node(a[r][c +1], r, c+1);
      minHeap.push(newNode);
       mx =max(mx, a[r][c+1]);
        
    }
    else{         //  next element not exits 
        break;
    }
    }
    vector<int>ans;
        ans.push_back(rangeStart);
        ans.push_back(rangeEnd);
    return ans;
    }
};