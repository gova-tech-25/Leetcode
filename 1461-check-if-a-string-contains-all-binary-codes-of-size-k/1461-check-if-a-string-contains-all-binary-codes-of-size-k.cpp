class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        int total = 1 << k;
        vector<bool> seen(total, false);

        int mask = total - 1;
        int curr = 0, cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            curr = ((curr << 1) & mask) | (s[i] - '0');

            if (i >= k - 1 && !seen[curr]) {
                seen[curr] = true;
                cnt++;
                if (cnt == total) return true;
            }
        }

        return false;
    }
};

class Solution1 {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        if(n-k+1 < (1 << k)) return false;
        
        set<string>st;

        for(int i = 0 ; i <= n - k ; i++){
            string sub = s.substr(i , k);
            st.insert(sub);
        }

        return st.size() == (1 << k);
    }
};