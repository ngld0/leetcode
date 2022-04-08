class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> ss;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto num:nums){
            
            ss.push(num);
            if(ss.size()> k) ss.pop();
        } 
    }
    
    int add(int val) {
        ss.push(val);
        if(ss.size()> kth) ss.pop();
        return ss.top();
    }
    /*
    sort[4, 5, 8, 2, 3] -> 2,3,  4,5,8 -> K largest is the k-th from the last 
    sort[4, 5, 8, 2, 3,5]-> 2,3,4,  5,5,8
    sort[4, 5, 8, 2, 3,5,10]-> 2,3,4,5,  5,8,10
    sort[4, 5, 8, 2, 3,5,10,9]-> 2,3,4,5,5,  8,9,10
    sort[4, 5, 8, 2, 3,5,10,9,4] -> 2,3,4,4,5,5,   8,9,10
    */
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
