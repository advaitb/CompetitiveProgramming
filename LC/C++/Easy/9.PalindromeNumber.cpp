class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        int _x = x;
        if(x < 0)
        {
            return false;
        }
        long long res = 0;
        while(_x > 0)
        {
            res = res*10+ _x%10;
            _x /= 10;
        }
        return res == x;
        
    }
};
