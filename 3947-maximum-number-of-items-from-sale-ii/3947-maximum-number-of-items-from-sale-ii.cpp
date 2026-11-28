class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        int minPrice = INT_MAX;

        // Calculate frequency of each factor
        for(auto &item : items){
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        // Count divisible factors using multiples
        for(int f = 1; f <= n; f++){
            for(int j = f; j <= n; j += f){
                cnt[f] += freq[j];
            }
        }

        // Sort items by price
        sort(items.begin(), items.end(),
            [](const auto &a, const auto &b){
                return a[1] < b[1];
            });

        long long ans = 0;
        long long remaining = budget;

        for(auto &item : items){
            int factor = item[0];
            int price = item[1];

            // Normal purchases are equally good or better
            if(price >= 2LL * minPrice){
                break;
            }

            long long freeItems = cnt[factor] - 1;

            long long copies = min(
                freeItems,
                remaining / price
            );

            ans += 2 * copies;
            remaining -= copies * price;
        }

        // Buy additional copies of the cheapest item
        ans += remaining / minPrice;

        return ans;
    }
};