#include <bits/stdc++.h>
using namespace std;

// ================= DFS Implementation =================
unordered_map<string, vector<pair<string, double>>> graphDFS;

bool dfs(string src, string dst, unordered_set<string> &visited, double &result, double product) {
    if (src == dst) {
        result = product;
        return true;
    }
    visited.insert(src);
    for (size_t i = 0; i < graphDFS[src].size(); i++) {
        string next = graphDFS[src][i].first;
        double weight = graphDFS[src][i].second;
        if (!visited.count(next)) {
            if (dfs(next, dst, visited, result, product * weight)) {
                return true;
            }
        }
    }
    return false;
}

vector<double> calcEquationDFS(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
    graphDFS.clear();
    for (size_t i = 0; i < equations.size(); i++) {
        string a = equations[i][0], b = equations[i][1];
        double val = values[i];
        graphDFS[a].push_back(make_pair(b, val));
        graphDFS[b].push_back(make_pair(a, 1.0 / val));
    }

    vector<double> res;
    for (size_t i = 0; i < queries.size(); i++) {
        string src = queries[i][0], dst = queries[i][1];
        if (!graphDFS.count(src) || !graphDFS.count(dst)) {
            res.push_back(-1.0);
            continue;
        }
        unordered_set<string> visited;
        double ans = -1.0;
        dfs(src, dst, visited, ans, 1.0);
        res.push_back(ans);
    }
    return res;
}

// ================= BFS Implementation =================
unordered_map<string, vector<pair<string, double>>> graphBFS;

double bfs(string src, string dst) {
    if (!graphBFS.count(src) || !graphBFS.count(dst)) return -1.0;
    if (src == dst) return 1.0;

    queue<pair<string, double>> q;
    unordered_set<string> visited;
    q.push(make_pair(src, 1.0));
    visited.insert(src);

    while (!q.empty()) {
        pair<string, double> curr = q.front();
        q.pop();

        string node = curr.first;
        double product = curr.second;

        if (node == dst) return product;

        for (size_t i = 0; i < graphBFS[node].size(); i++) {
            string next = graphBFS[node][i].first;
            double weight = graphBFS[node][i].second;
            if (!visited.count(next)) {
                visited.insert(next);
                q.push(make_pair(next, product * weight));
            }
        }
    }
    return -1.0;
}

vector<double> calcEquationBFS(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
    graphBFS.clear();
    for (size_t i = 0; i < equations.size(); i++) {
        string a = equations[i][0], b = equations[i][1];
        double val = values[i];
        graphBFS[a].push_back(make_pair(b, val));
        graphBFS[b].push_back(make_pair(a, 1.0 / val));
    }

    vector<double> res;
    for (size_t i = 0; i < queries.size(); i++) {
        res.push_back(bfs(queries[i][0], queries[i][1]));
    }
    return res;
}

// ================= Union-Find Implementation =================
unordered_map<string, string> parentUF;
unordered_map<string, double> weightUF;

pair<string, double> findParent(string x) {
    if (parentUF.find(x) == parentUF.end()) {
        parentUF[x] = x;
        weightUF[x] = 1.0;
    }
    if (parentUF[x] == x) return make_pair(x, 1.0);

    pair<string, double> p = findParent(parentUF[x]);
    parentUF[x] = p.first;
    weightUF[x] *= p.second; // update ratio to root
    return make_pair(parentUF[x], weightUF[x]);
}

void unionNodes(string a, string b, double val) {
    pair<string, double> pa = findParent(a);
    pair<string, double> pb = findParent(b);

    string rootA = pa.first;
    string rootB = pb.first;
    double weightA = pa.second;
    double weightB = pb.second;

    if (rootA != rootB) {
        parentUF[rootA] = rootB;
        weightUF[rootA] = (val * weightB) / weightA;
    }
}

vector<double> calcEquationUF(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
    parentUF.clear();
    weightUF.clear();

    for (size_t i = 0; i < equations.size(); i++) {
        unionNodes(equations[i][0], equations[i][1], values[i]);
    }

    vector<double> res;
    for (size_t i = 0; i < queries.size(); i++) {
        string a = queries[i][0], b = queries[i][1];
        if (parentUF.find(a) == parentUF.end() || parentUF.find(b) == parentUF.end()) {
            res.push_back(-1.0);
            continue;
        }

        pair<string, double> pa = findParent(a);
        pair<string, double> pb = findParent(b);

        if (pa.first != pb.first) {
            res.push_back(-1.0);
        } else {
            res.push_back(pa.second / pb.second);
        }
    }
    return res;
}

// ================= MAIN =================
int main() {
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    cout << "DFS: ";
    vector<double> resultDFS = calcEquationDFS(equations, values, queries);
    for (size_t i = 0; i < resultDFS.size(); i++) cout << resultDFS[i] << " ";
    cout << endl;

    cout << "BFS: ";
    vector<double> resultBFS = calcEquationBFS(equations, values, queries);
    for (size_t i = 0; i < resultBFS.size(); i++) cout << resultBFS[i] << " ";
    cout << endl;

    cout << "Union-Find: ";
    vector<double> resultUF = calcEquationUF(equations, values, queries);
    for (size_t i = 0; i < resultUF.size(); i++) cout << resultUF[i] << " ";
    cout << endl;

    return 0;
}
