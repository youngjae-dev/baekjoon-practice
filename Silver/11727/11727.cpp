#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N; cin >> N;

	// dp[i] : 2xi 타일 채우는 경우의 수
	vector<int> dp(N + 1);

	// 초기 조건
	dp[1] = 1;
	if (N >= 2)dp[2] = 3;

	// 점화식: dp[i] = dp[i-1] + 2*dp[i-2]
	for (int i = 3; i <= N; ++i) {
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
	}
	cout << dp[N];
}