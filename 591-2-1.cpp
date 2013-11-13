#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define MIN(x,y) ((x)<(y)?(x):(y))

class TheArithmeticProgression
{
	public:
		double minimumChange(int a, int b, int c)
		{
			return fabs((c+a-2*b)/2.0);
		}	
};

int main()
{
}
