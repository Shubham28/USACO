/*
ID: celesti3
PROG: ariprog
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
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);

	int N,M;
	scanf("%d\n%d",&N,&M);

/*	In-efficient Implementation

	int L=0;
	int num[31630];
	unsigned short ind[2*M*M+5];
	bool bisq[2*M*M+5];

	MEM(bisq,0);

	EFOR(p,0,M)		EFOR(q,p,M)
		bisq[p*p+q*q]=1;

	EFOR(fl,0,2*M*M)
		if(bisq[fl])	num[L++]=fl;

	sort(num,num+L);
	FOR(as,0,L)
		ind[num[as]]=as;

	int lim=num[L-1];
	char cycl[31630];

	bool no=1;
	for(int dif=1;dif*(N-1)<=lim;dif++){
		MEM(cycl,0);

		FOR(a,0,L){
			if(num[a]-dif<0 || !bisq[num[a]-dif])
				cycl[a]=1;
			else
				cycl[a]=cycl[ind[num[a]-dif]]+1;
		}

		FOR(ans,0,L)
			if(cycl[ans]>=N){
				printf("%d %d\n",num[ans]-(N-1)*dif,dif);
				no=0;
			}
	}

	if(no)
		printf("NONE\n");
*/

	int L=0;
	int num[31630];
	bool bisq[2*M*M+5];
	MEM(bisq,0);

	EFOR(p,0,M)		EFOR(q,p,M)
		bisq[p*p+q*q]=1;

	EFOR(fl,0,2*M*M)
		if(bisq[fl])	num[L++]=fl;

	sort(num,num+L);
	int lim=num[L-1];

	bool no=1;
	for(int dif=1;dif*(N-1)<=lim;dif++){

		for(int st=0;num[st]+(N-1)*dif<=lim;st++){
			bool all=1;
			FOR(chk,1,N)
				if(!bisq[num[st]+(chk)*dif]){
					all=0;
					break;
				}

			if(all){
				printf("%d %d\n",num[st],dif);
				no=0;
			}
		}
	}
	if(no)
		printf("NONE\n");

	fclose(stdin);
	fclose(stdout);

	return 0;
}
