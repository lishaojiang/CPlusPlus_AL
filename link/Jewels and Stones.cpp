class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> kMap;
        for(int i = 0; i < J.size();i++)
        {
            kMap[J[i]] = 0;
        }
        int iTimes = 0;
        for(int i = 0; i < S.size();i++)
        {
            if(kMap.find(S[i]) != kMap.end())
            {
                iTimes++;
            }
        }
        return iTimes;
    }
};