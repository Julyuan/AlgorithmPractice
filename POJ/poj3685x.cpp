#include <iostream>
using namespace std;
 
typedef long long LL;
LL T, N, M;
 
LL f(const LL& i, const LL& j)
{
	return i * i + 100000 * i + j * j - 100000 * j + i * j;
}
 
// mid 是否小于第M小的数
bool is_less(const LL& mid)
{
	LL less_count = 0;	// 比mid小的数的个数
	for (int j = 1; j < N + 1; ++j)
	{
		// 当然不能这么搜啦
// 		for (int i = 1; i < N + 1; ++i)
// 		{
// 
// 		}
		int lb = 0, ub = N + 1;
		while (ub - lb > 1)
		{
			int i = (ub + lb) >> 1;
			if (f(i, j) < mid)
			{
				lb = i;
			}
			else
			{
				ub = i;
			}
		}
		less_count += lb;
	}
 
	return less_count < M;
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
//	freopen("in.txt", "r", stdin);
//	freopen("out1.txt", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		LL lb = -100000 * N, ub = N * N + 100000 * N + N * N + N * N;
		while (ub - lb > 1)
		{
			LL mid = (ub + lb) >> 1;
			if (is_less(mid))
			{
				lb = mid;
			}
			else
			{
				ub = mid;
			}
		}
		cout << lb << endl;
	}
	return 0;
}