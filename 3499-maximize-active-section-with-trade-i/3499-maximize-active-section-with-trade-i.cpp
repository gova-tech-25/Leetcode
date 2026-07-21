class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";

        vector<pair<char,int>> blocks;

        // Run-length encoding
        for (char c : t) {
            if (blocks.empty() || blocks.back().first != c)
                blocks.push_back({c, 1});
            else
                blocks.back().second++;
        }

        int totalOnes = 0;
        for (auto &p : blocks)
            if (p.first == '1')
                totalOnes += p.second;

        int ans = totalOnes;

        // Every removable 1-block has 0-blocks on both sides.
        for (int i = 1; i + 1 < blocks.size(); i++) {
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                ans = max(ans,
                          totalOnes +
                          blocks[i - 1].second +
                          blocks[i + 1].second);
            }
        }

        return ans - 2;   // remove the two artificial boundary 1's
    }
};