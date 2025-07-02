#include<iostream>
#include<queue>
using namespace std;

int main() {
	const int MAX = 200001; // 최대 접근 가능 index
	bool visited[MAX] = { false }; // false : 방문 X | true : 방문 O
	int time[MAX] = { 0 };         // 각 위치까지 시작점(N)을 기준으로 걸린 시간

	int N, K; // N : 수빈이의 위치 | K : 동생의 위치
	cin >> N >> K;

	queue<int> L;
	visited[N] = true; // 시작 위치 방문 처리

	// BFS 시작
	L.push(N);
	while (!L.empty()) {
		int curr = L.front(); L.pop();
		
		// 동생 위치에 도달하면 시간 출력 후 종료
		if (curr == K) {
			cout << time[curr];
			break;
		}

		// 현위치 -1 이 접근 가능할때
		if (curr - 1 >= 0) {
			if (visited[curr - 1] == false) {
				visited[curr - 1] = true;
				time[curr - 1] = time[curr] + 1;
				L.push(curr - 1);
			}
		}

		// 현위치 +1 이 접근 가능할때
		if (curr + 1 < MAX) {
			if (visited[curr + 1] == false) {
				visited[curr + 1] = true;
				time[curr + 1] = time[curr] + 1;
				L.push(curr + 1);
			}
		}

		// 현위치 *2 가 접근 가능할때
		if (curr * 2 < MAX) {
			if (visited[2 * curr] == false) {
				visited[2 * curr] = true;
				time[2 * curr] = time[curr] + 1;
				L.push(2 * curr);
			}
		}
	}
}