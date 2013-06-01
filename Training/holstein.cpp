/*
ID: celesti3
PROG: holstein
LANG: C++
*/


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

using namespace std;

int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);

	int V,G;
	int rq[25],amt[15][25];

	scanf("%d",&V);
	FOR(in,0,V)
		scanf("%d",&rq[in]);

	scanf("%d",&G);
	FOR(in,0,G)		FOR(j,0,V)
		scanf("%d",&amt[in][j]);

	int ans=20,opt;
	int prs[25];

	FOR(all,1,1<<G){
		int tmp=__builtin_popcount(all);
		if(tmp>=ans)		continue;

		MEM(prs,0);
		FOR(ms,0,G)
			if((all>>ms)&1){
				FOR(ad,0,V)
					prs[ad]+=amt[ms][ad];
			}

		bool dn=1;
		FOR(vt,0,V)
			if(prs[vt]<rq[vt]){
				dn=0;
				break;
			}

		if(dn && ans>tmp)
			ans=tmp,opt=all;
	}

	printf("%d",ans);
	FOR(sq,0,G)
		if((opt>>sq)&1)
			printf(" %d",sq+1);
	printf("\n");

	fclose(stdin);
	fclose(stdout);

	return 0;
}
