class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefCnt(n + 1, 0);
        vector<long long> prefNum(n + 1, 0);

        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = pow10[i - 1] * 10 % MOD;

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i];
            prefCnt[i + 1] = prefCnt[i];
            prefNum[i + 1] = prefNum[i];

            int d = s[i] - '0';

            if (d != 0) {
                prefSum[i + 1] += d;
                prefCnt[i + 1]++;
                prefNum[i + 1] = (prefNum[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            long long cnt = prefCnt[r + 1] - prefCnt[l];

            long long num =
                (prefNum[r + 1] -
                 prefNum[l] * pow10[cnt] % MOD + MOD) % MOD;

            ans.push_back(num * (sum % MOD) % MOD);
        }

        return ans;
    }
};