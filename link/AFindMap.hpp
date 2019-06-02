#ifndef AFINDMAP_H_
#define AFINDMAP_H_


#include <vector>


typedef unsigned char BYTE;
struct Point
{
    Point ()
    {
        iX = 0;
        iY = 0;
        iHaveCost = INT_MAX;
        fCost = INT_MAX;
    }

    Point(int X,int Y ,int HaveCost, float Cost)
    {
        iX = X;
        iY = Y;
        iHaveCost = HaveCost;
        fCost = Cost;
    }

    int iX;
    int iY;
    int iHaveCost;
    float fCost;
};

bool STLComparePoint(const Point & rkLeft,const Point & rkRight);

struct Grid
{
    Grid ()
    {
        iX = 0;
        iY = 0;
        iValue = 0;
        byFlag = 0;
    }

    Grid(int X,int Y,int Value,BYTE Flag)
    {
        iX = X;
        iY = Y;
        iValue = Value;
        byFlag = Flag;
    }


    int iX;
    int iY;
    int iValue;
    BYTE byFlag;
};


class BeFindPath
{
public:
    BeFindPath();
    ~BeFindPath();

    void Initilize(int iMapWidth,int iMapHeight);
    void Finilize();

    void FindPath(int iStartX,int iStartY,int iEndX,int iEndY);

    void SetGridBlock(int iX,int iY,BYTE iFlag);
    BYTE GetGridBlock(int iX,int iY);
    void SetGridCost(int iX,int iY,int iCost);
    int GetGridCost(int iX,int iY);

    float GetDistance(int iX,int iY,int iEndX,int iEndY);

    void PrintPath();

    bool IsInClostList(int iX,int iY);
    bool IsInOpenList(int iX,int iY);
    float extracted(int iX, int iY);
    
    void ChangeOpenListCost(int iX,int iY,int iCost);
    void AddPointInOpenList(int iX,int iY,int iHaveCost,std::vector<Point>& rkList);
    void RemovePointFromOpenList(int iX,int iY);
    void AddPointInCloseList(int iX,int iY);
    void RemovePointFromCloseList(int iX,int iY);
    bool CheckOnePointToFindPath(int iX,int iY,int iNowCost);
    bool IsInGridInPath(int iX,int iY);


private:
    int m_iMapWidth;
    int m_iMapHeight;
    int m_iStartX;
    int m_iStartY;
    int m_iEndX;
    int m_iEndY;
    bool m_bCanObliqueMove;                 // can move obliqued
    std::vector<Grid> m_kMapGrid;
    std::vector<Point> m_kOpenList;
    std::vector<Point> m_kCloseList;
    std::vector< std::vector<Point> > m_kPathList;
};

#endif
