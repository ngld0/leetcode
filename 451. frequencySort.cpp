class Solution {
public:
    //compare each value of pair by higher to lower
    static bool cmp(pair<char, int>& a, pair<char, int>& b)
    {
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        string res = "";
        //use map, key is character and the value is the frequency of this character
        unordered_map<char, int> map;
        for(char c: s){
            
            map[c]++;
        }
        //sort the map by value
        vector<pair<char, int>> A;
        for (auto& it : map) {
            A.push_back(it);
        }
        // Sort using comparator function
        sort(A.begin(), A.end(), cmp);
        //push the result after sort by descend
        for (auto& it : A) {
            
            res += std::string(it.second, it.first);;
        }
        return res;
    }
};
/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/
