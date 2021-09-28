class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        int[] sT = new int[127];
        
        Arrays.fill(sT,-1);
        
        int[] tT=new int[127];
        
        Arrays.fill(tT,-1);
        
        int i = 0 ;
        
        while(i<s.length()){
            
            if(sT[s.charAt(i)] != tT[t.charAt(i)]) return false;
            sT[s.charAt(i)]=i+1;
            tT[t.charAt(i)] = i+1;
            i++;
        }
        
        return true;
    }
}
