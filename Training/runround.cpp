/*
ID: celesti3
PROG: runround
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

using namespace std;

char conv[10];
bool dn[10];

bool chkRn(int num)
{
	sprintf(conv,"%d",num);
	int ln=strlen(conv);

	if(ln==1)	return 1;
	if(find(conv,conv+ln,'0')!=conv+ln)		return 0;

	MEM(dn,0);
	FOR(fl,0,ln)	dn[conv[fl]-'0']=1;
	if(count(dn,dn+10,1)!=ln)	return 0;

	MEM(dn,0);
	int prs=0,nxt;
	FOR(mv,0,ln){
		nxt=(prs+conv[prs]-'0')%ln;

		if(dn[nxt])		return 0;
		dn[nxt]=1;
		prs=nxt;
	}
	return 1;
}

int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);

	int M;
	scanf("%d",&M);
	while(1){
		M++;
		if(chkRn(M)){
			printf("%d\n",M);
			break;
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
