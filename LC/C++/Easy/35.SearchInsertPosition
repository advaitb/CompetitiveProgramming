class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int first=0;
        int last=nums.size();
        int mid;
        while (first<last) 
        {
            mid=first+((last-first)>>1); 
			if (nums[mid]<target)
            {
                first=mid+1;
            }
			else
            {
                last=mid;
            }
        }
        return first;
    }
};
