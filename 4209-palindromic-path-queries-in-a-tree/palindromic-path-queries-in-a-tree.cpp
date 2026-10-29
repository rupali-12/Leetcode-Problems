
class Solution {
public:
    // Fenwick Tree supporting XOR updates and prefix XOR queries
    class Fenwick {
    public:
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 2, 0);
        }

        void update(int idx, int val) {
            for (; idx <= n; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        }

        int query(int idx) {
            int result = 0;

            for (; idx > 0; idx -= idx & -idx) {
                result ^= bit[idx];
            }

            return result;
        }

        // XOR val into every position in [l, r]
        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }
    };

    vector<vector<int>> adj;
    vector<vector<int>> up;

    vector<int> depth, tin, tout, prefixMask;
    int timer = 0;
    int LOG;

    Fenwick* fw = nullptr;

    int getMask(char ch) {
        return 1 << (ch - 'a');
    }

    // Iterative DFS: avoids stack overflow on a chain-shaped tree
    void buildTree(int n, string& s) {
        timer = 0;

        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        prefixMask.assign(n, 0);

        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        up.assign(LOG, vector<int>(n, 0));

        // {node, parent, exiting}
        stack<tuple<int, int, bool>> st;
        st.push({0, 0, false});

        while (!st.empty()) {
            auto [u, parent, exiting] = st.top();
            st.pop();

            if (exiting) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;

            up[0][u] = parent;

            if (u == 0) {
                depth[u] = 0;
                prefixMask[u] = getMask(s[u]);
            } else {
                depth[u] = depth[parent] + 1;
                prefixMask[u] =
                    prefixMask[parent] ^ getMask(s[u]);
            }

            // Process the exit only after all descendants
            st.push({u, parent, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];

                if (v == parent) continue;

                st.push({v, u, false});
            }
        }

        // Binary lifting table
        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        // Bring u to the same depth as v
        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k)) {
                u = up[k][u];
            }
        }

        if (u == v) return u;

        // Lift both nodes until their parents are equal
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        // Reset all data for this invocation
        adj.assign(n, {});
        timer = 0;

        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Precompute Euler Tour and LCA information
        buildTree(n, s);

        // Initialize Fenwick Tree
        Fenwick fenwick(n + 1);
        fw = &fenwick;

        // Initially, each node stores its root-to-node prefix mask.
        // A point XOR update initializes that position.
        for (int u = 0; u < n; u++) {
            fw->rangeUpdate(tin[u], tin[u],
                            prefixMask[u]);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);

            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char ch;

                ss >> u >> ch;

                int oldMask = getMask(s[u]);
                int newMask = getMask(ch);

                int delta = oldMask ^ newMask;

                if (delta != 0) {
                    // Updating u changes the prefix mask
                    // of u and every descendant of u.
                    fw->rangeUpdate(
                        tin[u],
                        tout[u],
                        delta
                    );
                }

                s[u] = ch;
            } else {
                int u, v;
                ss >> u >> v;

                int w = LCA(u, v);

                // Current root-to-node prefix masks
                int maskU = fw->query(tin[u]);
                int maskV = fw->query(tin[v]);

                // Include the LCA character exactly once
                int pathMask =
                    maskU ^ maskV ^ getMask(s[w]);

                // At most one odd-frequency character
                bool possible =
                    (pathMask & (pathMask - 1)) == 0;

                ans.push_back(possible);
            }
        }

        return ans;
    }
};
