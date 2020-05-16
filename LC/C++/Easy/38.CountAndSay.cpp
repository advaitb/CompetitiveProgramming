class Solution 
{
public:
    string countAndSay(int n) 
    {
        if(n==0) return "";
        if(n==1) return "1";
        if(n==2) return "11";
        string result = countAndSay(n-1);
        string updateresult ="";
        int count = 1;
        for(int i = 1; i < result.length(); i++)
        {
            if(result[i]!=result[i-1])
            {
                updateresult+=to_string(count)+result[i-1];
                count = 1;
            }
            else
            {
                count++;
            }
            if(i == result.size()-1)
            {
                updateresult+=to_string(count)+result[i];
            }
        }
        return updateresult;
    }
};
