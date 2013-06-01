/*
ID: celesti3
PROG: inflate
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
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);

	int N,tot;
	scanf("%d %d",&tot,&N);

	int tm[10005],scr[10005];
	FOR(a,0,N)
		scanf("%d %d",&scr[a],&tm[a]);

	int S[100005];
	MEM(S,0);

	FOR(r,0,N)
		EFOR(cur,tm[r],tot)
			if(S[cur]<S[cur-tm[r]]+scr[r])
				S[cur]=S[cur-tm[r]]+scr[r];

	printf("%d\n",S[tot]);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
