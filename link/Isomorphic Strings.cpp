class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        char aS[256] = {0};
        char aT[256] = {0};
        for(int i = 0; i < s.size();i++)
        {
            if(aS[s[i]] != aT[t[i]])
            {
                return false;
            }
            aS[s[i]] = i+1;
            aT[t[i]] = i+1;
        }
        return true;
    }
};