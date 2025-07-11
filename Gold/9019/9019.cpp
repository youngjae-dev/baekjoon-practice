#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

// 4개의 명령어:
// D : n -> (2n) mod 10000
// S : n -> (n-1) mod 10000 (0은 9999로)
// L : n의 각 자릿수를 왼쪽으로 회전 (1234 -> 2341)
// R : n의 각 자릿수를 오른쪽으로 회전 (1234 -> 4123)
char cmd[4] = { 'D','S','L','R' };

int main() {
	int T; cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;

		vector<bool> visited(10000, false); // 이미 방문한 숫자 재탐색 방지
		queue<pair<int, string>> q;         // 현재 숫자와 그 숫자에 도달하기까지의 명령어 문자열 저장

		// BFS 시작
		visited[A] = true;
		q.push({ A, "" });

		while (!q.empty()) {
			int curr = q.front().first;
			string tmp = q.front().second;
			q.pop();

			// 목표 숫자 도달 시 출력 후 종료
			if (curr == B) {
				cout << tmp << '\n';
				break;
			}

			// 각 명령어를 통해 숫자 변환 시도
			for (int i = 0; i < 4; ++i) {
				int num;
				if (cmd[i] == 'D') num = (2 * curr) % 10000;
				else if (cmd[i] == 'S') num = (curr - 1 + 10000) % 10000;
				else if (cmd[i] == 'L') num = (curr % 1000) * 10 + curr / 1000;
				else if (cmd[i] == 'R') num = (curr / 10) + (curr % 10) * 1000;

				// 방문하지 않은 숫자인 경우 큐에 삽입 및 방문 표시
				if (!visited[num]) {
					visited[num] = true;
					q.push({ num, tmp + cmd[i] });
				}
			}
		}
	}
}
