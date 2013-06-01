/*
ID: celesti3
PROG: subset
LANG: C++
*/


#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <set>
#include <numeric>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);

	int N;
	scanf("%d",&N);

	if(N*(N+1)%4)
		printf("0\n");
	else {
		LL ways[420];
		MEM(ways,0);
		ways[0]=1;

		int M=N*(N+1)/4;
		EFOR(nm,1,N)
			RFOR(sm,M,nm){
				int trg=sm-nm;
				if(trg>=0)
					ways[sm]+=ways[trg];
			}

		printf("%lld\n",ways[M]/2);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
