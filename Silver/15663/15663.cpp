#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 문제 조건을 만족하는 수열 출력 함수
void sequence(const vector<int>& numbers, int M, vector<int>& seq_list, vector<bool>& visited) {

	// M개의 숫자 추출시 출력
	if (seq_list.size() == M) {
		for (int tmp : seq_list) cout << tmp << ' ';
		cout << '\n';
		return;
	}

	int prev = -1; // 같은 깊이에서 이전에 쓴 값 저장 -> 같은 값은 건너띔

	// 수열 만들기
	for (int i = 0; i < numbers.size(); ++i) {
		if (visited[i]) continue;         // 수열에 포함된 숫자는 건너띔
		if (prev == numbers[i]) continue; // 같은 깊이에서 이미 사용된 값이면 건너띔

		visited[i] = true;                // 현재 숫자 사용 표시
		seq_list.push_back(numbers[i]);   // 수열에 숫자 추가
		prev = numbers[i];                // 이전 값 갱신

		sequence(numbers, M, seq_list, visited);

		// 백트래킹
		seq_list.pop_back();
		visited[i] = false;
	}

}

int main() {

	// N개의 자연수 중 M개의 숫자를 추출
	int N, M;
	cin >> N >> M;

	vector<int> numbers(N);
	// 숫자 초기화
	for (int i = 0; i < N; ++i) {
		cin >> numbers[i];
	}
	
	sort(numbers.begin(), numbers.end()); // 사전순 출력을 위해 오름차순으로 정렬

	vector<int> seq_list;
	vector<bool> visited(N + 1, false);
	sequence(numbers, M, seq_list, visited);
}