class Solution {
public:
    
    string findCreatorId(vector<pair<int, int>>mpSecSecond, vector<string>& ids){
        vector<string>temp;
        sort(mpSecSecond.begin(), mpSecSecond.end());
        int mxViews= mpSecSecond.back().first;
        for(auto m: mpSecSecond){
            if(m.first==mxViews){
                temp.push_back(ids[m.second]);
            }
        }
        sort(temp.begin(), temp.end());
        return temp[0];
    }
    
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n= creators.size();
        unordered_map<string, pair<long long, vector<pair<int, int>>>>mp;
        long long highestPopularity=INT_MIN;
        for(int i=0; i<n; i++){
            pair<int, int>inner = make_pair(views[i], i);
            pair<long long, vector<pair<int,int>>>outer;
            outer.first+= views[i];
            outer.second.push_back(inner);
            if(mp.find(creators[i])!=mp.end()){
                mp[creators[i]].first+= views[i];
                mp[creators[i]].second.push_back(inner);
            }
            else{
                mp[creators[i]] = outer;
            }
            highestPopularity= max(highestPopularity, mp[creators[i]].first);
        }
        
          //  for(auto m: mp){
        //     cout<<m.first<<": ";
        //     pair<int, vector<pair<int, int>>>temp= m.second;
        //     cout<<temp.first<<" -> ";
        //     vector<pair<int, int>>ans= temp.second;
        //     for(auto a: ans){
        //         cout<<"("<<a.first<<", "<<a.second<<"), ";
        //     }
        //     cout<<endl;
        // }
        
        vector<vector<string>>ans;
        for(auto m: mp){
            if(m.second.first==highestPopularity){
                vector<string>temp;
                temp.push_back(m.first);
                string id_creators = findCreatorId(m.second.second, ids);
                temp.push_back(id_creators);
                ans.push_back(temp);
            }
        }
        return ans;
        
        
    }
};