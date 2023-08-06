class Solution {
public:
    int minSwaps(string str) {
        
  // step-1: check odd condition
  if(str.length()%2!=0){
    return -1;
  }
  //  step-2: Remove Valid part 
       int openCount=0, closeCount=0;
     stack<int>s;
     for(int i=0; i<str.length(); i++){
       char ch= str[i];
       if(ch=='['){
         s.push(ch);
       }
       else{
         //  ch is closed bracket 
        if(!s.empty() && s.top()=='['){
          s.pop();
        }
        else{
          s.push(ch);
        }
       }
     }

    //  step 2 count number of opening and closing brackets in stack present after removing valid part 
    while(!s.empty()){
      if(s.top()=='[')
        openCount++;
      else
        closeCount++;
    s.pop();
    }
  int res = (openCount+1)/2 + (closeCount+1)/2;
   return res/2;
    }
};