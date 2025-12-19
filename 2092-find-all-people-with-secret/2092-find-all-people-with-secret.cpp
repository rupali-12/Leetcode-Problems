class Solution {
public:
   typedef pair<int, int>P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<P>>timeMeetings;

        for(auto meeting: meetings){
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];
            timeMeetings[time].push_back({person1, person2});
        }

        vector<bool>knowSecret(n, false);
        knowSecret[0]=true;
        knowSecret[firstPerson] = true;

        for(auto &it: timeMeetings){
            int t = it.first;
            vector<P>meets  = it.second;

            queue<int>que;
            unordered_map<int, vector<int>>adj;  // a-> {b, c, d}
            unordered_set<int>alreadyAdded;

            for(auto& [person1, person2]: meets){
               adj[person1].push_back(person2);
               adj[person2].push_back(person1);

            //    if person1 already know 
            if(knowSecret[person1]==true && alreadyAdded.find(person1)==alreadyAdded.end()){
                que.push(person1);
                alreadyAdded.insert(person1);
            }

            //    if person2 already know 
            if(knowSecret[person2]==true && alreadyAdded.find(person2)==alreadyAdded.end()){
                que.push(person2);
                alreadyAdded.insert(person2);
            }
            }

            // Now I know who know who according to time 
            // process BFS
            while(!que.empty()){
                int person = que.front();
                que.pop();

                for(auto & nextPerson: adj[person]){
                    if(knowSecret[nextPerson]==false){
                        knowSecret[nextPerson]=true;
                        que.push(nextPerson);
                    }
                }
            }
        }
        vector<int>result;
        for(int i=0; i<n; i++){
            if(knowSecret[i]==true){
                result.push_back(i);
            }
        }
        return result;
    }
};