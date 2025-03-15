class Solution {
public:
    static bool customSort(string& a, string& b) { return a.size() < b.size(); }

    bool isConcatenated(unordered_map<string, bool>& present, string& word,
                        int idx, vector<int>& dp) {
        if (idx == word.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string curr = "";
        int n = word.size();
        bool okay = false;
        for (int i = idx; i < n; i++) {
            curr += word[i];
            if (present[curr]) {
                okay = okay || isConcatenated(present, word, i + 1, dp);
            }
        }
        return dp[idx] = okay ? 1 : 0;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() == 1)
            return {};
        unordered_set<string> present(words.begin(), words.end());
        int n = words.size();
        vector<string> ans;

        vector<bool> dp(30 + 1, false);

        for (int i = 0; i < n; i++) {

            int size = words[i].size();
            string s = words[i];
            dp[size] = true;

            for (int j = size - 1; j >= 0; j--) {
                bool okay = false;
                for (int k = j; k < size; k++) {
                    if ( k - j + 1 != size &&  present.count(s.substr(j, k - j + 1)) ) {
                        okay = okay || dp[k + 1];
                    }
                }
                dp[j] = okay;
            }

            if (dp[0]) {
                ans.push_back(s);
            }

            fill(dp.begin(), dp.end(), false);
  
        }
        return ans;
    }
};