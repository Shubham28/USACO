/*
ID: celesti3
PROG: dualpal
LANG: C++
*/


#include <algorithm>
#include <sstream>
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

int L,B;
char conv[32],revr[32];

void basCnv(int num)
{
	L=0;
	while(num!=0){
		int mod=num%B;
		conv[L++]='0'+mod;
		num/=B;
	}
	conv[L]=0;
	return;
}

int main()
{
//	freopen("Input.txt","r",stdin);
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);

	int N,S;
	scanf("%d%d",&N,&S);

	int cnt=0;
	for(int chk=S+1;cnt<N;chk++){
		int tmp=0;
		EFOR(bs,2,10){
			B=bs;
			basCnv(chk);

			strcpy(revr,conv);
			reverse(revr,revr+L);
			if(strcmp(conv,revr)==0)
				++tmp;

			if(tmp>=2){
				cnt++;
				break;
			}
		}
		if(tmp==2)
			printf("%d\n",chk);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
