class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> ret; 
        for (auto op:ops){
            if(op == "C"){
                
                ret.pop();
            } else if(op == "D"){
                int tem = ret.top();
                ret.push(tem *2);
            }  else if(op == "+"){
                int tem = ret.top();
                ret.pop();
                int ss = tem + ret.top();
                ret.push(tem);
                ret.push(ss);
            }else 
                ret.push(stoi(op));
            //cout<< ret.top()<<endl;
        }
        int score = 0;
        while(!ret.empty()){
            score += ret.top();
            ret.pop();
        }
        
        return score;
    }
};
