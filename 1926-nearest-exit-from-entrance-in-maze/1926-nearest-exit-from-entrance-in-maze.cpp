class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m= maze.size(), n= maze[0].size();
        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        // mark as visited 
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        vector<vector<int>>directions{{-1, 0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            int size= q.size();
            
            while(size--){
                pair<int, int>front= q.front();
                q.pop();
                
                int i= front.first;
                int j= front.second;
                
             // if boundary 
        if( (front != make_pair(entrance[0], entrance[1])) && (i==0 || j==0 || i==m-1 || j==n-1 )){
            return steps;
        }
    
            // explore neighbour
            for(auto & dir: directions){
                int new_i = i+dir[0];
                int new_j= j+dir[1];
            if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && maze[new_i][new_j]!='+'){
                    q.push({new_i, new_j});
                    maze[new_i][new_j] = '+';
                }
            }
            }
            steps++;
        }
        return -1;
    }
};