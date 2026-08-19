class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> freq;

        for(string word : words){
            freq[word]++;
        }

        vector<pair<string , int>>arr;
        for(auto &[word , count] : freq){
            arr.push_back({word , count});
        }
        
        sort(arr.begin() , arr.end() , [](auto &a , auto &b){
            if(a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        });

        vector<string> ans;

        for(int i = 0 ;  i < k ; i++){
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};