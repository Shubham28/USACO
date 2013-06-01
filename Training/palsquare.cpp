/*
ID: celesti3
PROG: palsquare
LANG: C++
*/


#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

int B,L;
char conv[20],revr[20];

void basCnv(int num)
{
	L=0;
	while(num!=0){
		int mod=num%B;
		if(mod<=9)
			conv[L++]='0'+mod;
		else
			conv[L++]='A'+(mod-10);
		num/=B;
	}
	conv[L]=0;
	return;
}

int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);

	scanf("%d",&B);
	EFOR(all,1,300){
		int sqr=all*all;
		basCnv(sqr);

		FOR(cpy,0,L)		revr[cpy]=conv[cpy];
		FOR(rv,0,(L>>1))		swap(revr[rv],revr[L-1-rv]);

		bool eq=1;
		FOR(chk,0,L)
			if(conv[chk]!=revr[chk]){
				eq=0;
				break;
			}

		if(eq){
			basCnv(all);
			FOR(rv,0,(L>>1))		swap(conv[rv],conv[L-1-rv]);

			printf("%s %s\n",conv,revr);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
