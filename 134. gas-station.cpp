class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0, totalCos=0, tank=0, ans=0;
        for(int i=0; i<gas.size(); i++){
          totalGas += gas[i];
          totalCos += cost[i];
          tank += gas[i]-cost[i];
          if(sum<0){
            tank = 0;
            ans = i+1;
          }            
        }
        if(totalGas < totalCos) return -1;
        return ans;
   }
};
