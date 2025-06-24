#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 정점과 간선의 상태
enum class Status { UNEXPLORED, VISITED, DISCOVERY, CROSS };

struct Edge;
// 정점(컴퓨터 역할)
struct Vertex {
	int vid;
	Status status;
	vector<Edge*> incident_edges;
	Vertex(int vid) :vid(vid), status(Status::UNEXPLORED) {}
};
// 간선 (컴퓨터 사이에 이어지는 네트워크 역할)
struct Edge {
	Vertex* src;
	Vertex* dst;
	Status status;
	Edge(Vertex* src, Vertex* dst) :src(src), dst(dst), status(Status::UNEXPLORED) {}
};

class Graph {
private:
	vector<Vertex*>vertices_list;
	vector<Edge*>edges_list;
	vector<Vertex*>virusComputer;
	Vertex* find_vertex(int vid) {
		for (Vertex* v : vertices_list) {
			if (v->vid == vid) {
				return v;
			}
		}
		return nullptr;
	}
	// 주어진 컴퓨터와 연결된 반대쪽 컴퓨터 리턴
	Vertex* opposit(Edge* e, Vertex* v) {
		if (e->dst == v)return e->src;
		if (e->src == v)return e->dst;
	}
public:
	Graph() = default;
	// 컴퓨터 등록
	bool insertVertex(int vid) {
		Vertex* new_vertex = new Vertex(vid);
		vertices_list.push_back(new_vertex);
		return true;
	}
	// 네트워크 연결
	bool insertEdge(int vid1, int vid2) {
		Vertex* src = find_vertex(vid1);
		Vertex* dst = find_vertex(vid2);
		Edge* new_edge = new Edge(src, dst);
		edges_list.push_back(new_edge);
		src->incident_edges.push_back(new_edge);
		dst->incident_edges.push_back(new_edge);
		return true;
	}
	// BFS를 통해 startNum 컴퓨터와 연결된 요소들의 수 리턴
	int startBFS(int startNum) {
		BFS(find_vertex(startNum));
		return virusComputer.size();
	}
	// 본격적인 BFS 시작
	void BFS(Vertex* v) {
		// 바이러스 시작 컴퓨터는 카운트해주지 않기 때문에
		// virusComputer 벡터에 넣어주지 않는다
		queue<Vertex*> L;
		v->status = Status::VISITED;
		L.push(v);
		while (!L.empty()) {
			Vertex* vertex = L.front(); L.pop();
			for (Edge* e : vertex->incident_edges) {
				Vertex* w = opposit(e, vertex);
				if (w->status == Status::UNEXPLORED) {
					w->status = Status::VISITED;
					e->status = Status::DISCOVERY;
					L.push(w);
					virusComputer.push_back(w);
				}
				else {
					e->status = Status::CROSS;
				}
			}
		}

	}
};

int main() {
	int N; cin >> N; // 컴퓨터 수
	int M; cin >> M; // 연결된 컴퓨터 쌍의 수
	Graph G;
	// 컴퓨터 1~N번까지 설치
	for (int i = 1; i <= N; ++i) {
		G.insertVertex(i);
	}
	// 컴퓨터 네트워크 연결
	while (M--) {
		int vid1, vid2;
		cin >> vid1 >> vid2;

		G.insertEdge(vid1, vid2);
	}
	// BFS 수행을 통해
	// 1번 컴퓨터의 Connectied Component 구하기
	cout << G.startBFS(1);
}