#include "AFindMap.h"
#include <iostream>

BeFindPath::BeFindPath()
{
    m_bCanObliqueMove = false;
    m_iMapWidth = 0;
    m_iMapHeight = 0;
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

bool BeFindPath::IsInClostList(int iX,int iY)
{
    for(int i = 0; i <m_kCloseList.size();i++)
    {
        if(m_kCloseList[i].iX == iX && m_kCloseList[i].iY ==iY)
        {
            return true;
        }
    }
    return false;
}

bool BeFindPath::IsInOpenList(int iX,int iY)
{
    for(int i = 0; i <m_kOpenList.size();i++)
    {
        if(m_kOpenList[i].iX == iX && m_kOpenList[i].iY == iY)
        {
            return true;
        }
    }
    return false;
}

void BeFindPath::FindPath(int iStartX,int iStartY,int iEndX,int iEndY)
{
    if(iStartX >= m_iMapWidth || iStartY >= m_iMapHeight || iEndX >= m_iMapWidth || iEndY >= m_iMapHeight)
    {
        return;
    }

    // first add original point
    Point kPointStart(iStartX,iStartY,INT_MAX);
    m_kCloseList.push_back(kPointStart);

    int iPointX = iStartX;
    int iPointY = iStartY;

     // put near 4 point to open list,
     // left,right,up,down
     for(int i = 0; i < 4; i++)
     {
         if((iPointX - 1) >= 0)
         {
             // 
         }
     }
    if(m_bCanObliqueMove)
    {

    }


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