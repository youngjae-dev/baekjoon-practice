#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 정점의 탐색 상태
enum class Status { UNEXPLORED, VISITED };

struct Edge;

// 정점
struct Vertex {
	int vid; // 정점 고유 번호
	int kevinNum; // 해당 정점의 케빈 베이컨 수
	int level; // BFS 탐색 중 거리 레벨
	Status status;
	vector<Edge*> incident_edges;
	Vertex(int vid) :vid(vid), kevinNum(0), level(0), status(Status::UNEXPLORED) {}
};

// 간선
struct Edge {
	Vertex* src;
	Vertex* dst;
	Edge(Vertex* src, Vertex* dst) :src(src), dst(dst) {}
};

class Graph {
private:
	vector<Vertex*> vertices_list;
	vector<Edge*> edges_list;

	// vid에 해당 하는 정점 포인터 반환
	Vertex* find_vertex(int vid) {
		for (Vertex* v : vertices_list) {
			if (v->vid == vid) return v;
		}
		return nullptr;
	}

	// 두 정점 사이의 간선 포인터 반환
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

	// 간선 e 기준으로 정점 v의 반대편 정점 반환
	Vertex* opposite(Edge* e, Vertex* v) {
		if (e->dst == v)return e->src;
		if (e->src == v)return e->dst;
	}
	
	// 모든 정점의 탐색 상태 초기화
	void reset() {
		for (Vertex* v : vertices_list) {
			v->status = Status::UNEXPLORED;
			v->level = 0;
		}
	}
public:
	Graph() = default;

	// 정점 추가
	void insertVertex(int vid) {
		Vertex* new_vertex = new Vertex(vid);
		vertices_list.push_back(new_vertex);
	}

	// 간선 추가(중복 X)
	void insertEdge(int vid1, int vid2) {
		Vertex* src = find_vertex(vid1);
		Vertex* dst = find_vertex(vid2);
		if (find_edge(src, dst) != nullptr) return;

		Edge* new_edge = new Edge(src, dst);

		edges_list.push_back(new_edge);
		src->incident_edges.push_back(new_edge);
		dst->incident_edges.push_back(new_edge);
	}

	// 모든 정점 기준 BFS 수행 후 케빈 베이컨 수 계산
	void BFS() {
		for (Vertex* v : vertices_list) {
			v->status = Status::VISITED;
			v->level = 0;

			queue<Vertex*> L;
			L.push(v);

			while (!L.empty()) {
				Vertex* vertex = L.front(); L.pop();
				for (Edge* e : vertex->incident_edges) {
					Vertex* w = opposite(e, vertex);
					if (w->status == Status::UNEXPLORED) {
						w->status = Status::VISITED;
						w->level = vertex->level + 1;
						v->kevinNum += w->level;
						L.push(w);
					}
				}
			}
			reset();
		}
	}

	// 케빈 베이컨 수가 가장 작은 정점 번호 반환
	// 단, 여러 명일 경우 번호가 작은 정점 반환
	int minKevinNum() {
		auto min = vertices_list.begin();
		for (auto it = vertices_list.begin(); it != vertices_list.end(); ++it) {
			if ((*min)->kevinNum > (*it)->kevinNum) {
				min = it;
			}
			else if ((*min)->kevinNum == (*it)->kevinNum && (*min)->vid > (*it)->vid) {
				min = it;
			}
		}
		return (*min)->vid;
	}
};

int main() {
	int N, M; // N : 유저의 수, M : 친구 관계의 수
	cin >> N >> M;

	Graph G;
	for (int i = 1; i <= N; ++i) {
		G.insertVertex(i);
	}

	while (M--) {
		int vid1, vid2;
		cin >> vid1 >> vid2;
		G.insertEdge(vid1, vid2);
	}

	G.BFS(); // 케빈 베이컨 수 계산
	cout << G.minKevinNum(); // 최소 케빈 수를 가진 정점 번호 출력
}