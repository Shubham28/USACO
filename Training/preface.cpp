/*
ID: celesti3
PROG: preface
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

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

char numr[]={'I','V','X','L','C','D','M'};
int val[]={1,5,10,50,100,500,1000};
int tot[7];

void cntNumr(int nm)
{
	int last=nm%10;
	if(last==4)		tot[0]++,tot[1]++;
	else if(last==9)	tot[0]++,tot[2]++;
	else
		tot[1]+=last/5,tot[0]+=last-(last/5)*5;

	nm/=10;
	last=nm%10;
	if(last==4)		tot[2]++,tot[3]++;
	else if(last==9)	tot[2]++,tot[4]++;
	else
		tot[3]+=last/5,tot[2]+=last-(last/5)*5;

	nm/=10;
	last=nm%10;
	if(last==4)		tot[4]++,tot[5]++;
	else if(last==9)	tot[4]++,tot[6]++;
	else
		tot[5]+=last/5,tot[4]+=last-(last/5)*5;

	tot[6]+=nm/10;
	
	return;
}

int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);

	MEM(tot,0);
	int N;
	scanf("%d",&N);
	EFOR(i,1,N)
		cntNumr(i);

	FOR(p,0,7)
		if(tot[p]!=0)
			printf("%c %d\n",numr[p],tot[p]);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
