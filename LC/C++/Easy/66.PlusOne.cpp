class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> vec;
        bool addone;
        for(int i = digits.size()-1; i > -1; i--)
        {
            if(digits[i]  == 9)
            {
                if(i == digits.size()-1)
                {
                    addone = true;
                }
                if(addone)
                {
                    vec.insert(vec.begin(), 0);
                }
                else
                {
                    vec.insert(vec.begin(), 9);
                }       
            }
            else
            {
                if(i == digits.size()-1)
                {
                    addone = true;
                }
                if(addone)
                {
                  vec.insert(vec.begin(), digits[i]+1); 
                  addone = false;
                }
                else
                {
                    vec.insert(vec.begin(), digits[i]);
                }
            }
        }
        if(addone)
        {
            vec.insert(vec.begin(), 1);
        }
        return vec;
    }
};
