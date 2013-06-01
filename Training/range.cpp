/*
ID: celesti3
PROG: range
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

using namespace std;

int main()
{
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);

	int N;
	bool sq[2][251][251];

	scanf("%d",&N);
	char inp[251];
	FOR(r,0,N){
		scanf("%s",inp);

		FOR(c,0,N)
			sq[1][r][c]=(inp[c]=='1');
	}

	EFOR(ln,2,N){
		int cnt=0,prv=(ln-1)&1;

		EFOR(r,0,N-ln)		EFOR(c,0,N-ln){
			sq[ln&1][r][c]=(sq[prv][r][c] && sq[prv][r][c+1] && sq[prv][r+1][c] && sq[prv][r+1][c+1]);
			cnt+=sq[ln&1][r][c];
		}

		if(cnt>0)
			printf("%d %d\n",ln,cnt);
		else
			break;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
