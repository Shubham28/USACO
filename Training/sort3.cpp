
/*
ID: celesti3
PROG: sort3
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

using namespace std;

int N;
int ar[1001],cnt[4];

inline int range(int in)
{
	if(in<cnt[1])	return 1;
	else if(in>=cnt[1]+cnt[2])		 return 3;
	return 2;
}

int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);

	scanf("%d",&N);

	FOR(inp,0,N){
		scanf("%d",&ar[inp]);
		cnt[ar[inp]]++;
	}

	int ans=0;
	FOR(fr,0,N-1){
		int id1=range(fr);
		if(id1==ar[fr])		continue;

		FOR(sc,fr+1,N){
			int id2=range(sc);

			if(ar[fr]!=ar[sc] && id1!=id2 && (id1==ar[sc] && id2==ar[fr])){
				ans++;
				swap(ar[fr],ar[sc]);
				break;
			}
		}
	}

	int it=0;
	EFOR(d,1,2){
		it+=cnt[d];
		FOR(i,cnt[d-1],it){
			int ch=range(i);

			if(ch!=ar[i]){
				int j=it;
				for(;ar[j]!=d;j++);

				swap(ar[i],ar[j]);
				ans++;
			}
		}
	}
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
