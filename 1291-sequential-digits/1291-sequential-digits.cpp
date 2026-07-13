class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int>q;

        for(int i = 1 ; i <=9 ; i++)
            q.push(i);
        
        while(!q.empty()){

            int num = q.front();
            q.pop();

            if(num >= low && num <= high){
                ans.push_back(num);
            }

            int last_digit = num % 10;

            if(last_digit == 9) continue;

            int nextNumber = num * 10 + (last_digit + 1);
            
            if(nextNumber <= high){
                q.push(nextNumber);
            }
        }
        return ans;
        
    }
};