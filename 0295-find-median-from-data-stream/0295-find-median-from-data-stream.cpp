class MedianFinder {
public:
    priority_queue<int>maxHeap;
    vector<int> arr;
    // int n;
	priority_queue<int, vector<int>, greater<int>>minHeap;
	vector<double>ans;
		double median;
    MedianFinder() {
        median=-1;
    }
    int signum(int a,int b){
	if(a==b){
		return 0;
	}
	else if(a>b){
		return 1;
	}
	return -1;
}
    void addNum(int element) {
      switch(signum(maxHeap.size(), minHeap.size())){
		case 0: if(element>median){
			      minHeap.push(element);
				  median =minHeap.top();
		      }
		      else{
			     maxHeap.push(element);
				 median = maxHeap.top();
		      }
		      break;
			//   case when left size > right size 
	     case 1: if(element>median){
			      minHeap.push(element);
		       }
		      else{
			    //  case when element < M , pop 1 element from maxHeap and push in minheap then push element in maxheap
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(element);				
		      }
               median = (minHeap.top() + maxHeap.top())/2.0;
		      break;
		case -1: if(element>median){
			   	maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(element);
		   }
		      else{
			     maxHeap.push(element);
		      }
               median = (minHeap.top() + maxHeap.top())/2.0;
		      break;
	}
    }
    
    double findMedian() {
        for(int i=0; i<arr.size(); i++){
		addNum(arr[i]);
		ans.push_back(median);
	}
       if(arr.size()>0){
            return ans[ans.size()-1];
       }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */