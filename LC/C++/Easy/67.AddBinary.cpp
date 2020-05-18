class Solution {
public:
    string addBinary(string a, string b) 
    {
        string res;
        bool addone = false;
        int size_a = a.length();
        int size_b = b.length();
        if(size_a < size_b)
        {
            for(int i = 0; i < size_b-size_a; i++)
            {
                a.insert(a.begin(),'0');
            }
        }
        if(size_b < size_a)
        {
            for(int i = 0; i < size_a-size_b; i++)
            {
                b.insert(b.begin(),'0');
            }
        }
        for(int i = a.length()-1; i > -1; i--)
        {
            if((a[i]=='1') && (b[i]=='1'))
            {
                if(i==a.length()-1)
                {
                    addone = true;
                    res.insert(res.begin(),'0');
                }
                else
                {
                    if(addone)
                    {
                        res.insert(res.begin(),'1');
                    }
                    else
                    {
                        res.insert(res.begin(),'0');
                        addone = true;
                    }
                }
            }
            else if(a[i]!=b[i])
            {
                if(addone)
                {
                    res.insert(res.begin(),'0');
                }
                else
                {
                    res.insert(res.begin(),'1');
                }
            }
            else
            {
                if(addone)
                {
                    res.insert(res.begin(),'1');
                    addone = false;
                }
                else
                {
                    res.insert(res.begin(),'0');
                }
            }
        }
        if(addone)
        {
            res.insert(res.begin(),'1');
        }
        return res;
    }
};
