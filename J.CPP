#include <bits/stdc++.h>
#include <climits>
using namespace std;
struct point {
    int x;
    int y;
    int c;
    int t;
};
struct elem {
    int x;
    int y;
    int cost;
    int time;
};
struct od {
    bool operator()(const elem &a, const elem &b) {
        return a.cost > b.cost;
    }
};
elem make_elem(int i, int j, int c, int t) {
    elem new_e;
    new_e.x = i;
    new_e.y = j;
    new_e.cost = c;
    new_e.time = t;
    return new_e;
}
point make_point(int x, int y, int c, int t) {
    point new_p;
    new_p.x = x;
    new_p.y = y;
    new_p.c = c;
    new_p.t = t;
    return new_p;
}
vector<point> graph[100][100];
bool visited[100][100][201]; int dis[100][100][201];
priority_queue<elem,vector<elem>,od> pq;
void dijkstra(int x, int y) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 201; k++) {
                dis[i][j][k] = INT_MAX;
                visited[i][j][k] = false;
            }
        }
    }
    dis[x][y][100] = 0;
    pq.push(make_elem(x, y, dis[x][y][100], 100));
    while (!pq.empty()) {
        int c1 = pq.top().x, c2 = pq.top().y, c3 = pq.top().cost, c4 = pq.top().time;
        pq.pop();
        if (visited[c1][c2][c4]) continue;
        visited[c1][c2][c4] = true;
        for (int i = 0; i < graph[c1][c2].size(); i++) {
            int f1 = graph[c1][c2][i].x, f2 = graph[c1][c2][i].y, f3 = graph[c1][c2][i].c, f4 = graph[c1][c2][i].t;
            if (f4 + c4 < 0 || f4 + c4 > 200) continue;
            if (visited[f1][f2][f4 + c4]) continue;
            if (dis[f1][f2][f4 + c4] < dis[c1][c2][c4] + f3) continue;
            dis[f1][f2][f4 + c4] = dis[c1][c2][c4] + f3;
            pq.push(make_elem(f1, f2, dis[f1][f2][f4 + c4], f4 + c4));
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int n, m, x, y; cin >> n >> m >> x >> y; x--; y--;
        int p; cin >> p;
        int x1, x2, y1, y2, c, t;
        for (int i = 0; i < p; i++) {
            cin >> x1 >> y1 >> x2 >> y2 >> c >> t;
            graph[x1 - 1][y1 - 1].push_back(make_point(x2 - 1, y2 - 1, c, t));
        }
        dijkstra(x, y);
        int q; cin >> q;
        int a, b, w;
        cout << "Case " << tc << ":\n";
        for (int i = 0; i < q; i++) {
            cin >> a >> b >> w;
            a--; b--;
            if (dis[a][b][w + 100] == INT_MAX) cout << "No\n";
            else cout << dis[a][b][w + 100] << '\n';
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                graph[i][j].clear();
            }
        }
    }
    return 0;
}


