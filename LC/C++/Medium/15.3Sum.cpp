class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector <int>> res;
        vector <int> temp(3);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            temp[0] = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    temp[1] = nums[left];
                    temp[2] = nums[right];
                    res.push_back(temp);
                    while(left < right && nums[left+1] == nums[left]) left++; 
                    while(left < right && nums[right-1] == nums[right]) right--;
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else right--;     
            }
        }
        return res;
    }
};
