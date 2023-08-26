class Solution {
    public boolean canCross(int[] stones) {
        HashMap<Integer, HashSet<Integer>>mp= new HashMap();
        int n= stones.length;
        for(int i=0; i<n; i++){
            mp.put(stones[i], new HashSet<Integer>());
        }
        
        mp.get(stones[0]).add(0);
        
        for(int i=0; i<n; i++){
            int stone = stones[i];
            
            HashSet<Integer>set = mp.get(stone);
            for(int val: set){
                // k-1
                if(mp.containsKey(stone+val-1)){
                    if(val-1>0){
                        mp.get(stone+val-1).add(val-1);
                    }
                }
                // k
                  if(mp.containsKey(stone+val)){
                    if(val>0){
                        mp.get(stone+val).add(val);
                    }
                }
                // k+1
                  if(mp.containsKey(stone+val+1)){
                    if(val+1>0){
                        mp.get(stone+val+1).add(val+1);
                    }
                }
            }
            if(mp.get(stones[n-1]).size()>0){
                return true;
            }
        }
        return false;
    }
}