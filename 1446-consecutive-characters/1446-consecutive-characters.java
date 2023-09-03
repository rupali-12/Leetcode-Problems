class Solution {
    public int maxPower(String s) {
        int maxLen=1;
        int count=1;
        char ch=s.charAt(0);
        for(int i=1; i<s.length(); i++){
            if(s.charAt(i)==ch){
                count++;
                 maxLen= Math.max(maxLen, count);
            }
            else{
                maxLen= Math.max(maxLen, count);
                ch= s.charAt(i);
                count=1;
            }
        }
        return maxLen;
    }
}