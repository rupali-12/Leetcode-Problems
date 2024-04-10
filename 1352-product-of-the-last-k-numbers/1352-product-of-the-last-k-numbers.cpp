class ProductOfNumbers {
public:
   vector<int>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
      if(num==0){
          v.clear();
          return;
      }
     if(v.empty()){
         v.push_back(num);
     }
        else{
            v.push_back(v.back()*num);
        }
    }
    
    int getProduct(int k) {
        if(k>v.size()){
            return 0;
        }
        
       if(k==v.size()){
           return v[k-1];
       }
        
        return v.back()/(v[v.size()-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */