/*
프로그래머스 
LV3. 금과 은 운반하기
*/


#include <string>
#include <vector>
#include <limits.h>
#include <math.h>
#include <iostream>

using namespace std;


long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 0;

    int cities = g.size();

    long long low = 0;
    //10e9 * 2 * 10e5 * 2 * 1
    long long high = 400000000000000;

    long long totalGold, totalSilver, totalTransfer;


    while (low <= high) {
        long long mid = (low + high) / 2;
        totalGold = totalSilver = totalTransfer = 0;

        for (int i = 0; i < cities; i++) {
            long long times = 0;
            if (mid >= t[i]) {
                times = 1;
                times += (mid - t[i]) / (long long)(t[i] * 2);
            }

            long long gold = (w[i] * times <= g[i]) ? (w[i] * times) : g[i];
            long long silver = (w[i] * times <= s[i]) ? (w[i] * times) : s[i];
            long long transfer = (silver + gold >= w[i] * times) ? w[i] * times : silver + gold;

            totalGold += gold;
            totalSilver += silver;
            totalTransfer += transfer;
        }

        if (totalGold >= a && totalSilver >= b && totalTransfer >= (a + b)) {
            high = mid - 1;
            answer = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> g = { 50, 20, 100 };
    vector<int> s = { 0, 200, 10 };
    vector<int> w = { 30, 50, 10 };
    vector<int> t = { 3, 6, 9 };

    cout << solution(100, 200, g, s, w, t) << endl;


}