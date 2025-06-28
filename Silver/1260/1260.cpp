#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 정점과 간선의 상태
// BFS와 DFS에서 쓰임
enum class Status { UNEXPLORED, VISITED, CROSS, DISCOVERY, BACK };

struct Edge;

// 정점 구조체
struct Vertex {
	int vid;
	vector<Edge*>incident_edges;
	Status status;
	Vertex(int vid) :vid(vid), status(Status::UNEXPLORED) {}
};

// 간선 구조체
struct Edge {
	Vertex* src;
	Vertex* dst;
	Status status;
	Edge(Vertex* src, Vertex* dst) :src(src), dst(dst), status(Status::UNEXPLORED) {}
};

class Graph {
private:

	// 정점 목록들 관리
	vector<Vertex*>vertices_list;

	// 간선 목록들 관리
	vector<Edge*>edges_list;

	// 정점 찾기
	Vertex* find_vertex(int vid) {
		for (Vertex* v : vertices_list) {
			if (v->vid == vid) {
				return v;
			}
		}
		return nullptr;
	}

	// 해당 정점과 간선이 주어졌을때 반대편 정점
	Vertex* opposite(Edge* e, Vertex* v) {
		if (e->src == v)return e->dst;
		if (e->dst == v)return e->src;
	}

	// 간선 찾기
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

	// DFS나 BFS 이후에 마킹된 정점 및 간선 초기화
	void reset() {
		for (Vertex* v : vertices_list) {
			v->status = Status::UNEXPLORED;
		}
		for (Edge* e : edges_list) {
			e->status = Status::UNEXPLORED;
		}
	}
public:
	Graph() = default;

	// 정점 삽입
	void InsertVertex(int vid) {
		Vertex* new_vertex = new Vertex(vid);
		vertices_list.push_back(new_vertex);
	}

	// 간선 삽입
	void InsertEdge(int vid1, int vid2) {
		Vertex* src = find_vertex(vid1);
		Vertex* dst = find_vertex(vid2);

		Edge* new_edge = new Edge(src, dst);
		edges_list.push_back(new_edge);

		// 간선의 한 정점의 인접 정점들 오름차순 정렬
		auto it = src->incident_edges.begin();
		while (it != src->incident_edges.end() && opposite(*it, src)->vid < opposite(new_edge, src)->vid) {
			++it;
		}
		src->incident_edges.insert(it, new_edge);

		// 간선의 또 다른 정점의 인접 정점들 오름차순 정렬
		it = dst->incident_edges.begin();
		while (it != dst->incident_edges.end() && opposite(*it, dst)->vid < opposite(new_edge, dst)->vid) {
			++it;
		}
		dst->incident_edges.insert(it, new_edge);
	}

	// DFS의 시작 정점 입력 받고 DFS 시작
	void startDFS(int startNum) {
		DFS(find_vertex(startNum));
		cout << '\n';
		reset();
	}

	// BFS의 시작 정점 입력 받고 BFS 시작
	void startBFS(int startNum) {
		BFS(find_vertex(startNum));
		cout << '\n';
		reset();
	}

	void DFS(Vertex* v) {
		v->status = Status::VISITED;
		cout << v->vid << ' ';

		// 해당 정점의 인접 정점들 순회하면서 마킹 여부 확인
		for (Edge* e : v->incident_edges) {
			Vertex* w = opposite(e, v);

			// 마킹 안되어 있으면 재귀적으로 순회
			if (w->status == Status::UNEXPLORED) {
				e->status = Status::DISCOVERY;
				DFS(w);
			}

			// 마킹 되어 있으면 간선을 BACK으로 마킹
			else {
				e->status = Status::BACK;
			}
		}
	}
	void BFS(Vertex* v) {
		v->status = Status::VISITED;
		cout << v->vid << ' ';

		// BFS를 하기 위한 queue 선언
		// 시작 정점을 기준으로 Level 별로 push / pop
		queue<Vertex*> L;

		// 시작 정점 마킹 후 queue에 삽입
		L.push(v);
		while (!L.empty()) {
			Vertex* vertex = L.front(); L.pop();

			// queue에 있는 정점들의 인접 정점들부터 순회
			for (Edge* e : vertex->incident_edges) {
				Vertex* w = opposite(e, vertex);

				// 마킹 되어있지 않으면 마킹 후 queue에 삽입
				if (w->status == Status::UNEXPLORED) {
					e->status = Status::DISCOVERY;
					w->status = Status::VISITED;
					cout << w->vid << ' ';
					L.push(w);
				}
				// 마킹 되어 있으면 CROSS로 마킹
				else {
					e->status = Status::CROSS;
				}
			}
		}
	}
};

int main() {

	// N : 정점 개수 | M : 간선 개수 | V : DFS/BFS 시작 정점 번호
	int N, M, V;
	cin >> N >> M >> V;
	Graph G;

	// 정점 번호는 1~N
	for (int i = 1; i <= N; ++i) {
		G.InsertVertex(i);
	}

	// 간선 삽입
	while (M--) {
		int vid1, vid2;
		cin >> vid1 >> vid2;
		G.InsertEdge(vid1, vid2);
	}

	// DFS와 BFS 순회
	G.startDFS(V);
	G.startBFS(V);
}