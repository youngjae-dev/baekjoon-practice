#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N; cin >> N;

	// dp[i] : i를 제곱수들의 합으로 표현할 때 최소 개수
	vector<int> dp(N + 1);

	for (int i = 1; i <= N; ++i) {

		// 최악의 경우 : 1^2을 i번 더함
		dp[i] = i;

		for (int j = 1; j * j <= i; ++j) {
			// 가능한 제곱수 j^2을 하나 사용
			// i - j^2을 구성하는 최소 개수(dp[i - j^2])에
			// 사용한 j^2 하나를 추가해서 비교
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N];
}
