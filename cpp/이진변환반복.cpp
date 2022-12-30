#include <iostream>

#include <string>
#include <vector>

using namespace std;

string RemoveZero(string s) {
    string result = "";

    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') {
            result += '1';
        }
    }

    return result;
}

string ToBinary(int n) {
    string result = "";

    while (n > 1) {
        int remainder = n % 2;
        result = to_string(remainder) + result;
        n /= 2;
    }
    result = to_string(n) + result;

    return result;
}




vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);


    while (s != "1") {
        int len = s.length();

        string converted = RemoveZero(s);
        int convertedLen = converted.length();

        answer[1] += len - convertedLen;
        s = ToBinary(convertedLen);
        answer[0]++;
    }

    return answer;
}

int main() {
    string  s = "110010101001";
    solution(s);
}