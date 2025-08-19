#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N; cin >> N;

	// 이전 줄의 최대/최소 점수 저장
	int preMax[3] = { 0,0,0 };
	int preMin[3] = { 0,0,0 };
	for (int i = 0; i < N; ++i) {
		int num1, num2, num3;
		cin >> num1 >> num2 >> num3;

		// 현재 줄의 최대/최소 점수 갱신
		int curMax[3];
		int curMin[3];

		// 최대 점수 갱신
		curMax[0] = num1 + max(preMax[0], preMax[1]);
		curMax[1] = num2 + max({ preMax[0], preMax[1], preMax[2] });
		curMax[2] = num3 + max(preMax[1], preMax[2]);

		// 최소 점수 갱신
		curMin[0] = num1 + min(preMin[0], preMin[1]);
		curMin[1] = num2 + min({ preMin[0], preMin[1], preMin[2] });
		curMin[2] = num3 + min(preMin[1], preMin[2]);

		// 다음 반복을 위해 이전 줄에 현재 줄 정보 저장
		for (int j = 0; j < 3; ++j) {
			preMax[j] = curMax[j];
			preMin[j] = curMin[j];
		}
	}

	// 마지막 줄의 최대/최소 점수 출력
	cout << max({ preMax[0], preMax[1], preMax[2] }) << ' ' << min({ preMin[0], preMin[1], preMin[2] });
}