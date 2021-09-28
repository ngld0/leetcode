class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int tem = 0;
        int i;
        char[] chars = s.toCharArray();
        for(i = s.length() - 1; i>=0 ;i--){
            tem = (shifts[i] + tem) %26;
            //s.charAt(i) += tem ;
            chars[i] = (char)((s.charAt(i) - 'a' + tem) % 26 + 'a');
        }
        return new String(chars);
    }
}
