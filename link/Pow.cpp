#include <iostream>
#include <map>


// 1.first,i can't input the right code by myself,after reference internet source code,i understand
// how to slover this problem

// mypow is written by recursion, it is easy to understand
// mypowB is written by no recursion, it is hard to understand,it take me so much time to repair it

class Solution {
public:


	double myPow(double x,int n)
	{
		if(n == 0)
		{
			return 1;
		}

		if(n == 1)
		{
			return x;
		}

		if(n == -1)
		{
			return 1.0f/x;
		}

		std::map<int,double>::iterator iter = m_kSpeedUpMap.find(n);
		if(iter != m_kSpeedUpMap.end())
		{
			return iter->second;
		}

		if(n % 2 == 0)
		{
			double fRet = myPow(x,n/2) * myPow(x,n/2);
			m_kSpeedUpMap[n] = fRet;
			return fRet;
		}
		else
		{
			double fRet =  myPow(x,n/2) * myPow(x,n > 0 ? n/2+1 : n/2-1);
			m_kSpeedUpMap[n] = fRet;
			return fRet;
		}
	}
	double myPowB(double x,int n)
	{
		double b = 1.0f;
		if(n == 0)
			return 1.0f;
		bool bNative = false;
		if(n < 0)
		{
			n = -n;
			bNative = true;
		}
		for(int i = n;i > 0;)
		{
			if(i % 2 == 0)
			{
				x = x * x;
				i = i / 2;
			}
			else 
			{
				b = b * x;
				i--;
			}
		}
		if(bNative)
		{
			b = 1.0f / b;
		}
		return b;
	}
private:
	std::map<int,double> m_kSpeedUpMap;
};

int main(int agrc,const char* acParam[])
{
	Solution kS;
	double fRet = kS.myPowB(2,5);
	std::cout << fRet << std::endl;
}