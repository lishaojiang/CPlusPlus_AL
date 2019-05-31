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
    }
    int iX;
    int iY;
};
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

    void SetBlock(int iX,int iY,BYTE iFlag);
    BYTE GetBlock(int iX,int iY);

    void PrintPath();



private:
    int m_iMapWidth;
    int m_iMapHeight;
    std::vector<Grid> m_kMapGrid;
    std::vector<Point> m_kOpenList;
};

#endif