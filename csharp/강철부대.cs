using System;
using System.Collections.Generic;
using System.Text;

namespace CTwithCSharp
{
    class SteelMilitary
    {
        private Queue<int> q = null;    //BFS를 위한 큐
        bool[] visited = null;          //BFS를 위한 방문 여부를 저장하는 bool 배열
        int[] distance = null;          //BFS를 위해 목적지로부터 각 지역 사이의 거리를 저장하는 int 배열
        Dictionary<int, List<int>> road = null;  //roads 배열을 출발노드 : 도착노드리스트 형태로 저장
        const int MAX = 100001;         //최대값


        public int[] solution(int n, int[,] roads, int[] sources, int destination)
        {
            //초기화
            int[] answer = new int[sources.Length];
            visited = new bool[n + 1];
            distance = new int[n + 1];
            q = new Queue<int>();
            road = new Dictionary<int, List<int>>();
            for(int i = 0; i <= n; i++)
            {
                visited[i] = false;
                distance[i] = MAX;  //최대값으로 설정
                road[i] = new List<int>();
            }

            for(int i = 0; i < roads.GetLength(0); i++)
            {
                road[roads[i, 0]].Add(roads[i, 1]);
                road[roads[i, 1]].Add(roads[i, 0]);
            }

            q.Enqueue(destination);
            distance[destination] = 0;

            while(q.Count > 0)
            {
                int cur = q.Dequeue();

                if (visited[cur])  //이미 방문한 곳이라면 스킵
                    continue;

                visited[cur] = true;

                for(int i = 0; i < road[cur].Count; i++)
                {
                    q.Enqueue(road[cur][i]);
                    if (distance[road[cur][i]] > distance[cur] + 1)
                        distance[road[cur][i]] = distance[cur] + 1;
                }
            }

            for(int i = 0; i < sources.Length; i++)
            {
                if (distance[sources[i]] != MAX)
                    answer[i] = distance[sources[i]];
                else
                    answer[i] = -1;
            }


            return answer;
        }
    }
}
