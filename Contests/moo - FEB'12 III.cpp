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
#define LL long long

using namespace std;

int main()
{
	freopen("moo.in","r",stdin);
	freopen("moo.out","w",stdout);

	LL len[30];
	len[0]=3;

	FOR(now,1,30){
		len[now]=2*len[now-1];
		len[now]+=(1+now+2);
	}

	LL N;
	cin>>N;

	while(N>3){
		int seq=0;
		for(;len[seq]<N;seq++);

		if(N>len[seq-1]){
			N-=len[seq-1];

			if(N<=1+seq+2)
				break;

			N-=(1+seq+2);
		}
	}
	cout<<((N==1)?'m':'o')<<"\n";

	fclose(stdin);
	fclose(stdout);

	return 0;
}
