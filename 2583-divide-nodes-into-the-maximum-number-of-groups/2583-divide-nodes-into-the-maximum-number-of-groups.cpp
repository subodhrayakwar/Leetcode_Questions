class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); 
        for (auto& e : edges) {
            graph[e[0]-1].push_back(e[1]-1); 
            graph[e[1]-1].push_back(e[0]-1); 
        }
        
        vector<int> seen(n); 
        vector<vector<int>> group; 
        for (int i = 0; i < n; ++i) 
            if (!seen[i]) {
                seen[i] = 1; 
                stack<int> stk; stk.push(i); 
                group.push_back({i}); 
                while (stk.size()) {
                    auto u = stk.top(); stk.pop(); 
                    for (auto& v : graph[u]) 
                        if (!seen[v]) {
                            seen[v] = seen[u] + 1; 
                            stk.push(v); 
                            group.back().push_back(v); 
                        } else if ((seen[u] & 1) == (seen[v] & 1)) return -1; 
                }
            }
        
        auto bfs = [&](int x) {
            int ans = 0; 
            vector<bool> seen(n); 
            seen[x] = true; 
            queue<int> q; q.push(x); 
            for (; q.size(); ++ans) 
                for (int sz = q.size(); sz; --sz) {
                    auto u = q.front(); q.pop(); 
                    for (auto& v : graph[u]) 
                        if (!seen[v]) {
                            seen[v] = true; 
                            q.push(v); 
                        }
                }
            return ans; 
        }; 
        
        int ans = 0; 
        for (auto& g : group) {
            transform(g.begin(), g.end(), g.begin(), bfs); 
            ans += *max_element(g.begin(), g.end()); 
        }
        return ans; 
    }
};