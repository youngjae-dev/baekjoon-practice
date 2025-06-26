#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;

		// 파도반 수열의 값은 매우 커질 수 있으므로
		// int형으로는 오버플로우 발생
		// 따라서 long long 타입 사용
		vector<long long> dp(N + 1);

		// P(1)부터 P(5)까지는 불규칙적이므로 명시적으로 초기화
		// 또한 N의 크기에 따라 접근 가능한 범위만 초기화해야함
		if (N >= 1) dp[1] = 1;
		if (N >= 2) dp[2] = 1;
		if (N >= 3) dp[3] = 1;
		if (N >= 4) dp[4] = 2;
		if (N >= 5) dp[5] = 2;

		// 점화식 : P(N) = P(N-5) + P(N-1)
		for (int i = 6; i <= N; ++i) {
			dp[i] = dp[i - 5] + dp[i - 1];
		}
		cout << dp[N] << '\n';
	}
}