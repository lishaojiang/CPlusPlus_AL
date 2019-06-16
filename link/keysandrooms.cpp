#include<iostream>
#include<vector>
#include<map>
#include<stack>


using namespace std;

// fuction I,DFS ,test success
void CanVisit_DFS(vector<vector<int>  >& rooms,map<int,int>& kMapVisited,int iIndex,bool& bSuccess)
{
    if(kMapVisited.find(iIndex) != kMapVisited.end())
    {
        // we have visit this node, do nothing
    }
    else
    {
        kMapVisited[iIndex] = 1;
        if(kMapVisited.size() == rooms.size())
        {
            bSuccess = true;
        }
        //visit it's children
        for(int j = 0;j < rooms[iIndex].size();j++)
        {
            CanVisit_DFS(rooms,kMapVisited,rooms[iIndex][j],bSuccess);
        }
    }
}

// functin II,BFS, test success
bool CanVisit_BFS(vector<vector<int> >& rooms)
{
    stack<int> keys;
    map<int,int> kRoomMap;
    if(rooms.size() <= 0)
    {
        return true;
    }
    
    // put first rooom's keys into stack
    kRoomMap[0] = 1;
    for(int j = 0;j < rooms[0].size();j++)
    {
        keys.push(rooms[0][j]);
    }

    while(!keys.empty())
    {
        int iIndexRoom = keys.top();
        keys.pop();

        if(kRoomMap.find(iIndexRoom) == kRoomMap.end())
        {
            kRoomMap[iIndexRoom] = 1;
            for(int j = 0;j < rooms[iIndexRoom].size();j++)
            {
                keys.push(rooms[iIndexRoom][j]);
            }
        }  
    }

    if(kRoomMap.size() < rooms.size())
    {
        return false;
    }
    return true;
}

bool canVisitAllRooms(vector<vector<int> >& rooms)
{
    bool bSuccess = false;
    int iIndex = 0;
    map<int,int> kMap;
    CanVisit_DFS(rooms,kMap,iIndex,bSuccess);
    return bSuccess;
}

int main(int iAgrc,const char* pcParam[])
{
    return 0;
}