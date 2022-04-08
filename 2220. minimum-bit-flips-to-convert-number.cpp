class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = 0;
        while(start != goal){
            if(start%2 != goal%2)
                flips++;
            start = start /2;
            goal = goal /2;
        }
        return flips;
    }
};
