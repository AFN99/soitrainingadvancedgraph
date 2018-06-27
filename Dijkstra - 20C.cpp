#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
ll inf = 10000000000000LL;
vector <pil> adj[100100];
priority_queue <pli, vector<pli>, greater<pli> > pq;
ll dis[100100];
bool vis[100100];
int p[100100];
vector <int> ans;
int main() {
    int n, m;
    int ui, vi;
    ll wi;
    cin >> n >> m;
    while (m--) {
        cin >> ui >> vi >> wi;
        adj[ui].push_back({vi, wi});
        adj[vi].push_back({ui, wi});
    }
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[1] = 0;
    pq.push({0, 1});
    p[1] = -1;
    int to; ll d;
    while (!pq.empty()) {
        ui = pq.top().S;
        pq.pop();
        if (vis[ui]) continue;
        vis[ui] = true;
        for (auto v : adj[ui]) {
            to = v.F, d = v.S;
            if (dis[to] > dis[ui] + d) {
                dis[to] = dis[ui] + d;
                pq.push({dis[to], to});
                p[to] = ui;
            }
        }
    }
	if (dis[n] == inf) {
		cout << "-1\n";
		return 0;
	}	
    for (int i = n;; i = p[i]) {
        ans.push_back(i);
        if (p[i] == -1) break;
    }
    cout << ans[ans.size() - 1];
    for (int i = ans.size() - 2; i >= 0; i--) cout << ' ' << ans[i];
    cout << '\n';
    return 0;
}
