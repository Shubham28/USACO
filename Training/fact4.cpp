/*
ID: celesti3
PROG: fact4
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

int N,P=0;
int prms[600];

void SieveFull()
{
	prms[P++]=2;

	int U=(N&1)?N:N-1;
	int range=(U-1)/2;
	int limit=int(sqrt(U+0.)+1e-9)/2;

	bool chk[4230];
	MEM(chk,0);

	EFOR(i,1,limit){
		if(chk[i-1]==0)
			for(int j=2*i*(i+1);j<=range;j+=(2*i+1))
				chk[j-1]=1;
	}

	FOR(i,0,range)
		if(chk[i]==0)
			prms[P++]=2*i+3;

	return;
}

int prmPwr(int base)
{
	int exp=0,pwr=1;

	while(true){
		pwr=pwr*base;
		if(pwr>N)
			break;

		exp+=N/pwr;
	}
	return exp;
}

int main()
{
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);

	scanf("%d",&N);

	if(N<=2 || N==4)
		printf("%d\n",N);
	else if(N==3)
		printf("6\n");
	else {
		SieveFull();
		int zero=prmPwr(5);

		int ans=1;
		FOR(a,0,P){
			if(a==2)		continue;

			int tot=prmPwr(prms[a]);
			if(a==0)
				tot-=zero;

			EFOR(ml,1,tot){
				ans*=prms[a];

				if(ans>1000000)
					ans%=10;
			}
		}
		printf("%d\n",ans%10);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
