#include <iostream>
#include <string>

using namespace std;
int solution(string s)
{
    int len = s.length();
    int answer = len;

    for (int i = len; i > 0; i--) {
        if (i % 2 == 1) {
            for (int center = i / 2; center < (len - (i / 2)); center++) {
                int left = center - 1;
                int right = center + 1;

                bool isPalindrome = true;
                for(int j = 0; j < i /2; j++){
                    if (s[left - j] != s[right + j]) {
                        isPalindrome = false;
                        break;
                    }
                }

                if (isPalindrome) {
                    return i;
                }
            }
        }
        else {
            for (int center = i / 2; center <= (len - (i / 2)); center++) {
                bool isPalindrome = true;
                if (s[center] != s[center - 1]) {
                    isPalindrome = false;
                    continue;
                }

                int left = center - 2;
                int right = center + 1;
                
                for (int j = 0; j < ((i / 2) - 1); j++) {
                    if (s[left - j] != s[right + j]) {
                        isPalindrome = false;
                        break;
                    }
                }

                if (isPalindrome) {
                    return i;
                }
            }
        }

    }
}

int main() {
    cout << solution("abb");
}