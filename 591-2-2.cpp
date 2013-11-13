#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

class ConvertibleStrings
{
	public:
		int cnt[15][15];
		int calmax(int flag[15],int lev)
		{
			if(lev>=9) return 0;
			
			int ans = 0;
			for(int i=0; i<9; i++)
			{
				if(cnt[lev][i]>0 && flag[i] == 0)
				{
					int tmp1;
					flag[i] = 1;
					tmp1 = cnt[lev][i] + calmax(flag,lev+1);
					if(tmp1>ans) ans = tmp1;
					flag[i] = 0;
				}
			}
			int tmp2 = calmax(flag,lev+1);
			if(tmp2 > ans) ans = tmp2;
 			return ans;
		}
		int leastRemovals(string A, string B)
		{
			memset(cnt,0,sizeof(cnt));
			
			int n = A.length();
			
			for(int i=0; i<n; i++)
			{
				cnt[A[i]-'A'][B[i]-'A']++;
			}
			
			int flag[15];
			memset(flag,0,sizeof(flag));
			return n-calmax(flag,0);
		}
}; 
