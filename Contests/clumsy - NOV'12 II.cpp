#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <stack>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

using namespace std;

char inp[100005];
int L;

int main()
{
	freopen("clumsy.in","r",stdin);
	freopen("clumsy.out","w",stdout);

	scanf("%s",inp);
	L=strlen(inp);

	int cum=0,chng=0;
	FOR(i,0,L){
		if(inp[i]=='(')
			++cum;
		else {
			if(cum>0)	--cum;
			else		++chng,++cum;
		}
	}
	chng+=(cum>>1);
	printf("%d\n",chng);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
