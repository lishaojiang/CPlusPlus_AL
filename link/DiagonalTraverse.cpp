auto io_speed_up =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        vector<int> akRet;
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return akRet;
        }
        int iM = matrix[0].size();
        int iN = matrix.size();

        int iMax = iM > iN ? iM : iN;

        for(int i = 0; i < iMax * 2;i++)
        {
                if(i % 2 == 0)
                {
                    for(int j = i  >=  iN? iN -1 : i;j >=0 && i-j <iM ;j--)
                    {
                        akRet.push_back(matrix[j][i-j]);
                    }
                }
                else
                {
                    for(int j = i  >=  iM? iM -1 : i;j >=0 && i-j <iN ;j--)
                    {
                        akRet.push_back(matrix[i-j][j]);
                    }
                }
        }

        return akRet;
    }
};