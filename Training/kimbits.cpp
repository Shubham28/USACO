/*
ID: celesti3
PROG: kimbits
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
#define UI unsigned int

using namespace std;

int N,L;
bool bit[33];
UI ways[33][32][2];

int cntNum(int pos,int rem,bool less)
{
	if(pos==N+1)
		return 1;

	UI &tmp=ways[pos][rem][less];
	if(tmp!=-1)
		return tmp;

	tmp=0;
	if(less){
		if(rem)
			tmp+=cntNum(pos+1,rem-1,less);
		tmp+=cntNum(pos+1,rem,less);
	} else {
		if(bit[pos]){
			if(rem)
				tmp+=cntNum(pos+1,rem-1,less);
			tmp+=cntNum(pos+1,rem,!less);
		} else
			tmp+=cntNum(pos+1,rem,less);
	}

	return tmp;
}

int main()
{
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);

	UI I;
	scanf("%d %d %u",&N,&L,&I);

	UI low=0,high=(1ll<<N)-1;
	UI ans;

	while(low<=high){
		UI mid=low+(high-low)/2;

		MEM(ways,-1);
		FOR(ps,0,N)
			bit[N-ps]=(mid>>ps)&1;

		UI cnt=cntNum(1,L,0);

		if(cnt==I){
			ans=mid;
			break;
		} else if(cnt<I)
			low=mid+1;
		else
			high=mid-1;
	}

	for(UI chk=ans-1;;ans=chk,chk--){
		MEM(ways,-1);
		FOR(ps,0,N)
			bit[N-ps]=(chk>>ps)&1;

		UI cnt=cntNum(1,L,0);
		if(cnt!=I)
			break;
	}

	FOR(ps,0,N)
		bit[N-ps]=(ans>>ps)&1;

	EFOR(pr,1,N)
		printf("%d",int(bit[pr]));
	printf("\n");


	fclose(stdin);
	fclose(stdout);

	return 0;
}
