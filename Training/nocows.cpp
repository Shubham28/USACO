/*
ID: celesti3
PROG: nocows
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
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline int LowLv(int nds)
{  	return (32-__builtin_clz(nds));     }

inline int UpLv(int nds)
{     return (nds+1)>>1;			}

int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);

	int MOD=9901;
	int cnt[200][200],S[200][200];
	MEM(cnt,0);		MEM(S,0);

	cnt[1][1]=1;
	FOR(fl,1,100)	S[1][fl]=1;

	for(int nd=3;nd<200;nd+=2)
		for(int lf=1;lf<nd;lf+=2){
			int rt=nd-lf-1;

			EFOR(htl,LowLv(lf),UpLv(lf))
				EFOR(htr,LowLv(rt),UpLv(rt)){
					cnt[nd][max(htl,htr)+1]+=cnt[lf][htl]*cnt[rt][htr];
					cnt[nd][max(htl,htr)+1]%=MOD;
			}
		}

	int N,K;
	scanf("%d%d",&N,&K);
	printf("%d\n",cnt[N][K]);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
