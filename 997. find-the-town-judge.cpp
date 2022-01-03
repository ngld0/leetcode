class Solution {
public:
    /*
    one of n people is judge => n-1 people and 1 judge;
    
    */
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(n == 1) return 1;
        // init a vector contains n people, bcz the first index is 0 so we have to use n+1
        // and the init value for all people is 0
        vector<int> mp(n+1,0);
        // if a people is judge (bi) (bi trust by ai) then we increase the value ;
        // after increased, whether a person is judge or not,we evaluate by the total people vote for this person
        //because the total person is n-1, then if the total vote for this person is equal to n-1 then return this person.
        for(auto &v:trust){
            mp[v[1]]++;
            mp[v[0]]--;
        }
        // check whether is judge or not.
        for(int i = 1; i <= n; i++){
            if(mp[i] == n-1) return i;
        }
        
        return -1;
    }
};

/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
 

Constraints:

1 <= n <= 1000
0 <= trust.length <= 10^4
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
*/
