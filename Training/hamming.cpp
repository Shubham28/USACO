/*
ID: celesti3
PROG: hamming
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
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);

	int N,B,D;
	scanf("%d %d %d",&N,&B,&D);

	printf("0");
	if(N==1)
		printf("\n");
	else {
		printf(" ");
		int cnt=0;
		int ar[N+1];

		ar[cnt++]=0;
		FOR(nm,1,1<<8){

			bool ad=1;
			FOR(prv,0,cnt){
				int df=0;
				FOR(bt,0,8)
					df+=(((ar[prv]>>bt)&1)!=((nm>>bt)&1));

				if(df<D){
					ad=0;
					break;
				}
			}
			if(ad){
				ar[cnt++]=nm;
				printf("%d",nm);
				printf((cnt==N || cnt%10==0)?"\n":" ");

				if(cnt==N)	break;
			}
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
