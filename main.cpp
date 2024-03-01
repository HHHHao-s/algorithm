#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int N = 1e5 + 5;

std::vector<int> dp[N];
std::pair<int, char> fa[N];
int tree[N][26];
int sum[N], cnt;

void insert(const std::string &s) {
    int cur = 0;
    for(char c : s) {
        if(!tree[cur][c - 'a']) {
            tree[cur][c - 'a'] = ++cnt;
            fa[cnt] = std::make_pair(cur, c);
        }

        cur = tree[cur][c - 'a'];
        sum[cur] += 1;
    }
}

void dfs(int cur) {
    bool has_son = false;
    for(int i = 0; i < 26 && dp[cur].size() < 3; i++) {
        if(tree[cur][i]) {
            dfs(tree[cur][i]);
            for(int it : dp[tree[cur][i]]) {
                if(dp[cur].size() < 3) {
                    dp[cur].emplace_back(it);
                }
            }
            has_son = true;
        }
    }

    if(!has_son) {
        for(int i = 0; i < std::min(3, sum[cur]); i++) {
            dp[cur].emplace_back(cur);
        }
    }
}

std::string get_string(int tail, int cur) {
    std::string result;
    while(tail != cur) {
        auto [f, c] = fa[tail];
        result += c;
        tail = f;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<std::vector<std::string>> solve(std::vector<std::string> vec, std::string word) {
    for(const std::string &s : vec) {
        insert(s);
    }

    dfs(0);

    std::vector<std::vector<std::string>> result;

    int cur = 0;
    std::string prefix;
    for(char c : word) {
        prefix += c;
        cur = tree[cur][c - 'a'];
        std::vector<std::string> sv;
        for(int tail : dp[cur]) {
            sv.emplace_back(prefix + get_string(tail, cur));
        }
        result.emplace_back(sv);
    }

    return result;
}

int main() {
    auto result = solve({"money", "monday", "monkey", "mother", "map", "monkeys", "mobile", "monetary"}, "money");

    for(auto vec : result) {
        for(auto s : vec) {
            std::cout << s << " ";
        }
        std::cout << "\n";
    }

    return 0;
}