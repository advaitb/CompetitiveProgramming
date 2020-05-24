class Solution 
{
public:
    int climbStairs(int n) 
    {
        //4 = 1,1,1,1 OR 2,1,1 OR 1,2,1 OR 1,1,2 OR  2,2
        //seems to be following fibonnaci - indeed!
        // Use O(n) time and O(1) space!
        
        if(n==0||n==1)
        {
            return 1;
        }
        int prev = 1;
        int pprev = 1;
        int result = 0;
        for(int i = 2; i <= n; i++)
        {
            result = prev+pprev;
            pprev = prev;
            prev = result;
        }
        return result;
    }
};
