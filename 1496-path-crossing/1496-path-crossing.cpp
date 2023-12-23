class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>>track;
        track.insert({0,0});
        int x=0, y=0;
        for(int i=0; i<path.length(); i++){
            char ch= path[i];
            if(ch=='N'){
                y+=1;
            }
            else if(ch=='S') y-=1;
            else if(ch=='E') x+=1;
            else x-=1;
            pair<int, int>p;
            p.first = x;
            p.second=y;
            if(track.find(p)!=track.end()){
                return true;
            }
            else{
                track.insert(p);
            }
        }
        return false;
    }
};