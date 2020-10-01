#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(int start,vector<int>* v,int n)
{
	queue<int> q;
	q.push(1);
	bool* visited=new bool[n+1];
	for(int i=0;i<=n;i++)
	visited[i]=false;
	visited[1]=true;
	while(!q.empty())
	{
		int y=q.front();
		cout << y << endl;
		q.pop();
		for(int i=0;i<v[y].size();i++)
		{
			if(!visited[v[y][i]])
			{
				q.push(v[y][i]);
				visited[v[y][i]]=true;
			}
		}
	}
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>* v=new vector<int>[n+1];
    for(int i=0;i<m;i++)
    {
    	int x,y;
    	cin >> x >> y;
    	v[x].push_back(y);
    	v[y].push_back(x);
	}
	bfs(1,v,n);

}

