#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <numeric>
#include <sstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

using namespace std;

int fct[]={1,1,2,6,24,120,720,5040,40320,362880,3628800};

int nCr(int N,int R)
{
	LL ans=1;
	EFOR(p,N+1-R,N)
		ans*=p;

	ans/=fct[R];
	return int(ans);
}

int main()
{
	int N,K;
	cin>>N>>K;

	int d0=0,d1=K;
	while(N>0){
		if(N==1){
			FOR(z,0,d0)			printf("0");
			FOR(o,0,d1)			printf("1");
			break;
		}

		int lim=nCr(d0+d1,d1);
		if(lim<N){
			d0++;
			continue;
		}

		int mid=nCr(d0+d1-1,d1);
		if(mid>=N){
			printf("0");
			d0--;
		} else {
			printf("1");
			N-=mid,d1--;
		}
	}
	printf("\n");

	return 0;
}
