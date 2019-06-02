//
//  AFindMapStand.hpp
//  testcplusplus
//
//  Created by lsj on 6/2/19.
//  Copyright © 2019 lsj. All rights reserved.
//

#pragma once

#ifndef AFindMapStand_hpp
#define AFindMapStand_hpp

#include <vector>

#define SEARCH_MAX_DIRECT 4


// f(n)= h(n) +g(n);

struct GridNode
{
    GridNode()
    {
        iX = 0;
        iY = 0;
        iCost = 0;
        iFlag = 0;
    }
    
    GridNode(int X,int Y,int Cost,int Flag)
    {
        iX = X;
        iY = Y;
        iCost = Cost;
        iFlag = Flag;
    }
    int iX;
    int iY;
    int iCost;
    int iFlag;
};

struct SearchNode
{
    SearchNode()
    {
        iX = 0;
        iY = 0;
        iH = 0;
        fG = 0.0f;
        fN = 0.0f;
        pkParent = NULL;
    }
    
    SearchNode(int X,int Y,int H,float G,float N,SearchNode* pkParentNode)
    {
        iX = X;
        iY = Y;
        iH = H;
        fG = G;
        fN = N;
        pkParent = pkParentNode;
    }
    
    int iX;
    int iY;
    int iH;
    float fG;
    float fN;
    SearchNode* pkParent;
};


const int g_iSearchDirect[SEARCH_MAX_DIRECT][2] = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1},
};


bool CompareSearchNodeByLess(SearchNode*  pkLeft,SearchNode*  pkRight);

class BeFindPathStand
{
public:
    BeFindPathStand();
    ~BeFindPathStand();
    
    void Init(int iMapWidth,int iMapHeight);
    void FindPath(int iStartX,int iStartY,int iEndX,int iEndY);
    void GetPathFromOpenList();
    void PrintPath();
    void ClearOpenAndCloseList();
    
    void SetGridFlag(int iX,int iY,int iFlag);
    int  GetGridFlag(int iX,int iY);
    void SetGridCost(int iX,int iY,int iCost);
    int  GetGridCost(int iX,int iY);
    bool CheckValidGrid(int iX,int iY);
    
    
    float GetDistance(int iX1,int iY1,int iX2,int iY2);
    
    bool IsInCloseList(int iX,int iY);
    bool IsInOpenList(int iX,int iY);
    bool IsInPathList(int iX,int iY);
    SearchNode* GetNodeFromOpenList(int iX,int iY);
    
protected:
    std::vector<GridNode> m_kMapGridNodes;
    
    int m_iMapWidth;
    int m_iMapHeight;
    int m_iStartX;
    int m_iStartY;
    int m_iEndX;
    int m_iEndY;
    
    std::vector<SearchNode*> m_kOpenList;
    std::vector<SearchNode*> m_kCloseList;
    
    std::vector<SearchNode*> m_kRealPathList;    
};

#endif /* AFindMapStand_hpp */

