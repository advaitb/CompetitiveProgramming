class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
       if(nums.empty())
       {
           return 0;
       }
       int prev = nums[0];
       int dup_count = 1;
       auto it = nums.begin()+1;
       while(it != nums.end())
       {
          if(*it==prev)
          {
            it = nums.erase(it);
          }
          else
          {
            dup_count++;
            prev = *it;
            it++;
          }
       }
       return dup_count;
    }
};
