/*
ID: celesti3
PROG: beads
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
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);

	int N;
	scanf("%d",&N);

	char neck[352];
	scanf("%s",neck);

	bool all=true;
	FOR(chk,1,N)
		if(neck[chk]!=neck[chk-1]){
			all=false;
			break;
		}

	if(all)
		printf("%d\n",N);
	else {
		int ans=0;
		FOR(all,0,N){
			int fwd=1,rev=0;
			char bd=neck[all];

			int pos=all+1;
			for(;pos!=all;pos++){
				pos%=N;

				if((bd=='w') && (neck[pos]!='w'))
					bd=neck[pos];

				if((neck[pos]==bd) || (neck[pos]=='w'))
					++fwd;
				else
					break;
			}

			pos=all-1;
			bd=neck[pos];
			for(;pos!=all;pos--){
				pos=(pos+N)%N;

				if((bd=='w') && (neck[pos]!='w'))
					bd=neck[pos];
				if((neck[pos]==bd) || (neck[pos]=='w'))
					++rev;
				else
					break;
			}
			ans=max(ans,fwd+rev);
		}
		ans=min(ans,N);
		printf("%d\n",ans);
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}
