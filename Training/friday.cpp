/*
ID: celesti3
PROG: friday
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
#define PB(A,B) A.push_back(B);
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);

	int N;
	scanf("%d",&N);

	int st=0;
	int days[]={31,28,31,30,31,30,31,31,30,31,30,31};

//	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
	int ans[7];
	MEM(ans,0);

	EFOR(yr,1900,1900+N-1)
		FOR(mnth,0,12)
			EFOR(date,1,days[mnth]){
				if(date==13)	++ans[st];
				st=(st+1)%7;

				if(mnth==1 && date==28 && yr%4==0 && (yr%100!=0 || (yr%100==0 && yr%400==0)))
					st=(st+1)%7;
			}

	printf("%d %d %d %d %d %d %d\n",ans[5],ans[6],ans[0],ans[1],ans[2],ans[3],ans[4]);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
