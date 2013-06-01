/*
ID: celesti3
PROG: calfflac
LANG: C++
*/


#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
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
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);

	char inp[20005],seq[20005];
	short ind[20005];
	int tot=0,L=0;
	bool paln[3][20001];

	char ch=getchar();
	while(ch!=EOF){
		inp[tot++]=ch;

		if('A'<=inp[tot-1] && inp[tot-1]<='Z')
			seq[L]=inp[tot-1]+32,ind[L++]=tot-1;
		else if('a'<=inp[tot-1] && inp[tot-1]<='z')
			seq[L]=inp[tot-1],ind[L++]=tot-1;
		ch=getchar();
	}

	FOR(ps,0,L)		paln[0][ps]=1;
	FOR(ps,0,L-1)
		paln[1][ps]=(seq[ps]==seq[ps+1])?1:0;

	int chn=2,bln=1,bps=0;

	EFOR(ln,3,min(L,2001)){
		MEM(paln[chn],0);

		EFOR(ps,0,L-ln){
			int lst=ps+ln-1;
			if(seq[ps]==seq[lst] && paln[(chn+3-2)%3][ps+1])
				paln[chn][ps]=1;

			if(paln[chn][ps] && bln<ln)
				bln=ln,bps=ps;
		}
		chn=(chn+1)%3;
	}

	printf("%d\n",bln);
	EFOR(pr,ind[bps],ind[bps+bln-1])
		printf("%c",inp[pr]);
	printf("\n");

	fclose(stdin);
	fclose(stdout);

	return 0;
}
