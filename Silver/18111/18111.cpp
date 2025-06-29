#include<iostream>
#include<vector>
using namespace std;

// 주어진 높이 기준으로 블록들 모두 제거하기
// 모두 제거하는데 걸리는 시간 리턴
// 벡터는 실제 field에 영향 끼치면 안되므로 const로 선언
// 블록 개수 B는 실제 B에 영향을 끼쳐야 하므로 참조로 선언
int removeBlock(int standard, const vector<vector<int>>& v, int& B) {
	int time = 0;

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[0].size(); ++j) {

			// 현재 높이가 기준보다 높을 경우 -> 블록 제거
			if (v[i][j] > standard) {

				B = B + (v[i][j] - standard); // 제거한 블록 인벤토리에 추가

				time = time + (v[i][j] - standard) * 2; // 블록을 한 칸 제거할 때마다 2초 소요
			}
		}
	}
	return time;
}

// 주어진 높이 기준으로 블록들 모두 추가하기
// 모두 추가하는데 걸리는 시간 리턴
int buildBlock(int standard, const vector<vector<int>>& v, int& B) {
	int time = 0;

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[0].size(); ++j) {

			// 현재 높이가 기준보다 낮을 경우 -> 블록 추가
			if (v[i][j] < standard) {

				B = B - (standard - v[i][j]); // 저장된 인벤토리에서 블록 꺼내쓰기

				time = time + (standard - v[i][j]); // 블록을 한 칸 쌓을 때마다 1초 소요
			}
		}
	}
	return time;
}

int main() {
	int N, M, B; // N : 가로 길이 | M : 세로 길이 | B : 가지고 있는 블록의 개수
	cin >> N >> M >> B;

	// field : 집을 만들고자 하는 공간(N x M)
	vector<vector<int>> field(N, vector<int>(M, 0));
	
	int time = 0; // 걸리는 시간
	int height = 0; // 높이

	int min_height = 0; // 주어진 입력 중 최소 높이
	int max_height = 0; // 주어진 입력중 최대 높이

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> field[i][j];
			
			// 최소 높이와 최대 높이 초기화
			if (i == 0 && j == 0) {
				min_height = field[i][j];
				max_height = field[i][j];
			}

			if (min_height > field[i][j])min_height = field[i][j]; // 최소 높이 최신화

			if (max_height < field[i][j])max_height = field[i][j]; // 최대 높이 최신화
		}
	}
	
	for (int i = min_height; i <= max_height; ++i) {
		int standard = i; // 기준 높이(최소 높이부터 최대 높이까지 한칸씩 추가)
		int tmp_time = 0; // 기존에 저장해놨던 최소 시간과 비교하기 위한 변수
		int tmp_B = B; // 실제 인벤토리에 영향을 주지 않기 위해 tmp_B에 복사

		// 기준 높이를 목표로 블록들을 제거 & 추가
		tmp_time += removeBlock(standard, field, tmp_B);
		tmp_time += buildBlock(standard, field, tmp_B);

		// 만일 가지고 있는 블록 개수보다 더 썼을 경우 조건 성립 X
		if (tmp_B < 0) continue;

		// time과 height 변수 초기화
		if (i == min_height) {
			time = tmp_time;
			height = standard;
		}

		// 기존 시간보다 더 적게 걸린 경우 시간과 높이 최신화
		if (time > tmp_time) {
			time = tmp_time;
			height = standard;
		}

		// 기존 시간과 같게 나왔지만, 높이가 더 클 경우 높이 최신화
		else if (time == tmp_time && height < standard) {
			time = tmp_time;
			height = standard;
		}
	}
	
	cout << time << ' ' << height;
}