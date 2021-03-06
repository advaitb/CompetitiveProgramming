//KMP
//https://medium.com/@giri_sh/string-matching-kmp-algorithm-27c182efa387

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};

/*
//Brute force
int bruteForce(std::string& text, std::string& pattern)
{
    int startpos = text.length() - pattern.length();
    for(int i = 0; i < startpos; i++)
    {
        int j = 0;
        for(;j < pattern.length(); j++)
        {
            if(text[i+j] != pattern[j])
            {
                break;
            }
        }
        if (j == pattern.length())
        {
            return i;
        }
    }
    return -1;
}
*/
