class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans=0;
        unordered_map<int, pair<int, int>>x_range;
        unordered_map<int, pair<int, int>>y_range;

        // store min max of x and y coordinates 
        for(auto coordinate: buildings){
            int x= coordinate[0], y= coordinate[1];
           if(!x_range.count(x)){
              x_range[x] ={y, y};
           }
           else{
            x_range[x].first = min(x_range[x].first, y);
            x_range[x].second = max(x_range[x].second, y);
           }

           if(!y_range.count(y)){
              y_range[y] ={x, x};
           }
           else{
            y_range[y].first = min(y_range[y].first, x);
            y_range[y].second = max(y_range[y].second, x);
           }
        }
    
        // check if it not extreme then count
        for(int i=0; i<buildings.size(); i++){
            int x= buildings[i][0], y= buildings[i][1];
            bool is_extreme_x = (x_range[x].first == y || x_range[x].second==y);
            bool is_extreme_y = (y_range[y].first == x || y_range[y].second==x);
            if(!is_extreme_x && !is_extreme_y){
                ans++;
            }
        }
        return ans;
    }
};