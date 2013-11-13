#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 55;

class YetAnotherTwoTeamsProblem
{
	public:
		vector <int> s;
		int n;
		int sum[MAX][MAX];
		
		long long fun(int i, int sumnow, int pos)
		{
			if(sumnow >= sum[0][n-1]/2.0+s[i]) return 0;
			if(pos < n && sumnow+sum[pos][n-1] <= sum[0][n-1]/2.0) return 0;
			
			long long ans = 0;
			if(sumnow > sum[0][n-1]/2.0 && sumnow < sum[0][n-1]/2.0+s[i]) ans += 1;
			if(pos < n && sumnow < sum[0][n-1]/2.0+s[i]) 
			{
				if(pos pos < n-1 && sumnow + s[pos+1] < sum[0][n-1]/2.0+s[i])
				{
					ans += fun(i,sumnow+s[i],pos+1) + fun(i,sumnow,pos+1);
				}
			}
			
			return ans;
		} 
		
		long long count(vector <int> skill)
		{
			s.assign(skill.begin(),skill.end());
			sort(s.begin(),s.end());
			n = s.size();
			
			memset(sum,0,sizeof(sum));
			sum[0][0] = s[0];
			for(int i=1; i<n; i++)
			{
				for(int j=0; j<=i; j++)
				{
					sum[j][i] = sum[j][i-1]+s[i];
				}
			}
			
			long long ans = 0;
			for(int i=0; i<n; i++)
			{
				ans += fun(i,s[i],i+1);
				cout<<ans<<endl;
			}
			return ans;
		}
}; 

int main()
{
	YetAnotherTwoTeamsProblem t;
	int ss[] = {1, 1, 1, 1, 1};
	vector<int> s;
	for(int i=0; i<5; i++)
		s.push_back(ss[i]);
	cout<<t.count(s)<<endl;
}
