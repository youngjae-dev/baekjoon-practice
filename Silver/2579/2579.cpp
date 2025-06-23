#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N; cin >> N;

	vector<int>arr(N); //누적 합 관리
	vector<int>score(N); // 점수관리

	for (int i = 0; i < N; ++i) {
		cin >> score[i];
	}
	for (int i = 0; i < N; ++i) {
		if (i == 0)arr[i] = score[i]; // 첫번째 계단
		else if (i == 1)arr[i] = score[i] + score[i - 1]; // 2번째 계단
		else if (i == 2)arr[i] = max(score[i - 1], score[i - 2]) + score[i]; // 3번째 계단
		// 그 외에 계단은 동일하게 처리
		else {
			// 특정 계단에 도달하는 2가지 경우
			// i-2 -> i vs i-3 -> i-1 -> i
			arr[i] = score[i] + max(arr[i - 2], score[i - 1] + arr[i - 3]);
		}
	}
	// 마지막 계단의 누적합
	cout << arr[N - 1];
}