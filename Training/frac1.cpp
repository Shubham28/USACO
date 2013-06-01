/*
ID: celesti3
PROG: frac1
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
#include <set>
#include <numeric>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);

	pair<short,short>frac[25000];
	int N;
	scanf("%d",&N);

	if(N==1){
		printf("0/1\n");
		printf("1/1\n");
	} else {

		int len=0;
		frac[len++]=make_pair(0,1);

		int A,B,C,D,K;
		A=0,B=1,C=1,D=N;
		while(C<N){
			K=int((N+B)/D);
			int tmpa=A,tmpb=B;
			A=C,B=D;
			C=K*C-tmpa,D=K*D-tmpb;

			frac[len++]=make_pair(short(A),short(B));
		}

		FOR(pr,0,len)
			printf("%hd/%hd\n",frac[pr].first,frac[pr].second);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
