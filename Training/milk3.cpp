/*
ID: celesti3
PROG: milk3
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

void reCnv(int mask,int ans[])
{
	ans[2]=mask&(31);
	mask>>=5;
	ans[1]=mask&(31);
	mask>>=5;
	ans[0]=mask&(31);

	return;
}

int cnvInt(int qnt[3])
{
	int ret=0;
	ret+=qnt[0];
	ret<<=5;
	ret+=qnt[1];
	ret<<=5;
	ret+=qnt[2];

	return ret;
}

int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);

	int tot[3];
	scanf("%d %d %d",&tot[0],&tot[1],&tot[2]);

	int ans[1000],btl[3],tmp[3];
	bool vist[(1<<15)+5];
	int L=0;

	btl[0]=btl[1]=0;
	btl[2]=tot[2];
	MEM(vist,0);

	queue<int>brd;
	int root=cnvInt(btl);
	brd.push(root);
	vist[root]=1;

	while(!brd.empty()){
		int prs=brd.front();
		brd.pop();

		reCnv(prs,btl);
		if(btl[0]==0)
			ans[L++]=btl[2];

		FOR(frm,0,3)	FOR(to,0,3)
			if(frm!=to && btl[frm]>0){
				memcpy(tmp,btl,sizeof(btl));

				int pour=(tmp[frm]<=(tot[to]-tmp[to]))?tmp[frm]:(tot[to]-tmp[to]);
				tmp[frm]-=pour,tmp[to]+=pour;

				int nxt=cnvInt(tmp);
				if(!vist[nxt]){
					brd.push(nxt);
					vist[nxt]=1;
				}
			}
	}

	if(L>1){
		sort(ans,ans+L);
		FOR(pr,0,L-1)
			printf("%d ",ans[pr]);
		printf("%d\n",ans[L-1]);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
