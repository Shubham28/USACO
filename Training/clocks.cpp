/*
ID: celesti3
PROG: clocks
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
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int movs[][5]={{0,1,3,4,-1},{0,1,2,-1,-1},{1,2,4,5,-1},{0,3,6,-1,-1},{1,3,4,5,7},{2,5,8,-1,-1},{3,4,6,7,-1},{6,7,8,-1,-1},{4,5,7,8,-1}};

void reCnv(int num,int ans[])
{
	RFOR(all,8,0){
		int lst=num&3;

		if(lst==0)		ans[all]=12;
		else if(lst==1)		ans[all]=3;
		else if(lst==2)		ans[all]=6;
		else if(lst==3)		ans[all]=9;

		num>>=2;
	}
	return;
}

int cnvInt(int tmp[])
{
	int ret=0;
	FOR(all,0,9){
		int val=0;
		if(tmp[all]==3)		val=1;
		else if(tmp[all]==6)	val=2;
		else if(tmp[all]==9)	val=3;

		ret+=val;
		ret<<=2;
	}
	ret>>=2;
	return ret;
}

int par[(1<<18)+1],path[(1<<18)+1];

void prntPath(int child)
{
	if(par[child]==-5)		return;

	prntPath(par[child]);
	printf("%d",path[child]+1);
	printf((child!=0)?" ":"\n");

	return;
}

int main()
{
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);

	int tmp[9],chng[9];
	FOR(inp,0,9)
		scanf("%d",&tmp[inp]);

	queue<int>brd;
	MEM(par,-1);
	MEM(path,-1);

	int root=cnvInt(tmp);
	brd.push(root);
	par[root]=-5,path[root]=-5;

	while(!brd.empty()){
		int prs=brd.front();
		brd.pop();

		if(prs==0)
			break;
		else {
			reCnv(prs,tmp);
			FOR(chk,0,9){
				memcpy(chng,tmp,sizeof(tmp));
				FOR(rt,0,5)
					if(movs[chk][rt]!=-1){
						chng[movs[chk][rt]]+=3;
						chng[movs[chk][rt]]%=12;
						if(chng[movs[chk][rt]]==0)		chng[movs[chk][rt]]=12;
					}

				int frm=cnvInt(chng);
				if(par[frm]==-1){
					brd.push(frm);
					par[frm]=prs,path[frm]=chk;
				}
			}
		}
	}
	prntPath(0);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
