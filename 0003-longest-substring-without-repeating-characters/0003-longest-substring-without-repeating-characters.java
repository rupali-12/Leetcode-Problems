class Solution {
    public int lengthOfLongestSubstring(String s) {
             int left=0, right=0;
       HashMap<Character, Integer>mp=new HashMap<Character, Integer>();
        int len=0;
        int n= s.length();
        while(right<n){
            if(mp.containsKey(s.charAt(right))){
                 left= Math.max(left, mp.get(s.charAt(right))+1);
            }
            
            // update occurence of char 
             mp.put((s.charAt(right)), right);
            len = Math.max(len, right-left+1);
            right++;
        }
        return len;
    }
}