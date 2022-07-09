class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        q.push_back( 0 );
        for( int i = 1; i < n; i++ ) {
            while( k + q.front() < i ){
                q.pop_front();                
            }
            nums[ i ] += nums[ q.front() ];
            while( q.size() > 0 && nums[ i ] >= nums[ q.back() ]){
                q.pop_back();                
            }
            q.push_back( i );
        }
        return nums[ n - 1 ];
    }
};
