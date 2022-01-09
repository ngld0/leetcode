class Solution {
public:
    // time 0(n), space O(1)
    bool isRobotBounded(string instructions) {
        // (x, y) started location
        int x = 0, y = 0, i = 0;
        // move around a point
        vector<vector<int>> move = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        
        for (char instruction : instructions)
            
            if (instruction == 'R')
                // turn right 1 unit
                i = (i + 1) % 4;
        
            else if (instruction == 'L')
                // turn left
                i = (i + 3) % 4;
        
            else
                // go straint 1 unit
                x += move[i][0], y += move[i][1];
        return x == 0 && y == 0 || i > 0;
    }
};
