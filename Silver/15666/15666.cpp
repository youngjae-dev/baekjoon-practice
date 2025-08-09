#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 길이 M의 수열 생성 (중복 선택 허용, 비내림차순, 같은 depth 중복 제거)
void sequence(const vector<int>& numbers, int M, vector<int>& seq_list, int start) {
	// 길이 M이 되면 현재 수열을 출력하고 재귀 종료
	if (seq_list.size() == M) {
		for (int tmp : seq_list)cout << tmp << ' ';
		cout << '\n';
		return;
	}

	int prev = -1; // 같은 depth에서 이미 사용한 값 저장 (같은 값 중복 출력 방지)

	// 현재 depth에서 start 인덱스부터 탐색 (i 그대로 넘겨 중복 선택 허용)
	for (int i = start; i < numbers.size(); ++i) {
		if (prev == numbers[i]) continue; // 단, 같은 depth에서 같은 값은 건너띔

		seq_list.push_back(numbers[i]);

		sequence(numbers, M, seq_list, i);

		seq_list.pop_back();
		prev = numbers[i];
	}
}

int main() {
	int N, M;      // N개의 숫자 중 길이가 M인 수열
	cin >> N >> M;

	// 숫자 초기화
	vector<int> numbers(N);
	for (int i = 0; i < N; ++i) {
		cin >> numbers[i];
	}

	// 비내림차순과 사전순 출력을 위한 오름차순 정렬
	sort(numbers.begin(), numbers.end());
	vector<int> seq_list;

	sequence(numbers, M, seq_list, 0);
}