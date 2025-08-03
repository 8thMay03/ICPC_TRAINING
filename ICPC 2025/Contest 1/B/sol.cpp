#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int ALPHABET = 26;

struct TrieNode {
    TrieNode* child[ALPHABET];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < ALPHABET; ++i) child[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int N = S.length();
    int K;
    cin >> K;
    Trie trie;
    for (int i = 0; i < K; ++i) {
        string word;
        cin >> word;
        trie.insert(word);
    }
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        if (dp[i] == 0) continue;
        TrieNode* node = trie.root;
        for (int j = i; j < N; ++j) {
            int idx = S[j] - 'a';
            if (!node->child[idx]) break;
            node = node->child[idx];
            if (node->isEnd) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[N] << '\n';
}
