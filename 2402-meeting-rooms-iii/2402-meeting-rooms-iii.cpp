class Solution {
public:
    typedef pair<long long, int>P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
//         // Approach-1: Brute force 
//         sort(meetings.begin(), meetings.end());
//         vector<long long>lastAvailableAt(n, 0); // room number i will be last available
//         vector<int>roomUsedCount(n,0);
        
//         for(vector<int>&meet: meetings){
//             int start= meet[0];
//             int end= meet[1];
//             int duration= end-start;
//             bool found=false;
//             long long earlyEndRoomTime= LLONG_MAX;
//             int earlyEndRoom =-1;
            
//             // find the first avilable room for any meeting 
//             for(int room=0; room<n; room++){
//                 if(lastAvailableAt[room]<=start){
//                     lastAvailableAt[room]= end;
//                     roomUsedCount[room]++;
//                     found=true;
//                     break;  // stop when you find a room available
//                 }
                
//                 if( lastAvailableAt[room]<earlyEndRoomTime){
//                     earlyEndRoomTime = lastAvailableAt[room];
//                     earlyEndRoom =room;
//                 }
//             }
            
//             // I couldn't find my room 
//             if(!found){
//                 // pick room which willl end first 
//                 lastAvailableAt[earlyEndRoom] += duration;
//                 roomUsedCount[earlyEndRoom]++;
//             }
//         }
//         int resultRoom=-1;
//         int maxUse=0;
//         for(int i=0; i<n; i++){
//             if(roomUsedCount[i]>maxUse){
//                 maxUse= roomUsedCount[i];
//                 resultRoom= i;
//             }
//         }
//         return resultRoom;
        
        // Approach-2: Optimize (minheap)
        int m= meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<int>roomUsedCount(n, 0);
        priority_queue<P, vector<P>, greater<P>>usedRooms;
        priority_queue<int, vector<int>, greater<int>>availableRooms;
        
        // push all room as available
        for(int room=0; room<n; room++){
            availableRooms.push(room);
        }
        
        for(vector<int>&meet: meetings){
            int start= meet[0];
            int end= meet[1];
            int duration =end-start;
            
            // jo room khali ho skate h usko available room m push 
            while(!usedRooms.empty() && usedRooms.top().first<=start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }
            
            // check is any room is available 
            if(!availableRooms.empty()){
                int room =availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end, room});
                roomUsedCount[room]++;
            }
            else{   // no room is available
                int room = usedRooms.top().second;
                long long earlyRoomEndTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({(earlyRoomEndTime+duration), room});
                roomUsedCount[room]++;
            }
        }
        int resultRoom =-1;
        int maxUse=0;
        for(int room=0; room<n; room++){
            if(roomUsedCount[room]>maxUse){
                maxUse = roomUsedCount[room];
                resultRoom = room;
            }
        }
        return resultRoom;
        
    }
};