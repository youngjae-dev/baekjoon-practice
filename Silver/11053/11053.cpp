#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N; // 수열의 길이 입력
	vector<int> numbers(N + 1);

	// 수열 값 입력 (1-based index)
	for (int i = 1; i <= N; ++i) {
		cin >> numbers[i];
	}

	vector<int> dp(N + 1, 1);  // 각 위치에서 끝나는 증가 부분 수열의 최대 길이 저장
	int max_length = 1;        // 전체 수열 중 최장 증가 부분 수열의 길이

	// 다이나믹 프로그래밍 수행
	for (int i = 2; i <= N; ++i) {
		// 현재 원소 이전의 모든 원소들과 비교
		for (int j = 1; j < i; ++j) {
			if (numbers[i] > numbers[j]) {
				// numbers[i]가 numbers[j]보다 크다면, 증가 부분 수열 갱신
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		// 전체 최댓값 갱신
		max_length = max(max_length, dp[i]);
	}

	// 결과 출력
	cout << max_length;
}