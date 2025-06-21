class Solution {
    public boolean dfs(int[][] graph, boolean vis[], int curr, boolean isSafe[]) {
        vis[curr] = true;
        for (int i : graph[curr]) {
            if (!vis[i]) {
                if (!dfs(graph, vis, i, isSafe)) {
                    isSafe[curr] = false;
                    return false;
                }
            } else {
                if (!isSafe[i]) return false;
            }
        }
        isSafe[curr] = true;
        return true;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        boolean[] vis = new boolean[n];
        boolean[] isSafe = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            if (graph[i].length == 0) isSafe[i] = true;
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(graph, vis, i, isSafe);
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) ans.add(i);
        }
        return ans;
    }
}