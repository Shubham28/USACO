/*
ID: celesti3
PROG: contact
LANG: C++
*/


#include <map>
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
#define SORT(A) sort( A.begin(),A.end() )
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);

	string inp="",tmp;
	int lo,hi,N;
	scanf("%d %d %d",&lo,&hi,&N);

	int ln=0;
	while(cin>>tmp)
		inp+=tmp;
	ln=SZ(inp);

	int freq[8200];
	MEM(freq,0);

	EFOR(ps,0,ln-lo){
		int val=1;
		EFOR(cp,0,lo-1)
			val=(val<<1)+(inp[ps+cp]-'0');
		++freq[val];

		for(int cp=lo;ps+cp<ln && cp<=hi-1;cp++){
			val=(val<<1)+(inp[ps+cp]-'0');
			++freq[val];
		}
	}

	map<int, VI >invr;
	map<int, VI >::reverse_iterator it;

	EFOR(a,2,8192)
		if(freq[a])
			PB(invr[freq[a]],a);

	for(it=invr.rbegin();it!=invr.rend() && N>0;N--,it++){
		int L=SZ((*it).second);
		printf("%d\n",(*it).first);

		for(int all=0;all<L;all++){
			if(all>0 && all%6==0)
				printf("\n");

			if(all%6!=0)
				printf(" ");

			int copy=((*it).second)[all],tot=0;
			char rev[15];

			while(copy!=0){
				rev[tot++]=(copy%2)+'0';
				copy/=2;
			}
			rev[--tot]=0;
			reverse(rev,rev+tot);
			printf("%s",rev);
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
