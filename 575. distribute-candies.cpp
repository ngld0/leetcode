class Solution {
public:
    
    //Sol1. using sort then O(nlogn), O(1) space
    int distributeCandies(vector<int>& candyType) {

        sort(candyType.begin(), candyType.end());
        int type = 1;
        int n = candyType.size();
        for(int i = 1;i<n;i++){
            if(type >= n/2)  break;
            if(candyType[i] != candyType[i-1]) 
                type++;
        }
        return type;
        
    }  
    /*
    //Sol2. using map: time O(n), space O(n)
    int distributeCandies(vector<int>& candyType) {
        //set type = 0 first;
        unordered_map<int,int> mm;
        int type = 0;
        int n = candyType.size();
        for(int candy: candyType){
            mm[candy]++;
            if(mm[candy]==1) 
                type++;
            if(type>=n/2) 
                break;
        }
        return type;
    }
    */

};
