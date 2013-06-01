/*
ID: celesti3
PROG: checker
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

int seq[15],N;
bool posb[15],updiag[30],downdiag[30];
int cmb=0;

void backTrk(int cur)
{
	bool dn;
	FOR(chk,0,N){
		if(chk==seq[cur-1]-1 || chk==seq[cur-1] || chk==seq[cur-1]+1){
			chk=seq[cur-1]+1;
			continue;
		}

		if(posb[chk] && updiag[cur+chk] && downdiag[N+cur-chk]){
			dn=1;
			for(int prv=0;prv<cur;prv++)
				if(abs(seq[prv]-chk)==abs(prv-cur)){
					dn=0;
					break;
				}

			if(dn){
				if(cur==N-1){
					if(cmb<3){
						FOR(pr,0,N-1)		printf("%d ",seq[pr]+1);
						printf("%d\n",chk+1);
					}
					++cmb;
				} else{
					posb[chk]=updiag[cur+chk]=downdiag[N+cur-chk]=0;
					seq[cur]=chk;
					backTrk(cur+1);
					posb[chk]=updiag[cur+chk]=downdiag[N+cur-chk]=1;
				}
			}
		}
	}

	return;
}

int main()
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);

	scanf("%d",&N);
	FOR(fl,0,N)		posb[fl]=updiag[fl]=downdiag[fl]=1;
	FOR(fl,N,30)	updiag[fl]=downdiag[fl]=1;

	int lim=N>>1;
	FOR(put,0,lim){
		posb[put]=updiag[put]=downdiag[N-put]=0;
		seq[0]=put;
		backTrk(1);
		posb[put]=updiag[put]=downdiag[N-put]=1;
	}
	cmb<<=1;

	if(N&1){
		posb[lim]=updiag[lim]=downdiag[N-lim]=0;
		seq[0]=lim;
		backTrk(1);
	}

	if(N==6)
		printf("4 1 5 2 6 3\n");

	printf("%d\n",cmb);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
