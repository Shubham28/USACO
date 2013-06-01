/*
ID: celesti3
PROG: barn1
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
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);

	int M,S,C;
	scanf("%d %d %d",&M,&S,&C);
	M=min(M,C);

	int cws[C];
	int strt=S+1,end=0;
	FOR(inp,0,C){
		scanf("%d",&cws[inp]);
		strt=min(strt,cws[inp]);
		end=max(end,cws[inp]);
	}

	sort(cws,cws+C);
	int difs[C-1];

	FOR(add,0,C-1)
		difs[add]=cws[add+1]-cws[add]-1;

	sort(difs,difs+C-1);
	reverse(difs,difs+C-1);

	int ans=end-strt+1;
	FOR(ch,0,M-1)
		ans-=difs[ch];

	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
