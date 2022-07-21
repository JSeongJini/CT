/*
	프로그래머스 코딩테스트 연습
	Lv.3 N으로 표현
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long NNN(int _n, int _digits) {
	int result = _n;
	for (int i = 1; i < _digits; i++) {
		result = (result * 10) + _n;
	}
	
	return result;
}


int solution(int _N, int _number) {
	vector<vector<long long>> result = { {0} };
	result.push_back({ _N });

	if (_N == _number) return 1;

	int answer = 2;
	while (answer <= 8) {
		vector<long long> midResult;
		midResult.push_back(NNN(_N, answer));

		int lhs = 1;
		int rhs = answer - lhs;

		while (lhs <= rhs) {
			for (int i = 0; i < result[lhs].size(); i++) {
				for (int j = 0; j < result[rhs].size(); j++) {
					long long calc = result[lhs][i] + result[rhs][j];
					if (calc == _number) return answer;
					else midResult.push_back(calc);

					calc = result[lhs][i] - result[rhs][j];
					if (calc == _number) return answer;
					else midResult.push_back(calc);

					calc = result[rhs][j] - result[lhs][i];
					if (calc == _number) return answer;
					else midResult.push_back(calc);

					calc = result[lhs][i] * result[rhs][j];
					if (calc == _number) return answer;
					else midResult.push_back(calc);

					if (result[rhs][j] != 0) {
						calc = result[lhs][i] / result[rhs][j];
						if (calc == _number) return answer;
						else midResult.push_back(calc);
					}

					if (result[lhs][i] != 0) {
						calc = result[rhs][j] / result[lhs][i];
						if (calc == _number) return answer;
						else midResult.push_back(calc);
					}
				}
			}

			lhs++;
			rhs--;
		}

		sort(midResult.begin(), midResult.end());
		//중복된 값 제거
		midResult.erase(unique(midResult.begin(), midResult.end()), midResult.end());

		result.push_back(midResult);
		answer++;
	}

	return -1;
}

int main() {
	cout << solution(5, 12);
}