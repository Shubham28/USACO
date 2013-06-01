/*
ID: celesti3
PROG: sprime
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

#define N 10050
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

int K;

inline bool TEST(int chk)
{
	if(chk==2)	return 1;
	else if(!(chk&1))	return 0;

	if(chk<=(N-50)){
		if(gP(chk))		return 1;
	} else if(PrimeChk(chk))	return 1;

	return 0;
}

void DFS(int num,int pos)
{
	int chk;
	if(pos==K)
		for(int last=1;last<=9;last+=2){
			chk=num*10+last;
			if(TEST(chk))	printf("%d\n",chk);
		}
	else 
		EFOR(fl,0,9){
			chk=num*10+fl;
			if(TEST(chk))
				DFS(chk,pos+1);
		}

	return;
}

int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	sieve();

	scanf("%d",&K);
	if(K==1)
		printf("2\n3\n5\n7\n");
	else {
		DFS(2,2);
		for(int st=3;st<=7;st+=2)
			DFS(st,2);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
