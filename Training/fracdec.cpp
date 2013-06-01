/*
ID: celesti3
PROG: fracdec
LANG: C++
*/


#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <queue>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

//	Analytical solution doesn't need extra space

inline void newLn(int &L)
{
	if(L==76){
		printf("\n");
		L=0;
	}
	return;
}

int main()
{
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);

	int num,den;
	scanf("%d%d",&num,&den);
	int L=0;
	L=printf("%d.",num/den);

	if(num%den==0)
		printf("0\n");
	else {
		int rem[100001],qt[100001];
		MEM(rem,-1);
		int T=0;

		while(1){
			if(num==0){
				FOR(pr,0,T-1){
					L+=printf("%d",qt[pr]);
					newLn(L);
				}
				printf("\n");
				break;
			}

			num%=den;
			if(rem[num]!=-1){
				int fr=rem[num];

				FOR(pr,0,fr){
					L+=printf("%d",qt[pr]);
					newLn(L);
				}

				L+=printf("(");
				newLn(L);

				FOR(pr,fr,T){
					L+=printf("%d",qt[pr]);
					newLn(L);
				}
				printf(")\n");
				break;
			} else {
				rem[num]=T;
				num*=10;
				qt[T++]=num/den;
			}
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
