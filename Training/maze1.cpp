/*
ID: celesti3
PROG: maze1
LANG: C++
*/


#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <numeric>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define PII pair<int,int>
#define MP(A,B) make_pair(A,B)

using namespace std;

int H,W;
string grid[205];
int dist[2][101][40];

int dy[]={-1,0,0,1};
int dx[]={0,-1,1,0};

void BFS(PII src,int nm)
{
	queue< PII >brd;
	MEM(dist[nm],-1);

	brd.push(src);
	dist[nm][src.first/2][src.second/2]=1;

	while(!brd.empty()){
		int R=brd.front().first,C=brd.front().second;
		brd.pop();

		FOR(a,0,4){
			int tr=R+2*dy[a],tc=C+2*dx[a];
			if(0<=tr && tr<2*H+1 && 0<=tc && tc<2*W+1 && grid[R+dy[a]][C+dx[a]]==' ' && dist[nm][tr/2][tc/2]==-1){
				brd.push(MP(tr,tc));
				dist[nm][tr/2][tc/2]=dist[nm][R/2][C/2]+1;
			}
		}
	}
	return;
}

int main()
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);

	scanf("%d %d",&W,&H);
	FOR(a,0,2*H+1){
		string tmp;
		getline(cin,tmp);
		while(SZ(tmp)<2*W+1)
			getline(cin,tmp);

		grid[a]=tmp;
	}

	int nm=0;
	for(int cl=1;cl<2*W+1;cl+=2){
		if(grid[0][cl]==' ')
			BFS(MP(1,cl),nm++);

		if(grid[2*H][cl]==' ')
			BFS(MP(2*H-1,cl),nm++);
	}

	for(int rw=1;rw<2*H+1;rw+=2){
		if(grid[rw][0]==' ')
			BFS(MP(rw,1),nm++);

		if(grid[rw][2*W]==' ')
			BFS(MP(rw,2*W-1),nm++);
	}

	int ans=0;
	FOR(rw,0,H)		FOR(cl,0,W)
		ans=max(ans,min(dist[0][rw][cl],dist[1][rw][cl]));
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
