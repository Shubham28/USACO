/*
ID: celesti3
PROG: money
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
#define LL long long

using namespace std;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);

	int V,N;
	scanf("%d %d",&V,&N);

	int cns[N+1];
	FOR(in,0,V)
		scanf("%d",&cns[in]);

	LL ways[N+1];
	MEM(ways,0);
	ways[0]=1;

	FOR(pt,0,V)
		EFOR(fl,cns[pt],N){
			if(fl-cns[pt]>=0)
				ways[fl]+=ways[fl-cns[pt]];
		}

	printf("%lld\n",ways[N]);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
