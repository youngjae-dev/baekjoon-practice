#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// DFS와 BFS 수행시 정점의 방문 상태 마킹
enum class Status { UNEXPLORED, VISITIED };

struct Edge;

// 정점 구조체
struct Vertex {
	int vid;
	vector<Edge*> incident_edges;
	Status status;
	Vertex(int vid) :vid(vid),status(Status::UNEXPLORED) {}
};

// 간선 구조체
struct Edge {
	Vertex* src;
	Vertex* dst;
	Edge(Vertex* src, Vertex* dst) :src(src), dst(dst) {}
};

// 무향 그래프 클래스
class Graph {
private:
	vector<Vertex*> vertices_list; // 모든 정점 리스트
	vector<Edge*> edges_list; // 모든 간선 리스트
	int connectedComponent; // 연결 요소의 개수

	// 정점 찾는 함수
	Vertex* find_vertex(int vid) {
		for (Vertex* v : vertices_list) {
			if (v->vid == vid) {
				return v;
			}
		}
		return nullptr;
	}

	// 간선과 정점이 주어졌을때, 반대편 정점 구하는 함수
	Vertex* opposite(Edge* e, Vertex* v) {
		if (e->src == v)return e->dst;
		if (e->dst == v)return e->src;
	}

	// 간선 찾는 함수
	Edge* find_edge(Vertex* src, Vertex* dst) {
		if (src->incident_edges.size() < dst->incident_edges.size()) {
			for (Edge* e : src->incident_edges) {
				if (opposite(e, src) == dst) {
					return e;
				}
			}
			return nullptr;
		}
		else {
			for (Edge* e : dst->incident_edges) {
				if (opposite(e, dst) == src) {
					return e;
				}
			}
			return nullptr;
		}
	}
public:
	Graph() {
		connectedComponent = 0; // 클래스 객체 생성시 연결 요소 개수 0으로 초기화
	}

	// 정점 삽입 함수
	void insertVertex(int vid) {
		Vertex* new_vertex = new Vertex(vid);
		vertices_list.push_back(new_vertex);
	}

	// 간선 삽입 함수
	void insertEdge(int vid1, int vid2) {
		Vertex* src = find_vertex(vid1);
		Vertex* dst = find_vertex(vid2);
		Edge* new_edge = new Edge(src, dst);

		edges_list.push_back(new_edge);

		src->incident_edges.push_back(new_edge);

		dst->incident_edges.push_back(new_edge);
	}

	// 모든 정점 순회하면서 마킹 안된 정점을 기준으로 DFS 시작
	void startDFS() {
		for (Vertex* v : vertices_list) {
			if (v->status == Status::UNEXPLORED) {
				++connectedComponent;
				DFS(v);
			}
		}
	}

	// DFS 함수
	void DFS(Vertex* v) {
		v->status = Status::VISITIED;
		for (Edge* e : v->incident_edges) {
			Vertex* w = opposite(e, v);
			if (w->status == Status::UNEXPLORED) {
				DFS(w);
			}
		}
	}

	// 모든 정점 순회하면서 마킹 안된 정점을 기준으로 BFS 시작
	void startBFS() {
		for (Vertex* v : vertices_list) {
			if (v->status == Status::UNEXPLORED) {
				++connectedComponent;
				BFS(v);
			}
		}
	}

	// BFS 함수
	void BFS(Vertex* v) {
		v->status = Status::VISITIED;
		queue<Vertex*> L;
		L.push(v);
		while (!L.empty()) {
			Vertex* vertex = L.front(); L.pop();
			for (Edge* e : vertex->incident_edges) {
				Vertex* w = opposite(e, vertex);
				if (w->status == Status::UNEXPLORED) {
					w->status = Status::VISITIED;
					L.push(w);
				}
			}
		}
	}

	// 연결 요소 개수 리턴 함수
	int getConnectiedComponent() {
		return connectedComponent;
	}

	// 마킹 상태 리셋 함수
	void reset() {
		for (Vertex* v : vertices_list) v->status = Status::UNEXPLORED;
	}
};

int main() {
	int N, M; // N : 정점의 개수 | M : 간선의 개수
	cin >> N >> M;

	Graph G;

	// 정점 번호 1~N
	for (int i = 1; i <= N; ++i) {
		G.insertVertex(i);
	}

	// 간선 삽입
	while (M--) {
		int vid1, vid2;
		cin >> vid1 >> vid2;
		G.insertEdge(vid1, vid2);
	}

	// DFS 시작 후 연결 요소 출력
	G.startDFS();
	cout << G.getConnectiedComponent();

	// BFS 시작 후 연결 요소 출력 또한 가능
	// 단 DFS 실행 후 바로 BFS 실행시 마킹 상대 유지 되어있으므로
	// 마킹 상태 리셋 필요
	/*
	G.startBFS();
	cout << G.getConnectedComponent();
	*/
}