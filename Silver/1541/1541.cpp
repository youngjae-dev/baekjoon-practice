#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

// 문자열을 delimiter 기준으로 분할 후 벡터에 저장
vector<string> split(string str, char delimiter) {
	vector<string> result;
	stringstream input(str); // 문자열 스트림으로 변환
	string tmp;

	// delimiter를 기준으로 문자열을 잘라 tmp에 저장 후 result에 추가
	while (getline(input, tmp, delimiter)) {
		result.push_back(tmp);
	}
	return result;
}

int main() {
	string str;
	cin >> str;

	// '-' 기준으로 식을 나누어 각 덩어리 저장
	vector<string> expression = split(str, '-');

	int result = 0;

	// 각 덩어리를 '+' 기준으로 다시 나누고 합산
	for (int i = 0; i < expression.size(); ++i) {
		vector<string> tmp = split(expression[i], '+');
		int sum = 0;
		for (int j = 0; j < tmp.size(); ++j) {
			sum += stoi(tmp[j]);
		}
		// 첫 덩어리는 더하고 나머지는 빼기
		if (i == 0) result += sum;
		else result -= sum;
	}
	cout << result;
}