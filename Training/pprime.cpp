/*
ID: celesti3
PROG: pprime
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

#define N 100050
unsigned int prime[N/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
	memset(prime,-1,sizeof(prime));

	unsigned int i;
	unsigned int sqrtN=(unsigned int)sqrt((double)N)+1;
	for(i=3;i<sqrtN;i+=2) if(gP(i))
	{
		unsigned int i2=i+i;
		for(unsigned int j=i*i;j<N;j+=i2) rP(j);
	}
	return;
}

bool PrimeChk(int T)
{
	if(T<=1)	return 0;
	if(T<=3)	return 1;
	if(T%2==0 || T%3==0)	return 0;
	if(T<=8)	return 1;

	int fac=5;
	while(fac*fac<=T){
		if(T%fac==0)	return 0;
		if(T%(fac+2)==0)	return 0;
		fac+=6;
	}
	return 1;
}

int A,B;

inline void SHOW(int chk)
{
	if(A<=chk && chk<=B){
		if(chk<=(N-50)){
			if(gP(chk))		printf("%d\n",chk);
		} else if(PrimeChk(chk))
			printf("%d\n",chk);
	}
	return;
}

int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	sieve();

	scanf("%d %d",&A,&B);

	int num;
	if(A<=5 && 5<=B)	printf("5\n");
	if(A<=7 && 7<=B)	printf("7\n");

//	"AA" = 10*A + A
	for(int fr=1;fr<=9;fr+=2){
		num=11*fr;
		SHOW(num);
	}

//	"ABA" = 100*A + 10*B + A
//	"ABBA" = 1000*A + 100B + 10B + A
	for(int fr=1;fr<=9;fr+=2)	EFOR(sc,0,9){
		num=101*fr+10*sc;
		SHOW(num);

		num=fr*1001+sc*110;
		SHOW(num);
	}

//	"ABCBA" = 10000*A + 1000B + 100C + 10B + A
//	"ABCCBA" = 100000*A + 10000B + 1000C + 100C + 10B + A
	for(int fr=1;fr<=9;fr+=2)	EFOR(sc,0,9)	EFOR(thr,0,9){
		num=10001*fr+1010*sc+100*thr;
		SHOW(num);

		num=100001*fr+10010*sc+1100*thr;
		SHOW(num);
	}

//	"ABCDCBA" = 1000000*A + 100000B + 10000C + 1000D + 100C + 10B + A
//	"ABCDDCBA" = 10000000*A + 1000000B + 100000C + 10000D + 1000D + 100C + 10B + A
	for(int fr=1;fr<=9;fr+=2)	EFOR(sc,0,9)	EFOR(thr,0,9)	EFOR(frt,0,9){
		num=1000001*fr+100010*sc+10100*thr+1000*frt;
		SHOW(num);

		num=10000001*fr+1000010*sc+100100*thr+11000*frt;
		SHOW(num);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
