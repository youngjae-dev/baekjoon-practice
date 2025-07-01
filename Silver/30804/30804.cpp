#include<iostream>
using namespace std;

// 현재 탕후루에 꽂혀 있는 과일 종류의 개수를 반환
int fruitType(int fruits[10]) {
	int count = 0;
	for (int i = 1; i < 10; ++i) {
		if (fruits[i] != 0) ++count;
	}
	return count;
}

int main() {
	int N; cin >> N; // 전체 과일 개수 입력

	int left = 0; // 앞에서 과일을 제거할 포인터
	int right = 0; // 뒤에서 과일을 추가할 포인터
	int fruits[10] = { 0, }; // 과일 종류별 개수 저장 (1~9번 과일만 사용)

	// 과일이 꽂힐 순서를 저장할 배열
	int* arr = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> arr[i]; // 과일 종류 입력
	}

	int result = 0; // 만들 수 있는 최대 탕후루 길이 저장

	while (right < N) {
		fruits[arr[right]]++; // 새로운 과일을 탕후루에 추가
		right++;

		// 과일 종류가 3개 이상이면 앞에서부터 제거해 2종류 이하로 유지
		while(fruitType(fruits) > 2) {
			fruits[arr[left]]--;
			left++;
		}

		// 현재 구간이 최장이라면 결과 갱신
		result = max(result, right - left);
	}

	cout << result;
}