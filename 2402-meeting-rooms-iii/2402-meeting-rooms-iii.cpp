class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long>lastAvailableAt(n, 0); // room number i will be last available
        vector<int>roomUsedCount(n,0);
        
        for(vector<int>&meet: meetings){
            int start= meet[0];
            int end= meet[1];
            int duration= end-start;
            bool found=false;
            long long earlyEndRoomTime= LLONG_MAX;
            int earlyEndRoom =-1;
            
            // find the first avilable room for any meeting 
            for(int room=0; room<n; room++){
                if(lastAvailableAt[room]<=start){
                    lastAvailableAt[room]= end;
                    roomUsedCount[room]++;
                    found=true;
                    break;  // stop when you find a room available
                }
                
                if( lastAvailableAt[room]<earlyEndRoomTime){
                    earlyEndRoomTime = lastAvailableAt[room];
                    earlyEndRoom =room;
                }
            }
            
            // I couldn't find my room 
            if(!found){
                // pick room which willl end first 
                lastAvailableAt[earlyEndRoom] += duration;
                roomUsedCount[earlyEndRoom]++;
            }
        }
        int resultRoom=-1;
        int maxUse=0;
        for(int i=0; i<n; i++){
            if(roomUsedCount[i]>maxUse){
                maxUse= roomUsedCount[i];
                resultRoom= i;
            }
        }
        return resultRoom;
    }
};