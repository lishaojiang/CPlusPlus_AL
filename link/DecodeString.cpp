#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    Node()
    {
        iTimes = 1;
        kString = "";
        akChilds.clear();
        pkParent = NULL;
        bHasDeal = false;
    }
    int iTimes;
    bool bHasDeal;
    string kString;
    vector<Node*> akChilds;
    Node* pkParent;
};

bool IsDigitalNumber(char c)
{
    if(c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

string DecodeString(string s)
{
    string kOutString;
    stack<Node*> kNodeStack;
    const char* pcStr = s.c_str();
    //Node* pkRootNode = new Node();

    // some param
    const char* pcStrBegin = NULL;
    char acTemp[12] = {0};
    string kSAdd = "";
    int iGetTimes = 1;
    // Node* pkParentRoot = pkRootNode;
    // kNodeStack.push(pkParentRoot);

    // buld the tree
    while(*pcStr)
    {
        if(IsDigitalNumber(*pcStr))
        {
            pcStrBegin = pcStr;
            while(*pcStr && *pcStr != '[')
            {
                pcStr++;
            }
            
            memset(acTemp,0,sizeof(acTemp));
            memcpy(acTemp,pcStrBegin,pcStr-pcStrBegin);
            iGetTimes = atoi(acTemp);
            // break the '[' node
            pcStr++;

            // pcStrBegin = pcStr;
            // while(*pcStr && *pcStr != ']' && !IsDigitalNumber(*pcStr))
            // {
            //     pcStr++;
            // }

            // kSAdd = "";
            // kSAdd.append(pcStrBegin,pcStr - pcStrBegin);

            Node* pkNewNode = new Node();
            pkNewNode->iTimes = iGetTimes;
            pkNewNode->kString = "";
            if(kNodeStack.empty())
            {
                pkNewNode->pkParent = NULL;
            }
            else
            {
                Node* pkGetParent = kNodeStack.top();
                pkNewNode->pkParent = pkGetParent;

                // put into parent vectors
                pkGetParent->akChilds.push_back(pkNewNode);
            }

            kNodeStack.push(pkNewNode);
            
        }
        else if(*pcStr == ']')
        {
            pcStr++;

            kSAdd = "";
            Node* pkCurrentNode = kNodeStack.top();
            for(int iIndex = 0; iIndex < pkCurrentNode->akChilds.size();iIndex++)
            {
                kSAdd += pkCurrentNode->akChilds[iIndex]->kString;
            }

            string kTempS = "";
            for(int i = 0; i < pkCurrentNode->iTimes;i++)
            {
                kTempS += kSAdd;
            }

            pkCurrentNode->kString = kTempS;

            pkCurrentNode->bHasDeal = true;
            // delete this node after use
            kNodeStack.pop();

            if(kNodeStack.empty())
            {
                // output to the origin string
                kOutString += kTempS;
            }
        }
        else
        {
            pcStrBegin = pcStr;
            while(*pcStr && !IsDigitalNumber(*pcStr) && *pcStr != ']')
            {
                pcStr++;
            }

            kSAdd = "";
            kSAdd.append(pcStrBegin,pcStr - pcStrBegin);
            if(kNodeStack.empty())
            {
                kOutString += kSAdd;
            }
            else
            {
                Node* pkNewNode = new Node();
                pkNewNode->iTimes = 1;
                pkNewNode->kString = kSAdd;
                Node* pkGetParent = kNodeStack.top();
                pkNewNode->pkParent = pkGetParent;

                // put into parent vectors
                pkGetParent->akChilds.push_back(pkNewNode);
            }

        }
    }

    // get the node from the tree

    return kOutString;
}

int main(int iNums,const char* pcAgrc[])
{
    string s = "ab3[cd2[mn]kj]ef";
    string sRet = DecodeString(s);
    printf("%s",sRet.c_str());
    return 0;
}