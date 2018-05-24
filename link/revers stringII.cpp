auto io_speed_up =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution 
{
public:
    void reverarray(char* acArray,int iBegin,int iEnd)
    {
        char c;
        for(int i =0; i < (iEnd- iBegin +1)/2;i++)
        {
            c = acArray[iBegin +i];
            acArray[iBegin+ i] = acArray[iEnd - i];
            acArray[iEnd-i] = c;
        }
    }
    string reverseWords(string s) 
    {
        char* p = (char*)s.c_str();
        char* pBegin = p;
        //reverarray(p,0,s.size()-1);
        int iIndex =0;
        int i = 0;
        while(*p)
        {
            bool bcheck = false;
            for( i = iIndex; *p > 0 && i < s.size() && p[i] != ' ';i++)
            {
                bcheck = true;
            }
            if(bcheck)
            {
                reverarray(pBegin,iIndex,i-1); 
                p = p+i;
            }
            else
            {
                p++;
            }
        }
        return s;
    }
};