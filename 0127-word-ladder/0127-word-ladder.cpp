#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = wordList.size();

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;

        q.push({beginWord , 1});
        st.erase(beginWord);

        if(st.find(endWord) == st.end())
         return 0;
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord)
                return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    // if new word exist in set list
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};