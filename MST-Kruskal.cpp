#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct edge {
    int u;
    int v;
    ll w;
};
edge E[100100];
bool mys(edge x, edge y) {
    return x.w < y.w;
}
int p[10100];
int sz[10100];
int root(int x) {
    if (x == p[x]) return x;
    return p[x] = root(p[x]);
}
bool con(int x, int y) {
    x = root(x), y = root(y);
    if (x == y) return false;
    if (sz[x] >= sz[y]) {
        sz[x] += sz[y];
        sz[y] = 0;
        p[y] = x;
    }
    else {
        sz[y] += sz[x];
        sz[x] = 0;
        p[x] = y;
    }
    return true;
}
int main() {
    int n, m; int ui, vi; ll wi;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ui >> vi >> wi;
        E[i] = {ui, vi, wi};
    }
    sort(E, E + m, mys);
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ui = E[i].u, vi = E[i].v, wi = E[i].w;
        if (!con(ui, vi)) continue;
        //cout << "here\n";
        ans += wi;
    }
    cout << ans << '\n';
    return 0;
}
