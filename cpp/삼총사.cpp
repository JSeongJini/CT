#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    int len = number.size();

    vector<bool> combination;
    for (int i = 0; i < 3; i++)
        combination.push_back(true);
    for (int i = 3; i < len; i++)
        combination.push_back(false);

    sort(combination.begin(), combination.end());

    do {
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (combination[i]) {
                sum += number[i];
            }
        }

        if (sum == 0) answer++;
    } while (next_permutation(combination.begin(), combination.end()));

    return answer;
}

int main(){
    vector<int> number = { -2, 3, 0, 2, -5 };
    cout << solution(number) << endl;
}