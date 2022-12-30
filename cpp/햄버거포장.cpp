#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    stack<int> s;
    int first, second, third, fourth;
    first = second = third = fourth = 0;

    for (int i = 0; i < ingredient.size(); i++) {
        first = second;             
        second = third;             
        third = fourth;             
        fourth = ingredient[i];     

        s.push(fourth);

        if (first == 1 && second == 2 && third == 3 && fourth == 1) {
            answer++;

            for (int j = 0; j < 4; j++) s.pop();

            if (!s.empty()) {
                fourth = s.top(); s.pop();
            }
            else fourth = 0;

            if (!s.empty()) {
                third = s.top(); s.pop();
            }
            else third = 0;

            if (!s.empty()) {
                second = s.top(); s.pop();
            }
            else second = 0;

            if (second != 0) s.push(second);
            if (third != 0) s.push(third);
            if (fourth != 0) s.push(fourth);
        }
    }
    

    return answer;
}

int main() {
    vector<int> ingredient = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
    cout << solution(ingredient);
}