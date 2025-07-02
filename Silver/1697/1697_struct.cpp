#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 정점 방문 상태
enum class Status { UNEXPLORED, VISITED };

// 정점 구조체
struct Vertex {
	int vid;
	int level;
	Status status;
	Vertex(int vid) :vid(vid), level(0), status(Status::UNEXPLORED) {}
};

int main() {
	int N, K; // N : 수빈이의 위치 | K : 동생의 위치
	cin >> N >> K;
	vector<Vertex*> field(200001); // 이동 가능한 field

	// 시작 위치와 동생의 위치가 같다면 0 출력 후 종료
	if (N == K) {
		cout << 0;
		return 0;
	}

	// 모든 위치 정점 초기화
	for (int i = 0; i < field.size(); ++i) {
		field[i] = new Vertex(i);
	}

	Vertex* start = field[N]; // 시작 위치의 정점
	Vertex* end = field[K];   // 목표 위치의 정점
	start->level = 0; // 시작 위치의 레벨 초기화
	start->status = Status::VISITED; // 시작 위치의 방문 상태 갱신

	// BFS 시작
	queue<Vertex*>L;
	L.push(start);
	while (!L.empty()) {
		Vertex* pos = L.front(); L.pop();

		// 목표 위치에 도달시 출력 후 종료
		if (pos == end) {
			cout << pos->level;
			break;
		}

		// 3가지 방향으로 이동 가능한 경우 탐색
		if (pos->vid - 1 >= 0) {
			Vertex* tmp = field[pos->vid - 1];
			if (tmp->status == Status::UNEXPLORED) {
				tmp->level = pos->level + 1;
				tmp->status = Status::VISITED;
				L.push(tmp);
			}
		}
		if (pos->vid + 1 < field.size()) {
			Vertex* tmp = field[pos->vid + 1];
			if (tmp->status == Status::UNEXPLORED) {
				tmp->level = pos->level + 1;
				tmp->status = Status::VISITED;
				L.push(tmp);
			}
		}
		if (pos->vid * 2 < field.size()) {
			Vertex* tmp = field[pos->vid * 2];
			if (tmp->status == Status::UNEXPLORED) {
				tmp->level = pos->level + 1;
				tmp->status = Status::VISITED;
				L.push(tmp);
			}
		}
	}
}