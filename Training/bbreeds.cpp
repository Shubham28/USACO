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
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

char inp[1003];
int L=0;
const int MOD=2012;

int cum[1003];
int cnt[1003][1003];

int cntWays(int pos,int hols)
{
	int guer=cum[pos-1]-hols;

	if(pos==L+1)
		return (hols==0 && guer==0)?1:-9999;

	int &tmp=cnt[pos][hols];
	if(tmp!=-1)
		return tmp;

	if(inp[pos]=='('){
		int hOpen=cntWays(pos+1,hols+1);
		int gOpen=cntWays(pos+1,hols);
		tmp=max(hOpen,0)+max(gOpen,0);
	} else {
		int hClose=0,gClose=0;
		if(hols>0)			hClose=cntWays(pos+1,hols-1);
		if(guer>0)			gClose=cntWays(pos+1,hols);

		tmp=max(hClose,0)+max(gClose,0);
	}
	return (tmp>0)?tmp%MOD:-9999;
}

int main()
{
	freopen("bbreeds.in","r",stdin);
	freopen("bbreeds.out","w",stdout);

	inp[0]=' ',cum[0]=0;
	scanf("%s",&inp[1]);

	for(int i=1;inp[i]!=0;i++,L++)
		cum[i]=cum[i-1]+((inp[i]=='(')?1:-1);

	MEM(cnt,-1);
	int fin=cntWays(1,0);
	cout<<((fin>0)?fin:0)<<"\n";

	fclose(stdin);
	fclose(stdout);

	return 0;
}
