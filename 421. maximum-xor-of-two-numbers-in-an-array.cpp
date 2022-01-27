class Solution {
public:
    
    //ref https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91064/C%2B%2B-22-ms-beats-99.5-array-partitioning-similar-to-quick-sort
    // thanks author for the best solution!
    int findMaximumXOR(vector<int>& nums) {
        
        return helper(nums, 0, nums.size()-1, 0, nums.size()-1, 0, 30);
    }
private:
    // (ls, le) and (rs, re) are two ranges of nums, which gives max xor value to current bit;
    // bit decreases from 30 to 0, i.e., working from most significant bit on the left towards right;
    // Similar to quicksort, partition (ls, le) to two ranges (ls, j-1) and (j, le) by swapping elements
    // the range on the left with current bit = 1, and the range on right is 0; We do the same to (rs, re)
    // In order to set the current bit in the answer, i.e. val, to be 1, the left (ls, le) and right (rs,re) ranges must have subranges with opposite bit. If so, val = (val << 1) + 1; otherwise, val = val << 1.
    
    int helper(vector<int>& nums, int ls, int le, int rs, int re, int val, int bit) {
        if (bit == -1) return val;
        int mask = 1<<bit, j = ls, k = rs;
        for (int i = ls; i <= le; i++) 
            if (nums[i]&mask) swap(nums[i], nums[j++]);
        for (int i = rs; i <= re; i++) 
            if (nums[i]&mask) swap(nums[i], nums[k++]);
        // the left range has two subranges, the answer is max of (bit 1 subrange on the left and bit 0 subrange on the right) or (bit 0 subrange on the left and bit 1 subrange on the right)
        if (j > ls && j <= le) {
            int ans = 0;
            if (k > rs) 
                ans = helper(nums, j, le, rs, k-1, val*2+1, bit-1);
            if (k <= re) 
                ans = max(ans, helper(nums, ls, j-1, k, re, val*2+1, bit-1));
            return ans;
        }
        // the left range has only bit 0 subrange
        else if (j <= ls) {
            // check whether the right range has bit 1 subrange
            if (k > rs) 
                return helper(nums, ls, le, rs, k-1, val*2+1, bit-1);
            else 
                return helper(nums, ls, le, rs, re, val*2, bit-1);
        }
        // the left range has only bit 1 subrange
        else {
            // check whether the right range has bit 0 subrange
            if (k <= re) 
                return helper(nums, ls, le, k, re, val*2+1, bit-1);
            else 
                return helper(nums, ls, le, rs, re, val*2, bit-1);
        }
    }

};


  
  /*
  Sol 2. 
  struct TrieNode{
  TrieNode * next[2];
    
    TrieNode(){
        next[0]=NULL;
        next[1]= NULL;
        
    }
};


class Solution {
public:
    
    TrieNode * buildTrie(vector<int>nums){
        
        TrieNode * root = new TrieNode();
        
        TrieNode * cur = NULL;
    
        
        for(int num : nums){
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (cur->next[index] ==  NULL)
                    cur->next[index] = new TrieNode();
                cur = cur->next[index];
            }
            
            
        }
        
        return root;
    }
    
    
    int helper(TrieNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (cur->next[index]) {
                res <<= 1;
                res |= 1;
                cur = cur->next[index];
            } else {
                res <<= 1;
                res |= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }
    
    
    
    int findMaximumXOR(vector<int>& nums) {
        
        
        int res = 0;
        TrieNode* root = buildTrie(nums);
        
        for (auto i : nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
        
        
    }
};
  */


