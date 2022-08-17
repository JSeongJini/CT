#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        int quotient = n / a;

        int newCoke = quotient * b;
        answer += newCoke;

        n = (n - (a * quotient) + newCoke);
    }

    return answer;
}

int main() {
    cout << solution(3, 1, 20);
}