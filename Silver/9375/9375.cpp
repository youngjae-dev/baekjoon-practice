#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;

		// 카테고리별 의상 개수 저장
		unordered_map<string, int> clothes_count;

		// 카테고리 순회를 위한 list (map은 순서가 없기 때문에 따로 저장)
		vector<string> categories;

		while (N--) {
			string cloth, category;
			cin >> cloth >> category;


			// 카테고리가 처음 등장했을 경우, map에 초기화하고, 목록에 추가
			if (clothes_count.find(category) == clothes_count.end()) {
				clothes_count.insert({ category,0 });
				categories.push_back(category);
			}


			// 해당 카테고리에 속하는 의상 수 증가
			++clothes_count[category];
		}

		// 각 카테고리에서 (입는 경우 + 안 입는 경우)를 곱해서 전체 조합 계산 가능
		// 입는 경우는 각 카테고리에 해당하는 의상 수와 같다
		// 따라서, 카테고리에 해당하는 의상 수 + 1 만큼 더해주기
		int result = 1;
		for (string s : categories) {
			result *= (clothes_count[s] + 1);
		}

		// 전부 입지 않은 경우는 제외
		--result;
		cout << result << '\n';
	}
}