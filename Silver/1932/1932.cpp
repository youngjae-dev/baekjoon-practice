#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<vector<int>> triangle(N);

	// 정수 삼각형 각 행의 숫자 저장
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			int num; cin >> num;
			triangle[i].push_back(num);
		}
	}

	vector<vector<int>> dp = triangle;

	// Bottom-up : 아래부터 위로 올라가면서 최대 합을 갱신
	for (int i = N - 2; i >= 0; --i) {	// 마지막 전 행부터 시작
		for (int j = 0; j <= i; ++j) {

			// 현재 위치 값 + 아래 행의 j, j+1 중 더 큰 값
			dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}

	// 꼭대기(dp[0][0])가 전체 경로 중 최대 합
	cout << dp[0][0];
}