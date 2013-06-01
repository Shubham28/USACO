/*
ID: celesti3
PROG: ratios
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

/*	[X Y Z][a1 a2 a3	= P[k l m]
			b1 b2 b3
			c1 c2 c3]

	Take inverse of 3x3 matrix without determinent.		*/

int gl[3],F[3][3];
int I[3][3],prd[3];

inline void invMat()
{
	I[0][0]=F[1][1]*F[2][2]-F[2][1]*F[1][2];
	I[0][1]=-(F[1][0]*F[2][2]-F[2][0]*F[1][2]);
	I[0][2]=F[1][0]*F[2][1]-F[2][0]*F[1][1];

	I[1][0]=-(F[0][1]*F[2][2]-F[2][1]*F[0][2]);
	I[1][1]=F[0][0]*F[2][2]-F[2][0]*F[0][2];
	I[1][2]=-(F[0][0]*F[2][1]-F[2][0]*F[0][1]);

	I[2][0]=F[0][1]*F[1][2]-F[1][1]*F[0][2];
	I[2][1]=-(F[0][0]*F[1][2]-F[1][0]*F[0][2]);
	I[2][2]=F[0][0]*F[1][1]-F[1][0]*F[0][1];

	swap(I[0][1],I[1][0]);
	swap(I[0][2],I[2][0]);
	swap(I[1][2],I[2][1]);
}

int main()
{
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);

	FOR(a,0,3)
		scanf("%d",&gl[a]);

	FOR(rw,0,3)		FOR(cl,0,3)
		scanf("%d",&F[rw][cl]);

	invMat();
	FOR(cl,0,3){
		FOR(rw,0,3)
			prd[cl]+=gl[rw]*I[rw][cl];
	}

	bool fnd=1;
	int sign=0;
	FOR(a,0,3){
		if(prd[a]>0){
			if(sign<0){
				fnd=0;
				break;
			}
			sign=1;
		} else if(prd[a]<0){
			if(sign>0){
				fnd=0;
				break;
			}
			sign=-1;
		}
	}

	if(!fnd)
		printf("NONE\n");
	else {
		if(prd[0]<0)
			prd[0]*=-1,prd[1]*=-1,prd[2]*=-1;

		int tot=(prd[0]*F[0][0]+prd[1]*F[1][0]+prd[2]*F[2][0])/gl[0];
		int qt=__gcd(prd[0],__gcd(prd[1],__gcd(prd[2],tot)));
		prd[0]/=qt,prd[1]/=qt,prd[2]/=qt;
		tot/=qt;

		printf("%d %d %d %d\n",prd[0],prd[1],prd[2],tot);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
