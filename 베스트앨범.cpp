#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    struct cmp1 {
        bool operator()(const pair<string, int>& lhs, const pair<string, int>& rhs) {
            return lhs.second < rhs.second ;
        };
    };
    struct cmp2 {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return (lhs.second == rhs.second) ? (lhs.first > rhs.first) : (lhs.second < rhs.second);
        };
    };

    map<string, int> genreWithPlayed;
    map<string, vector<pair<int, int>>> genreWithSong;

    int len = genres.size();
    for (int i = 0; i < len; i++) {
        if (genreWithPlayed.find(genres[i]) == genreWithPlayed.end()) {
            genreWithPlayed.insert({ genres[i], plays[i] });
            genreWithSong.insert({ genres[i], {{i, plays[i]}} });
        }
        else {
            genreWithPlayed[genres[i]] += plays[i];
            genreWithSong[genres[i]].push_back({ i, plays[i] });
        }
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp1> genreHeap(genreWithPlayed.begin(), genreWithPlayed.end());

    while (!genreHeap.empty()) {
        string topGenre = genreHeap.top().first;

        int songs = (genreWithSong[topGenre].size() >= 2) ? 2 : 1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> songHeap(genreWithSong[topGenre].begin(), genreWithSong[topGenre].end());

        for (int i = 0; i < songs; i++) {
            int song = songHeap.top().first;
            answer.push_back(song);
            songHeap.pop();
        }

        genreHeap.pop();
    }

    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 2500, 150, 800, 2500 };


    vector<int> answer = solution(genres, plays);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

}