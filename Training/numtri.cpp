/*
ID: celesti3
PROG: numtri
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

using namespace std;

int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);

	int N;
	int inp[1001][1001];

	scanf("%d",&N);
	FOR(rw,0,N)		EFOR(cl,0,rw)
		scanf("%d",&inp[rw][cl]);

	int opt[2][1001];
	opt[0][0]=inp[0][0];

	int ans=0;
	FOR(rw,1,N){
		opt[rw&1][0]=inp[rw][0]+opt[!(rw&1)][0];
		EFOR(cl,1,rw-1)
			opt[rw&1][cl]=inp[rw][cl]+max(opt[!(rw&1)][cl-1],opt[!(rw&1)][cl]);
		opt[rw&1][rw]=inp[rw][rw]+opt[!(rw&1)][rw-1];
	}

	FOR(chk,0,N)
		ans=max(ans,opt[(N-1)&1][chk]);
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
