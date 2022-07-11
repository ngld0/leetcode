class RecentCounter {
    queue<int> mm;
public:
    RecentCounter() {
        mm = {};
    }
    
    int ping(int t) {
        mm.push(t);
        while(mm.front()<t-3000) 
            mm.pop();
        return t=mm.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
