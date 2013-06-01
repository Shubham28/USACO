/*
ID: celesti3
PROG: msquare
LANG: C++
*/


#include <map>
#include <queue>
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

using namespace std;

inline int conv(int seq[])
{
	int ret=0;
	FOR(a,0,8)
		ret=ret*10+seq[a];

	return ret;
}

int main()
{
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);

	int fin=0,tmp;
	FOR(a,0,4){
		scanf("%d",&tmp);
		fin=fin*10+tmp;
	}
	int sec=0;
	FOR(a,0,4){
		scanf("%d",&tmp);
		sec=sec*10+tmp;
	}

	do{
		fin=fin*10+sec%10;
	} while(sec/=10);

	queue<int>brd;
	brd.push(12348765);

	map<int,char>trns;
	map<int,int>P;
	trns[12348765]='O';

	int dig[8],cp[8];
	int tmp1,tmp2;

	while(!brd.empty()){
		int prs=brd.front();
		brd.pop();

		if(prs==fin)
			break;

		int dup=prs;
		RFOR(rv,7,0){
			dig[rv]=prs%10;
			prs/=10;
		}

		FOR(c,0,8)
			cp[(c+4)%8]=dig[c];

		int nxt1=conv(cp);
		if(trns.find(nxt1)==trns.end()){
			trns[nxt1]='A',P[nxt1]=dup;
			brd.push(nxt1);
		}

		tmp1=dig[3],tmp2=dig[7];
		FOR(c,0,3)		cp[(c+1)]=dig[c];
		cp[0]=tmp1;
		FOR(c,4,7)		cp[(c+1)]=dig[c];
		cp[4]=tmp2;

		int nxt2=conv(cp);
		if(trns.find(nxt2)==trns.end()){
			trns[nxt2]='B',P[nxt2]=dup;
			brd.push(nxt2);
		}

		memcpy(cp,dig,sizeof(dig));
		tmp1=cp[5];
		cp[5]=cp[6],cp[6]=cp[2],cp[2]=cp[1],cp[1]=tmp1;

		int nxt3=conv(cp);
		if(trns.find(nxt3)==trns.end()){
			trns[nxt3]='C',P[nxt3]=dup;
			brd.push(nxt3);
		}
	}

	char ans[40400];
	int L=0;
	while(trns[fin]!='O'){
		ans[L++]=trns[fin];
		fin=P[fin];
	}
	ans[L]=0;
	reverse(ans,ans+L);
	printf("%d\n%s\n",L,ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
