#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);

	int tls[11];
	FOR(a,0,N)
		scanf("%d",&tls[a]);

	int cst[10005][11];
	EFOR(ar,0,10000)
		EFOR(nm,0,10)
			cst[ar][nm]=1000005;

	cst[0][0]=0;

	FOR(t,0,N)
		RFOR(ar,M,0){
			if(t==0)		ar=0;

			FOR(num,0,N){
				if(cst[ar][num]>1000000)
					continue;

				for(int use=1;ar+use*use<=M;use++)
					cst[ar+use*use][num+1]=min(cst[ar+use*use][num+1],cst[ar][num]+(tls[t]-use)*(tls[t]-use));
			}
		}

	printf("%d\n",(cst[M][N]>1000000)?-1:cst[M][N]);

	return 0;
}
