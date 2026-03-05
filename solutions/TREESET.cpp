/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <iostream>
#include <vector>

using namespace std;

long long MOD = 998244353;
vector<vector<int>> adj;
long long dp[100005][2];

void dfs(int u, int p) {
    dp[u][0] = 1; // u is NOT in the set
    dp[u][1] = 1; // u IS in the set
    
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        
        // If u is NOT in the set, v can be either in or out
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
        
        // If u IS in the set, v MUST NOT be in the set
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    for (int i = 0; i <= N; i++) {
        adj.assign(N + 1, vector<int>());
        dp[i][0] = dp[i][1] = 0;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    // Total = (Sets excluding root + Sets including root)
    long long ans = (dp[1][0] + dp[1][1]) % MOD;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}