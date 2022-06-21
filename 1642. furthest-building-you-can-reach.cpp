class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> que;
        for (int i = 0; i < heights.size() - 1; i++) {
            int heigh = heights[i + 1] - heights[i];
            if (heigh > 0)
                que.push(-heigh);
            if (que.size() > ladders) {
                bricks += que.top();
                que.pop();
            }
            if (bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
};
