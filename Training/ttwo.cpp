/*
ID: celesti3
PROG: ttwo
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
#define LL long long

using namespace std;

inline void rot(int dirn[])
{
	if(dirn[0]==-1 && dirn[1]==0)				dirn[0]=0,dirn[1]=1;
	else if(dirn[0]==0 && dirn[1]==1)			dirn[0]=1,dirn[1]=0;
	else if(dirn[0]==1 && dirn[1]==0)			dirn[0]=0,dirn[1]=-1;
	else if(dirn[0]==0 && dirn[1]==-1)			dirn[0]=-1,dirn[1]=0;
}

int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);

	char inp[11][11];
	int cwS[2],frmS[2];

	FOR(a,0,10){
		scanf("%s",inp[a]);

		int ind=find(inp[a],inp[a]+10,'C')-inp[a];
		if(ind!=10)
			cwS[0]=a,cwS[1]=ind;

		ind=find(inp[a],inp[a]+10,'F')-inp[a];
		if(ind!=10)
			frmS[0]=a,frmS[1]=ind;
	}

	int drC[]={-1,0};
	int drF[]={-1,0};

	bool psb=0;
	int tot=0;
	while(tot<160000){
		if(cwS[0]==frmS[0] && cwS[1]==frmS[1]){
			psb=1;
			break;
		}

		++tot;

		int x=cwS[0]+drC[0];
		int y=cwS[1]+drC[1];

		if(x<0 || y<0 || x>=10 || y>=10 || inp[x][y]=='*'){
			rot(drC);
			x=cwS[0],y=cwS[1];
		} else {
			inp[cwS[0]][cwS[1]]='.';
			cwS[0]=x,cwS[1]=y;
		}

		int prs;
		if(drC[0]==-1 && drC[1]==0)		prs=0;
		if(drC[0]==0 && drC[1]==1)		prs=1;
		if(drC[0]==1 && drC[1]==0)		prs=2;
		if(drC[0]==0 && drC[1]==-1)		prs=3;

		x=frmS[0]+drF[0];
		y=frmS[1]+drF[1];

		if(x<0 || y<0 || x>=10 || y>=10 || inp[x][y]=='*')
			rot(drF);
		else {
			inp[frmS[0]][frmS[1]]='.';
			frmS[0]=x,frmS[1]=y;
		}
		inp[cwS[0]][cwS[1]]='C';
		inp[frmS[0]][frmS[1]]='F';
	}

	printf("%d\n",(psb)?tot:0);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
