auto io_speed_up =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution
{

public:
	void reversarray(char* acArray, int iBegin, int iEnd, int iOffset =0)
	{
		char cTemp;
		// strcpy
		if (iOffset != iBegin)
		{
			for (int i = iBegin,j = 0; i <= iEnd; i++,j++)
			{
				*(acArray + iOffset + j) = *(acArray + i);
			}
		}
		// swap
		for (int i = 0; i < (iEnd - iBegin + 1) / 2; i++)
		{
			cTemp = *(acArray +iOffset + i);
			*(acArray + iOffset + i) = *(acArray + iOffset + iEnd - iBegin - i);
			*(acArray + iOffset + iEnd - iBegin - i) = cTemp;
		}
	}
	void reverseWords(string &s)
	{
		char* pStr = (char*)s.c_str();
		char* pcBegin = pStr;
		int iSize = s.size();
		reversarray(pStr, 0, iSize - 1);
		int iCount = 0;
		int iBegin = 0;
		int iEnd = 0;
		int iRealIndex = 0;
		while (*pStr)
		{
			if (*pStr == ' ')
			{
				iCount++;
				pStr++;
			}
			else
			{
				iBegin = iCount;
				while (*pStr && *pStr != ' ')
				{
					iEnd = iCount;
					iCount++;
					pStr++;
				}
				if (iRealIndex != 0)
				{
					*(pcBegin + iRealIndex) = ' ';
					iRealIndex++;
				}
				reversarray((char*)s.c_str(), iBegin, iEnd,iRealIndex);
				iRealIndex += (iEnd - iBegin +1);
			}
		}
		*(pcBegin + iRealIndex) = 0;
	}
};