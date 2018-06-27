#include <bits/stdc++.h>

using namespace std;
struct edge {
    int s;
    int t;
    int w;
};
edge E[100100];
int dis[100100];
int inf = 1000000000;
int main() {
    int n, m;
    cin >> n >> m;
    int si, ti, wi;
    for (int i = 0; i < m; i++) {
        cin >> si >> ti >> wi;
        E[i] = {si, ti, wi};
    }
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dis[E[j].s] + E[j].w < dis[E[j].t])
                dis[E[j].t] = dis[E[j].s] + E[j].w;
        }
    }
    for (int i = 0; i < m; i++) {
        if (dis[E[i].t] > dis[E[i].s] + E[i].w) {
            cout << "negative cycle\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
    cout << '\n';
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

3 3
1 2 -1
2 3 5
3 1 -6
*/
