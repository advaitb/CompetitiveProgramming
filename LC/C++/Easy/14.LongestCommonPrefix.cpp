class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans = "";
        int len1 = strs.size();
        if (len1 == 0) 
            return "";
        int len2 = strs[0].length();
        for (int i = 0; i < len2; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < len1; ++j) {
                if (strs[j][i] != c) {
                    return ans;
                }
            }
            ans += c;
        }
        return ans;
    }
};
