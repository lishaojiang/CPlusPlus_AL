//
//  AFindMapStand.cpp
//  testcplusplus
//
//  Created by lsj on 6/2/19.
//  Copyright © 2019 lsj. All rights reserved.
//

#include "AFindMapStand.hpp"
#include "math.h"


BeFindPathStand::BeFindPathStand()
{
    m_iMapWidth = 0;
    m_iMapHeight = 0;
    m_iStartX = 0;
    m_iStartY = 0;
    m_iEndX = 0;
    m_iEndY = 0;
}

BeFindPathStand::~BeFindPathStand()
{
    // must release node
    ClearOpenAndCloseList();
}

void BeFindPathStand::Init(int iMapWidth,int iMapHeight)
{
    m_iMapWidth = iMapWidth;
    m_iMapHeight = iMapHeight;
    
    for(int i = 0; i < m_iMapHeight;i++)
    {
        for(int j = 0; j < m_iMapWidth;j++)
        {
            GridNode kNode(j,i,1,0);
            m_kMapGridNodes.push_back(kNode);
        }
    }
}

void BeFindPathStand::PrintPath()
{
    printf("hello ,first out!\n");
    // one way,put out the direct number
    for(int i = (int)m_kRealPathList.size() - 1;i >= 0;i--)
    {
        printf("Node:X:%d,Y:%d,Cost:%d\n",m_kRealPathList[i]->iX,m_kRealPathList[i]->iY,m_kRealPathList[i]->iH);
    }
    
    printf("hello,second out!\n");
    // the other way ,put out the right picture
    for(int i = 0; i< m_iMapHeight;i++)
    {
        for(int j = 0; j < m_iMapWidth;j++)
        {
            if(GetGridFlag(j,i) > 0)
            {
                printf("#");
            }
            else if(IsInPathList(j,i))
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

void BeFindPathStand::ClearOpenAndCloseList()
{
    for(int i = 0; i < m_kOpenList.size();i++)
    {
        SearchNode* pkNode = m_kOpenList[i];
        delete pkNode;
        //while(pkNode)
        //{
        //SearchNode* pkTemp = pkNode->pkParent;
        //delete pkNode;
        //pkNode = pkTemp;
        //}
    }
    m_kOpenList.clear();
    
    for(int i = 0; i < m_kCloseList.size();i++)
    {
        SearchNode* pkNode = m_kCloseList[i];
        delete pkNode;
        //while(pkNode)
        //{
        //SearchNode* pkTemp = pkNode->pkParent;
        //delete pkNode;
        //pkNode = pkTemp;
        //}
    }
    m_kCloseList.clear();
    
}

void BeFindPathStand::GetPathFromOpenList()
{
    if(m_kOpenList.empty())
    {
        return;
    }
    m_kRealPathList.clear();
    
    SearchNode* pkNode = m_kOpenList[0];
    while(pkNode)
    {
        m_kRealPathList.push_back(pkNode);
        pkNode = pkNode->pkParent;
    }
}

void BeFindPathStand::FindPath(int iStartX,int iStartY,int iEndX,int iEndY)
{
    if(!CheckValidGrid(iStartX,iStartY))
    {
        return;
    }
    if(!CheckValidGrid(iEndX,iEndY))
    {
        return;
    }
    
    // delete lists
    ClearOpenAndCloseList();
    
    // set some values
    m_iStartX = iStartX;
    m_iStartY = iStartY;
    m_iEndX = iEndX;
    m_iEndY = iEndY;
    
    // first put start point to openlist
    float fDistance = 0.0f;//GetDistance(m_iStartX,m_iStartY,m_iEndX,m_iEndY);
    SearchNode* pkNode = new SearchNode(m_iStartX,m_iStartY,0,fDistance,fDistance,NULL);
    m_kOpenList.push_back(pkNode);
    
    
    while(!m_kOpenList.empty())
    {
        pkNode = m_kOpenList[0];
        if(pkNode->iX == m_iEndX && pkNode->iY == m_iEndY)
        {
            // have find the node
            break;
        }
        
        
        m_kCloseList.push_back(pkNode);
        
        // find the sound points
        for(int i = 0; i < SEARCH_MAX_DIRECT; i++)
        {
            int iPointX = pkNode->iX + g_iSearchDirect[i][0];
            int iPointY = pkNode->iY + g_iSearchDirect[i][1];
            if(!CheckValidGrid(iPointX,iPointY))
            {
                continue;
            }
            if(IsInCloseList(iPointX,iPointY))
            {
                continue;
            }
            if(GetGridFlag(iPointX,iPointY) > 0)
            {
                continue;
            }
            int iCost = GetGridCost(iPointX,iPointY) + pkNode->iH;
            float fDistance = GetDistance(iPointX,iPointY,m_iEndX,m_iEndY);
            if(IsInOpenList(iPointX,iPointY))
            {
                // if the origin fN is big than this,replace this node
                SearchNode* pkOriNode = GetNodeFromOpenList(iPointX,iPointY);
                if(pkOriNode && pkOriNode->fN > (fDistance + iCost))
                {
                    pkOriNode->fN = fDistance + iCost;
                    pkOriNode->iH = iCost;
                    pkOriNode->fG = fDistance;
                    pkOriNode->pkParent = pkNode;
                }
            }
            else
            {
                // push new node into openlist
                SearchNode* pkNSNode = new SearchNode(iPointX,iPointY,iCost,fDistance,iCost + fDistance,pkNode);
                m_kOpenList.push_back(pkNSNode);
            }
        }
        
        // remove this node from openlist
        m_kOpenList.erase(m_kOpenList.begin());
        
        // sort open list
        std::sort(m_kOpenList.begin(),m_kOpenList.end(),CompareSearchNodeByLess);
        
    }
}


void BeFindPathStand::SetGridFlag(int iX,int iY,int iFlag)
{
    if(!CheckValidGrid(iX,iY))
    {
        return;
    }
    m_kMapGridNodes[iX + iY * m_iMapWidth].iFlag = iFlag;
}


int  BeFindPathStand::GetGridFlag(int iX,int iY)
{
    if(!CheckValidGrid(iX,iY))
    {
        return 0;
    }
    return m_kMapGridNodes[iX + iY * m_iMapWidth].iFlag;
}

void BeFindPathStand::SetGridCost(int iX,int iY,int iCost)
{
    if(!CheckValidGrid(iX,iY))
    {
        return;
    }
    m_kMapGridNodes[iX + iY * m_iMapWidth].iCost = iCost;
}

int BeFindPathStand::GetGridCost(int iX,int iY)
{
    if(!CheckValidGrid(iX,iY))
    {
        return INT_MAX;
    }
    return m_kMapGridNodes[iX + iY * m_iMapWidth].iCost;
}

bool BeFindPathStand::CheckValidGrid(int iX,int iY)
{
    if(iX >= m_iMapWidth || iX < 0 || iY >= m_iMapHeight || iY < 0)
    {
        return false;
    }
    return true;
}

bool BeFindPathStand::IsInCloseList(int iX,int iY)
{
    if(!CheckValidGrid(iX,iY))
    {
        return false;
    }
    for(int i = 0; i < m_kCloseList.size();i++)
    {
        SearchNode* pkNode = m_kCloseList[i];
        if(pkNode->iX == iX && pkNode->iY == iY)
        {
            return true;
        }
    }
    return false;
}

bool BeFindPathStand::IsInOpenList(int iX,int iY)
{
    if(!CheckValidGrid(iX,iY))
    {
        return false;
    }
    for(int i = 0;i < m_kOpenList.size();i++)
    {
        SearchNode* pkNode = m_kOpenList[i];
        if(pkNode->iX == iX && pkNode->iY == iY)
        {
            return true;
        }
    }
    return false;
}

bool BeFindPathStand::IsInPathList(int iX,int iY)
{
    for(int i = 0;i < (int)m_kRealPathList.size();i++)
    {
        SearchNode* pkNode = m_kRealPathList[i];
        if(pkNode->iX == iX && pkNode->iY == iY)
        {
            return true;
        }
    }
    return false;
}

SearchNode* BeFindPathStand::GetNodeFromOpenList(int iX,int iY)
{
    SearchNode* pkRetNode = NULL;
    if(!CheckValidGrid(iX,iY))
    {
        return pkRetNode;
    }
    for(int i = 0;i < m_kOpenList.size();i++)
    {
        SearchNode* pkNode = m_kOpenList[i];
        if(pkNode->iX == iX && pkNode->iY == iY)
        {
            pkRetNode = pkNode;
            break;
        }
    }
    return pkRetNode;
}

float BeFindPathStand::GetDistance(int iX1,int iY1,int iX2,int iY2)
{
    //return float(abs(iX1-iX2) + abs(iY1-iY2));
    return sqrt((iX1-iX2)*(iX1-iX2) + (iY1-iY2)*(iY1-iY2));
}

bool CompareSearchNodeByLess(SearchNode*  pkLeft,SearchNode*  pkRight)
{
    if(pkLeft->fN < pkRight->fN)
    {
        return true;
    }
    else if (pkLeft->fN == pkRight->fN)
    {
        if(pkLeft->iH > pkRight->iH)
        {
            return true;
        }
    }
    return false;
}

//int main(int iagrs,const char* pcParam[])
//{
//    //    BeFindPath kPath;
//    //    kPath.Initilize(5,5);
//    //    //    for(int i = 0; i < 4;i++)
//    //    //    {
//    //    //        kPath.SetGridBlock(1+i,3,1);
//    //    //    }
//    //    kPath.SetGridBlock(3,3,1);
//    //    kPath.FindPath(1,1,4,4);
//    //    kPath.PrintPath();
//    //
//    BeFindPathStand kPathStand;
//    kPathStand.Init(10,10);
//    //kPathStand.SetGridFlag(3,3,1);
//    for(int i = 0; i < 7;i++)
//    {
//        kPathStand.SetGridFlag(3+i,7,1);
//    }
//    kPathStand.FindPath(1,1,9,9);
//    kPathStand.GetPathFromOpenList();
//    kPathStand.PrintPath();
//    
//    
//    return 0;
//}

