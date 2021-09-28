class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string res(s);
        for (int i = 1; i < s.size(); ++i) {
            s.push_back(s[0]);
            s.erase(s.begin());
            res = min(res, s);
        }
        return res;
    }
};
//https://github.com/grandyang/leetcode/issues/899
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for (int i = 0; i < S.size(); ++i) {
            res = min(res, S.substr(i) + S.substr(0, i));
        }
        return res;
    }
};
