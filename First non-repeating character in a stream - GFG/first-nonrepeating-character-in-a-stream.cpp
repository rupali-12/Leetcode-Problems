//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		   queue<char>q;
		    string ans="";
		    map<char, int>count;
		    for(int i=0; i<A.length(); i++){
		        char ch =A[i];
		        count[ch]++;
		        q.push(ch);
		        
		      //  check for q.front is repeating or non repeating 
		        while(!q.empty()){
		            if(count[q.front()]>1){
		                q.pop();
		            }
		            else{
		                ans+=q.front();
		                break;
		            }
		        }
		        
		      //  case q.empty means there is no  non-repeating character  
		        if(q.empty()){
		            ans+="#";
		        }
		    }
		    	return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends