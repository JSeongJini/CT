#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int PopOptimalNumber(vector<int>& deck, const int other) {
    auto itr = deck.begin();

    while (itr != deck.end() && *itr <= other) {
        itr++;
    }
    
    if (itr == deck.end()) {
        itr = deck.begin();
    }
    
    int num = *itr;
    deck.erase(itr);
    return num;
}


int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int N = A.size();
    int j = 0;

    for (int i = 0; i < N; i++) {
        if (B[j] > A[i]) {
            answer++;
            j++;

            //j���� ���� B.erase(B.begin()) �ߴٰ� ȿ���� �׽�Ʈ ��� ���ߴ�....����
        }
    }

    return answer;
}

int main() {
    vector<int> A = { 5, 1, 3, 7 };
    vector<int> B = { 2, 2, 6, 8 };

    cout << solution(A, B);
}