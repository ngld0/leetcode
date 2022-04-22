class MyHashMap {
public:
    vector<pair<int, int>> vt;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        
        for(auto v = 0; v<vt.size();v++){
            if(vt[v].first == key){
                pair<int, int> tt= {key, value};
                vt[v] = tt;
                return;
            }
        }
        
        vt.push_back({key, value});   
        
    }
    
    int get(int key) {
        for(auto v:vt){
            if(v.first == key){
                return v.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto v = 0; v<vt.size();v++){
            if(vt[v].first == key){
                vt.erase(vt.begin()+v);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
