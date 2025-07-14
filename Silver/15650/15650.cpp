#include<iostream>
#include<vector>
using namespace std;

// 길이가 M인 오름차순 수열을 출력하는 함수
void sequence(int startNum, int N, int M, vector<int>& v) {
	if (v.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = startNum; i <= N; ++i) {
		v.push_back(i);            // 현재 숫자 추가
		sequence(i + 1, N, M, v);  // 다음 숫자 탐색
		v.pop_back();              // 백트래킹
	}
}

int main() {
	int N, M;
	cin >> N >> M; // 1부터 N까지 자연수 중에서 길이가 M인 오름차순 수열 출력
	vector<int> v;
	sequence(1, N, M, v);
}