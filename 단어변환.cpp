#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool IsDifferentOnlyOneAlpabat(const string lhs, const string rhs) {
    int len = lhs.length();
    int diff = 0;

    for (int i = 0; i < len; i++) {
        if (lhs[i] != rhs[i]) diff++;
    }

    return (diff == 1);
}

/// <summary>
/// DFS를 활용하여 target으로 변환하기 위한 다음 단어를 찾는 함수
/// </summary>
/// <param name="begin">현재 단어</param>
/// <param name="target">목표 단어</param>
/// <param name="words">단어 목록</param>
/// <param name="path">변환 과정으로 선택된 단어 목록</param>
/// <param name="min">최소 변환 과정 길이</param>
void SearchNextWord(const string begin, const string target, const vector<string> words, const vector<string> path, int& min) {
    if (begin == target) {
        if (path.size() < min) {
            min = path.size();
        }
        return;
    }

    if (path.size() > min) return;

    for (auto itr = words.begin(); itr != words.end(); itr++) {
        if (find(path.begin(), path.end(), *itr) == path.end()) {   //path에 없는 단어인 경우
            if (IsDifferentOnlyOneAlpabat(begin, *itr)) {   
                vector<string> newPath(path);
                newPath.push_back(*itr);
                SearchNextWord(*itr, target, words, newPath, min);
            }
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    else {
        int min = 50;
        SearchNextWord(begin, target, words, { begin }, min);

        return min - 1; //min은 시작와 목표 단어를 포함한 변환 과정의 길이이므로, -1을 해주어야 한다.
    }
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log" };
    
    cout << solution(begin, target, words);
}