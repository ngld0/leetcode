class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1);
        istringstream v2(version2);

        while(!v1.eof() || !v2.eof())
        {
            string s1 = "0",s2 = "0";
            if(!v1.eof())
                getline(v1,s1,'.');

            if(!v2.eof())
                getline(v2,s2,'.');

            int n1 = atoi(s1.c_str());
            int n2 = atoi(s2.c_str());
            if(n1 == n2) continue;
            
            return (n1 > n2) ? 1 : -1;
        }
        return 0;
    }
};
