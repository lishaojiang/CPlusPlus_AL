#include "AFindMap.h"
#include <iostream>

BeFindPath::BeFindPath()
{

}

BeFindPath::~BeFindPath()
{

}

void BeFindPath::Initilize(int iMapWidth,int iMapHeight)
{
    for(int i = 0; i < iMapWidth; i++)
    {
        for(int j = 0; j < iMapHeight;j++)
        {
            Grid kGrid(i,j,1,0);
            m_kMapGrid.push_back(kGrid);
        }
    }
}

void BeFindPath::Finilize()
{

}

void BeFindPath::SetBlock(int iX,int iY,BYTE byFlag)
{
    if(iX >= m_iMapWidth)
        return;
    if(iY >= m_iMapHeight)
        return;
    
    m_kMapGrid[iX + iY * m_iMapWidth].byFlag = byFlag;
}


BYTE BeFindPath::GetBlock(int iX,int iY)
{
    BYTE byRet = 0;
    if(iX >= m_iMapWidth)
        return byRet;
    if(iY >= m_iMapHeight)
        return byRet;
    
    byRet = m_kMapGrid[iX + iY * m_iMapWidth].byFlag;
    return byRet;
}

void BeFindPath::FindPath(int iStartX,int iStartY,int iEndX,int iEndY)
{

}

void BeFindPath::PrintPath()
{
    printf("hello ,we will put out path!\n");
}


int main(int iagrs,const char* pcParam[])
{
    BeFindPath kPath;
    kPath.Initilize(15,15);
    kPath.FindPath(3,5,7,8);
    kPath.PrintPath();
    return 0;
}