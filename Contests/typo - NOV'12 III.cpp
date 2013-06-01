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
#include <sstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

using namespace std;

char inp[100005];
int L;

int cntPos()
{
	int opn=0,cls=0,i=0;
	int ans=0;
	for(;i<L;i++){
		opn+=(inp[i]=='(');
		cls+=(inp[i]==')');

		if(opn<cls){
			ans=cls;
			opn=1,cls=0,i++;
			break;
		}
	}

	bool posb=1;
	for(;i<L;i++){
		opn+=(inp[i]=='(');
		cls+=(inp[i]==')');

		if(opn<cls){
			posb=0;
			break;
		}
	}

	return (posb)?ans:0;
}

int main()
{
	freopen("typo.in","r",stdin);
	freopen("typo.out","w",stdout);

	scanf("%s",inp);
	L=strlen(inp);

	int diff=count(inp,inp+L,'(')-count(inp,inp+L,')');

	int ans=0;
	if(abs(diff)==2){
		if(diff==2){
			reverse(inp,inp+L);
			FOR(i,0,L)
				inp[i]=(inp[i]=='(')?')':'(';
		}
		ans=cntPos();
	}
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
