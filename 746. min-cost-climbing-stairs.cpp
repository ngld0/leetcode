class Solution {
public:

    /*
    // Time O(n), space O(n)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // size
        int mm[n]; // cause of O(n) space; 
        int i; //iterator
        for(i = 0; i<n;i++){ // cause of Time O(n)
            if(i<2) // add first and second cost to the array mm; 
                mm[i] = cost[i];
            else{ // select the minimal sum of current cost and the previous two costs;
                mm[i] = cost[i] + min(mm[i-1], mm[i-2]); 
            } 
        }
        return min(mm[i-1],mm[i-2]);
    }    
    */
    //optimized to: Time O(n); space O(1) by using two pointer;
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0], second = cost[1], n=cost.size(); // by using normal variable, then space O(1);
        if(n <3) { // return the min if the size of cost is 3;
            return min(first, second);            
        }
        for(int i = 2;i<n;i++){ //cause of O(n) time
            int tt = cost[i] + min(first, second); // computing the total cost at i step;
            first = second; 
            second = tt;
        }
        return min(first, second);
    }

};
