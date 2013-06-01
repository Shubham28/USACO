/*
ID: celesti3
PROG: prefix
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
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define VS vector<string>
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);

	char prm[205][12];
	int ln[205];
	int N=0;

	scanf("%s",prm[N]);
	ln[N]=strlen(prm[N++]);
	while(!(strlen(prm[N-1])==1 && prm[N-1][0]=='.')){
		scanf("%s",prm[N]);
		ln[N]=strlen(prm[N++]);
	}
	N--;

	char tmp[12];
	FOR(i,0,N-1)   FOR(j,i+1,N)
		if(ln[i]>ln[j]){
			strcpy(tmp,prm[i]);
			strcpy(prm[i],prm[j]);
			strcpy(prm[j],tmp);
			swap(ln[i],ln[j]);
		}

	char S[200005];
	S[0]=0;
	string inp;
	while(cin>>inp)
		strcat(S,inp.c_str());

	int L=strlen(S);

	bool dn[200005];
	MEM(dn,0);		dn[0]=1;

	int ans=0,lim=0;
	EFOR(p,0,lim){
		if(!dn[p])	continue;

		bool prv;
		FOR(mt,0,N){
			if(mt>0 && ln[mt]==ln[mt-1]){
				if(prv)     continue;
			} else
				prv=0;

			if(p+ln[mt]<=L){
				bool same=1;
				FOR(c,0,ln[mt])
					if(S[p+c]!=prm[mt][c]){
						same=0;
						break;
					}

				if(same)
					dn[p+ln[mt]]=1,lim=p+ln[mt],prv=1;
			}
		}
		if(dn[p])	ans=p;
	}
	if(dn[L])	ans=L;
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
