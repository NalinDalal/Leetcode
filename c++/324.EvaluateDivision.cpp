/*399. Evaluate Division
You are given an array of variable pairs equations and an array of real numbers
values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai /
Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth
query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined,
return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will
not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so
the answer cannot be determined for them.



Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]] Output:
[6.00000,0.50000,-1.00000,1.00000,-1.00000] Explanation: Given: a / b = 2.0, b /
c = 3.0 queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]] Output:
[3.75000,0.40000,5.00000,0.20000] Example 3:

Input: equations = [["a","b"]], values = [0.5], queries =
[["a","b"],["b","a"],["a","c"],["x","y"]] Output:
[0.50000,2.00000,-1.00000,-1.00000]


Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.

It is a Graph Problem
*/
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  unordered_map<string, vector<pair<string, double>>> graph;

  void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
    for (int i = 0; i < equations.size(); i++) {
      string A = equations[i][0], B = equations[i][1];
      double val = values[i];

      graph[A].push_back({B, val});
      graph[B].push_back({A, 1.0 / val});
    }
  }

  double dfs(string src, string dest, unordered_set<string>& visited) {
    if (graph.find(src) == graph.end() || graph.find(dest) == graph.end())
      return -1.0; // If either variable does not exist

    if (src == dest)
      return 1.0; // Same variable, result is 1.0

    visited.insert(src);

    for (auto& neighbor : graph[src]) {
      string next = neighbor.first;
      double weight = neighbor.second;
      if (!visited.count(next)) {
        double res = dfs(next, dest, visited);
        if (res != -1.0)
          return res * weight;
      }
    }
    return -1.0;
  }

  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    // hmmm map equations[i] to values[i]
    // where values[i]=equations[i][0]/equations[i][1]
    // returna vector whose i eleemnt is ans of queries[i][0]/queries[i][1]
    // if division not possible return -1
    buildGraph(equations, values);
    vector<double> ans;
    for (auto& q : queries) {
      unordered_set<string> visited;
      ans.push_back(dfs(q[0], q[1], visited));
    }
    return ans;
  }
  /*
double divide(int a, int b) {
  if (b == 0)
    return -1.00000;
  // say the divisor is not defined i.e. b is not defined
  return (double)a / b;
}*/
};

// sub:
// https://leetcode.com/problems/evaluate-division/submissions/1586268097/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/evaluate-division/solutions/6579905/399-evaluate-division-by-nalindalal2004-etf2/
