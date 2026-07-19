class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> vis(26, false);
        string ans;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (vis[ch - 'a'])
                continue;

            while (!ans.empty() &&
                   ans.back() > ch &&
                   last[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            vis[ch - 'a'] = true;
        }

        return ans;
    }
};