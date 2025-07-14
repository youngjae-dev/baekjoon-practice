#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// N개의 자연수 중에서 M개를 골라 사전 순으로 증가하는 모든 순열 출력
// 백트래킹을 통해 가능한 수열을 완성하는 함수
void sequence(int depth, vector<int>& v, const vector<int>& numbers, vector<bool>& visited) {
	if (depth == v.size()) {  // 수열의 길이가 M에 도달했을 때 출력
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < numbers.size(); ++i) {
		if (!visited[i]) {
			visited[i] = true;           // 숫자 사용 표시
			v[depth] = numbers[i];       // 현재 위치에 숫자 저장
			sequence(depth + 1, v, numbers, visited);  // 다음 위치로 이동
			visited[i] = false;          // 백트래킹 (숫자 사용 취소)
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> numbers(N);           // 입력으로 주어질 N개의 자연수
	vector<bool> visited(N, false);   // 각 숫자의 사용 여부를 표시
	vector<int> v(M);                 // 길이 M인 결과 수열

	// 숫자 입력
	for (int i = 0; i < N; ++i) cin >> numbers[i];

	sort(numbers.begin(), numbers.end());  // 사전 순 출력을 위한 정렬

	sequence(0, v, numbers, visited);      // 백트래킹 시작
}