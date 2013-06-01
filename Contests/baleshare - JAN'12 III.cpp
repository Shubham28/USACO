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
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	int N,S[21];
	scanf("%d",&N);

	short L=0;
	FOR(a,0,N){
		scanf("%d",&S[a]);
		L+=S[a];
	}

	short opt[2][2000][2000];

	EFOR(fr,0,L)	EFOR(sc,0,L-fr){
		int thr=L-fr-sc;
		opt[N&1][fr][sc]=max(fr,max(sc,thr));
	}

	RFOR(use,N-1,0)
		EFOR(fr,0,L)		EFOR(sc,0,L-fr){
			short tmp=opt[(use+1)&1][fr][sc];
			tmp=min(tmp,opt[(use+1)&1][fr+S[use]][sc]);
			tmp=min(tmp,opt[(use+1)&1][fr][sc+S[use]]);
			opt[use&1][fr][sc]=tmp;
		}

	int ans=opt[0][0][0];
	printf("%d\n",ans);

	return 0;
}
