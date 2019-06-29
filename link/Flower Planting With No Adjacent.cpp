#include<iostream>
#include<vector>
#include<deque>
#include<set>

using namespace std;


class Solution 
{
public:
	struct Node
	{
		Node()
		{
			cColor = 0;
			kNears.clear();
			kChooses.clear();
		}
		// cColor -1 it shows has pushed into the bfs deque
		// cColor 0 we don't do anything
		// cColor 1,2,3,4 index its color
		char cColor;
		set<char> kChooses;
		vector<Node*> kNears;
	};

	void MakeGraph(vector<vector<int> >& paths)
	{
		for(int i = 0;i < paths.size();i++)
		{
			int iA = paths[i][0]-1;
			int iB = paths[i][1]-1;
			m_kVecGraph[iA]->kNears.push_back(m_kVecGraph[iB]);
			m_kVecGraph[iB]->kNears.push_back(m_kVecGraph[iA]);
		}
	}

	void FillColor()
	{
		for(int i = 0; i < m_kVecGraph.size();i++)
		{
			Node* pkNode = m_kVecGraph[i];
			if(pkNode->cColor > 0)
			{
				continue;
			}
			deque<Node*> bfs;
			bfs.clear();
			bfs.push_back(pkNode);
			pkNode->cColor = -1;
			while(!bfs.empty())
			{
				int iSize = bfs.size();
				for(int j = 0; j < iSize; j++)
				{
					pkNode = bfs.front();
					bfs.pop_front();
					// if we find color is not zero, it has choosed already
					if(pkNode->cColor <= 0)
					{
						// it can choose any one, we put it one
						if(pkNode->kChooses.empty())
						{
							pkNode->cColor = 1;
							for(int  k = 0; k < pkNode->kNears.size(); k++)
							{
								pkNode->kNears[k]->kChooses.insert(2);
								pkNode->kNears[k]->kChooses.insert(3);
								pkNode->kNears[k]->kChooses.insert(4);
								pkNode->kNears[k]->cColor = -1;
								bfs.push_back(pkNode->kNears[k]);
							}                            
						}
						else
						{
							// if near has already,we must choose the other
							set<char>& kCanChoose = pkNode->kChooses;
							if(kCanChoose.size() == 1)
							{
								pkNode->cColor = *(kCanChoose.begin());
								for(int  k = 0; k < pkNode->kNears.size(); k++)
								{
									if(pkNode->kNears[k]->cColor == 0)
									{
										bfs.push_back(pkNode->kNears[k]);
									}
								}
								kCanChoose.clear();
							}
							else if(kCanChoose.size() == 0)
							{
								// something is wrong
								int i = 3;
							}
							else
							{
								for(int  k = 0; k < pkNode->kNears.size(); k++)
								{
									if(pkNode->kNears[k]->cColor > 0)
									{
										set<char>::iterator iter = kCanChoose.find(pkNode->kNears[k]->cColor);
										if(iter != kCanChoose.end())
										{
											kCanChoose.erase(iter);
										}
									}            
								} 
								pkNode->cColor = *(kCanChoose.begin());
								kCanChoose.clear();

								// put it's near
								vector<Node*> kNextVec;
								for(int  k = 0; k < pkNode->kNears.size(); k++)
								{
									if(pkNode->kNears[k]->cColor <= 0) 
									{
										if(pkNode->kNears[k]->kChooses.empty())
										{
											for(int m = 1;m <=4;m++)
											{
												if(m != pkNode->cColor)
												{
													pkNode->kNears[k]->kChooses.insert(m);
												}
											}
											bfs.push_back(pkNode->kNears[k]);
										}
										else
										{
											set<char>::iterator iter = pkNode->kNears[k]->kChooses.find(pkNode->cColor);
											if(iter != pkNode->kNears[k]->kChooses.end())
											{
												pkNode->kNears[k]->kChooses.erase(iter);
											}
											if(pkNode->kNears[k]->kChooses.size() == 1)
											{
												pkNode->kNears[k]->cColor = *(pkNode->kNears[k]->kChooses.begin());
												pkNode->kNears[k]->kChooses.clear();

												kNextVec.push_back(pkNode->kNears[k]);

											}
											else
											{
												bfs.push_back(pkNode->kNears[k]);
											}
										}
									}            
								}  

								for(int k = 0; k <kNextVec.size();k++)
								{
									for(int m = 0; m < kNextVec[k]->kNears.size();m++)
									{
										if(kNextVec[k]->kNears[m]->cColor == 0)
										{
											bfs.push_back(kNextVec[k]->kNears[m]);
										}
									}
								}
							}
						}
					}
				}
			}

		}
	}

	vector<int> gardenNoAdj(int N, vector<vector<int> >& paths) 
	{
		vector<int> kOut;
		for(int i = 0; i < N; i++)
		{
			Node* pkNode = new Node();
			m_kVecGraph.push_back(pkNode);
		}

		MakeGraph(paths);
		FillColor();
		for(int i = 0; i < N; i++)
		{
			kOut.push_back(m_kVecGraph[i]->cColor);
		}

		return kOut;
	}
private:
	vector<Node*> m_kVecGraph;
};

int main(int,char**)
{
	Solution ks;
	vector<int> a;
	vector<int> kOut;
	vector<vector<int> > kVec;
	a.clear();
	a.push_back(1);
	a.push_back(2);
	kVec.push_back(a);

	a.clear();
	a.push_back(2);
	a.push_back(3);
	kVec.push_back(a);

	a.clear();
	a.push_back(3);
	a.push_back(1);
	kVec.push_back(a);

	kOut = ks.gardenNoAdj(3,kVec);
	return 0;
}

class Solution {
public:
	vector<int> v[10001];
	map<int,int> colour;
	bool vis[10001]={false};
	queue<pair<int,int>> q;

	void bfs(int n,int x){
		vis[n]=true;
		q.push({n,x});
		while(!q.empty()){
			auto i=q.front();
			q.pop();
			colour[i.first]=i.second;
			vis[i.first]=true;
			//cout << i.first<<" "<<i.second<<endl;
			for(int j=0;j<v[i.first].size();j++){
				if(!vis[v[i.first][j]]){
					q.push({v[i.first][j],i.second+1});
				}
			}
		}
	}


	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<int> *adj = new vector<int>[N];
		for(int i = 0;i<paths.size();i++){               // Constructing the graph
			int x = paths[i][0],y = paths[i][1];
			adj[x - 1].push_back(y - 1);
			adj[y - 1].push_back(x - 1);
		}

		vector<int> ans;
		for(int i = 0;i<N;i++){
			ans.push_back(0);
		}

		for(int i = 0;i<N;i++){
			bool col[4] = {false};
			for(int j = 0;j<adj[i].size();j++){
				if(ans[adj[i][j]] != 0){
					col[ans[adj[i][j]] - 1] = true;
				}
			}

			for(int j = 0;j<4;j++){
				if(!col[j]){
					ans[i] = j + 1;
					break;
				}
			}
		}
		return ans;

	}
};

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
	vector<int> res(N);
	vector<vector<int>> g(N);
	for (auto p : paths) {
		g[p[0] - 1].push_back(p[1] - 1);
		g[p[1] - 1].push_back(p[0] - 1);
	}
	for (auto i = 0; i < N; ++i) {
		bool used[5] = {};
		for (auto j : g[i]) used[res[j]] = true;
		for (auto fl = 1; fl <= 4; ++fl) {
			if (!used[fl]) res[i] = fl;
		}
	}
	return res;
}