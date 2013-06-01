/*
ID: celesti3
PROG: game1
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
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

int N;
int val[205],S[205];
int opt[2][205][205];

int calOpt(int plr,int fr,int to)
{
	if(fr==to)
		return val[fr];

	int &tmp=opt[plr][fr][to];
	if(tmp!=-1)
		return tmp;

	int lft=calOpt(!plr,fr+1,to);
	int rt=calOpt(!plr,fr,to-1);

	return (tmp=S[to]-S[fr-1]-min(lft,rt));
}

int main()
{
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);

	S[0]=0;

	cin>>N;
	EFOR(a,1,N){
		cin>>val[a];
		S[a]=S[a-1]+val[a];
	}

	MEM(opt,-1);
	int fir=calOpt(0,1,N);
	cout<<fir<<" "<<S[N]-fir<<"\n";

	fclose(stdin);
	fclose(stdout);

	return 0;
}
