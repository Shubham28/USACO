#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

int V;

int mr[]={-1,1,0,0};
int mc[]={0,0,-1,1};

char grid[6][6];
bool vist[6][6];

int L;
char path[30];

int DFS(int r,int c)
{
	path[L++]=grid[r][c];
	vist[r][c]=1;

	int opn=count(path,path+L,'(');
	int cls=count(path,path+L,')');

	int bst=0;
	if(opn==cls)
		bst=max(bst,2*opn);

	bool open=(path[L-1]=='(');
	FOR(i,0,4){
		int nr=r+mr[i];
		int nc=c+mc[i];

		if(0<=nr && nr<V && 0<=nc && nc<V && !vist[nr][nc] && (open || (grid[nr][nc]==')' && opn>cls)))
			bst=max(bst,DFS(nr,nc));
	}

	L--;
	vist[r][c]=0;

	return bst;
}

int main()
{
	freopen("hshoe.in","r",stdin);
	freopen("hshoe.out","w",stdout);

	scanf("%d",&V);
	FOR(i,0,V)
		scanf("%s",grid[i]);

	int ans=0;
	if(grid[0][0]=='('){
		MEM(vist,0);

		L=0;
		ans=DFS(0,0);
	}
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
