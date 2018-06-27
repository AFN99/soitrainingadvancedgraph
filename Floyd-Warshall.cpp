#include <bits/stdc++.h>

using namespace std;
int dis[1010][1010];
int inf = 1000000000;
int main() {
    int n, m;
    cin >> n >> m;
    int ui, vi, wi;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dis[i][j] = inf;
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> ui >> vi >> wi;
        dis[ui][vi] = wi;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] == inf || dis[k][j] == inf) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i][i] < 0) {
            cout << "negative cycle\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == inf) cout << "n ";
            else cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
/*
5 8
1 2 -1
1 3 4
2 3 3
4 3 5
5 4 -3
2 5 2
4 2 1
2 4 2

*/
