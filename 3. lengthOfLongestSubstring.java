class Solution {
    public int lengthOfLongestSubstring(String s) {
        //Set<Character> set = new HashSet<>();
        int point_a = 0;
        int tem = -1;
        int res=0;
        int[] a = new int[128];
        Arrays.fill(a,-1);
        while(point_a < s.length()){
            
            tem=Math.max(tem,a[s.charAt(point_a)]);
            a[s.charAt(point_a)] = point_a;
            res = Math.max(res,point_a-tem);
            point_a++;
            
        }
        return res;
    }
}
