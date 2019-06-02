#include "AFindMap.hpp"
#include <iostream>
#include <math.h>

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
    m_iMapWidth = iMapWidth;
    m_iMapHeight = iMapHeight;
}

void BeFindPath::Finilize()
{

}

void BeFindPath::SetGridBlock(int iX,int iY,BYTE byFlag)
{
    if(iX >= m_iMapWidth)
        return;
    if(iY >= m_iMapHeight)
        return;
    
    m_kMapGrid[iX + iY * m_iMapWidth].byFlag = byFlag;
}


BYTE BeFindPath::GetGridBlock(int iX,int iY)
{
    BYTE byRet = 0;
    if(iX >= m_iMapWidth)
        return byRet;
    if(iY >= m_iMapHeight)
        return byRet;
    
    byRet = m_kMapGrid[iX + iY * m_iMapWidth].byFlag;
    return byRet;
}

void BeFindPath::SetGridCost(int iX,int iY,int iCost)
{
    if(iX >= m_iMapWidth || iY >= m_iMapHeight)
    {
        return;
    }

    m_kMapGrid[iX + iY * m_iMapHeight].iValue = iCost;
}

int BeFindPath::GetGridCost(int iX,int iY)
{
    if(iX >= m_iMapWidth || iY >= m_iMapHeight)
    {
        return INT_MAX;
    }

    return m_kMapGrid[iX + iY * m_iMapHeight].iValue;
}

float BeFindPath::GetDistance(int iX,int iY,int iEndX,int iEndY)
{
    float fRet = 0.0f;
    fRet = sqrt((iX-iEndX)*(iX-iEndX) + (iY-iEndY)*(iY-iEndY));
    return fRet;
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

bool BeFindPath::IsInGridInPath(int iX,int iY)
{
    for(int i = 0; i <m_kPathList.size();i++)
    {
        if(m_kPathList[i][0].iX == iX && m_kPathList[i][0].iY == iY)
        {
            return true;
        }
    }
    return false;
}

float BeFindPath::extracted(int iX, int iY) {
    return GetDistance(iX,iY,m_iEndX,m_iEndY);
}

void BeFindPath::ChangeOpenListCost(int iX,int iY,int iCost)
{
    if(IsInOpenList(iX,iY))
    {
        for(int i = 0; i < m_kOpenList.size();i++)
        {
            if(m_kOpenList[i].iX == iX && m_kOpenList[i].iY == iY)
            {
                if(m_kOpenList[i].iHaveCost > iCost)
                {
                    m_kOpenList[i].iHaveCost = iCost;
                }
            }
        }
    }
    else
    {
        float fDis = extracted(iX, iY);
        Point kPoint(iX,iY,iCost,fDis);
        m_kOpenList.push_back(kPoint);
    }
    
}



void BeFindPath::AddPointInCloseList(int iX,int iY)
{
    if(iX >= m_iMapWidth || iY >= m_iMapHeight || iX < 0 || iY < 0)
    {
        return;
    }

    Point kPoint(iX,iY,INT_MAX,0.0f);
    m_kCloseList.push_back(kPoint);

}

void BeFindPath::AddPointInOpenList(int iX,int iY,int iHaveCost,std::vector<Point>& rkList)
{
    if(iX >= m_iMapWidth || iY >= m_iMapHeight || iX < 0 || iY < 0)
    {
        return;
    }

    if(IsInClostList(iX,iY))
    {
        return;
    }

    int iCost = iHaveCost + GetGridCost(iX,iY);
    int fCost = GetDistance(iX,iY,m_iEndX,m_iEndY);
    Point kPoint(iX,iY,iCost,fCost);
    rkList.push_back(kPoint);

    ChangeOpenListCost(iX,iY,iCost);

}

bool BeFindPath::CheckOnePointToFindPath(int iX,int iY,int iNowCost)
{
    std::vector<Point> kNearPoint;
    // we have search this point
    if(IsInClostList(iX,iY))
    {
        return false;
    }
    // there is a block
    if(GetGridBlock(iX,iY) > 0)
    {
        return false;
    }
    // first add to black list
    AddPointInCloseList(iX,iY);

    // put near 4 point to open list,
    // left,right,up,down
    AddPointInOpenList(iX-1,iY,iNowCost,kNearPoint);
    AddPointInOpenList(iX+1,iY,iNowCost,kNearPoint);
    AddPointInOpenList(iX,iY-1,iNowCost,kNearPoint);
    AddPointInOpenList(iX,iY+1,iNowCost,kNearPoint);

    if(kNearPoint.empty())
    {
        return false;
    }
    // choose the small 
    std::sort(kNearPoint.begin(),kNearPoint.end(),STLComparePoint);

    // add neart points to path list
    m_kPathList.push_back(kNearPoint);

    return true;
}

void BeFindPath::FindPath(int iStartX,int iStartY,int iEndX,int iEndY)
{
    if(iStartX >= m_iMapWidth || iStartY >= m_iMapHeight || iEndX >= m_iMapWidth || iEndY >= m_iMapHeight)
    {
        return;
    }

    m_iStartX = iStartX;
    m_iStartY = iStartY;
    m_iEndX = iEndX;
    m_iEndY = iEndY;


    int iPointX = iStartX;
    int iPointY = iStartY;
    int iNowCost = 0;
    float fDistance = GetDistance(iStartX,iStartY,iEndX,iEndY);

    Point kPointSearch(iPointX,iPointY,iNowCost,fDistance);
    std::vector<Point> kVec;
    kVec.push_back(kPointSearch);
    m_kPathList.push_back(kVec);

    while(!m_kPathList.empty())
    {
        int iSize = (int)m_kPathList.size();
        iPointX = m_kPathList[iSize -1][0].iX;
        iPointY = m_kPathList[iSize -1][0].iY;
        iNowCost = m_kPathList[iSize -1][0].iHaveCost;
        
        if(iPointX == iEndX && iPointY == iEndY)
        {
            // find it
            break;
        }
        
        if(CheckOnePointToFindPath(iPointX,iPointY,iNowCost))
        {
            
        }
        else
        {
            // dead path,should throw one point from list
            int iSize = (int)m_kPathList.size();
            m_kPathList[iSize-1].erase(m_kPathList[iSize-1].begin());
            if(m_kPathList[iSize-1].empty())
            {
                m_kPathList.erase(m_kPathList.begin() + iSize - 1);
            }
        }

    }
}

void BeFindPath::PrintPath()
{
    printf("hello ,first out!\n");
    // one way,put out the direct number
    for(int i = 0;i < m_kPathList.size();i++)
    {
        printf("Node:X:%d,Y:%d,Cost:%d\n",m_kPathList[i][0].iX,m_kPathList[i][0].iY,m_kPathList[i][0].iHaveCost);
    }

    printf("hello,second out!\n");
    // the other way ,put out the right picture
    for(int i = 0; i< m_iMapHeight;i++)
    {
        for(int j = 0; j < m_iMapWidth;j++)
        {
            if(GetGridBlock(j,i) > 0)
            {
                printf("#");
            }
            else if(IsInGridInPath(j,i))
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

bool STLComparePoint(const Point & rkLeft,const Point & rkRight)
{
    if((rkLeft.fCost + rkLeft.iHaveCost) < (rkRight.fCost + rkRight.iHaveCost))
    {
        return true;
    }
    return false;
}
