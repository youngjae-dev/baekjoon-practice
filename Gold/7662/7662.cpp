#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int testcase; cin >> testcase;

		priority_queue<int> max_q;                             // 내림차순 우선순위 큐
		priority_queue<int, vector<int>, greater<int>> min_q;  // 오름차순 우선순위 큐
		unordered_map<int, int> delete_num;                    // 삭제 연산을 위한 마킹 저장
		
		while (testcase--) {
			char cmd;
			int num;
			cin >> cmd >> num;

			// 삽입 연산
			if (cmd == 'I') {
				max_q.push(num);
				min_q.push(num);
				++delete_num[num]; // // 'num'의 삽입 개수 증가 -> 삽입된 횟수 기록
			}

			// 삭제연산
			else if (cmd == 'D') {

				// 최댓값 제거
				if (num == 1) {

					// 큐가 비어있지 않고, 최댓값이 유효한 값일 때까지 pop
					while (!max_q.empty() && delete_num[max_q.top()] == 0) max_q.pop();

					if (!max_q.empty()) {
						--delete_num[max_q.top()]; // 논리적으로 최댓값 제거 (실제 삭제는 아님)
						max_q.pop();
					}
				}

				// 최솟값 제거
				else if (num == -1) {

					// 큐가 비어있지 않고, 최솟값이 유효한 값일 때까지 pop
					while (!min_q.empty() && delete_num[min_q.top()] == 0) min_q.pop();

					if (!min_q.empty()) {
						--delete_num[min_q.top()]; // 논리적으로 최솟값 제거 (실제 삭제는 아님)
						min_q.pop();
					}
				}
			}

		}

		// // 큐의 top이 실제로는 삭제된 값이라면 정리
		while (!max_q.empty() && delete_num[max_q.top()] == 0) max_q.pop();
		while (!min_q.empty() && delete_num[min_q.top()] == 0) min_q.pop();

		// 결과 출력
		if (max_q.empty() || min_q.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << max_q.top() << ' ' << min_q.top() << '\n';
		}
	}
}