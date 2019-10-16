#include<algorithm>

class Solution {
public:
    bool isAnagram(string s, string t) {
       
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        //排除不一样长字符串
        if(s.size() != t.size())
        {
                return false;
        }
        //判断相等
        for(int i=0;i<s.size();++i)
        {
            
            if(s[i]!=t[i])
            {
                return false;
            }
        }
        return true;
    }
};
