class Solution {
public:

    bool isValidSerialization(string preorder) {
        int slots = 1;

        stringstream ss(preorder);

        string token;
        while(getline(ss , token , ',')){

            slots--;

            if(slots < 0 ) return false;

            if(token != "#") slots += 2;


        }
        return slots == 0;
        
    }
};

class Solution1 {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;  // Start with 1 slot for the root
        int n = preorder.size();
        int i = 0;
        
        while (i < n) {
            // If no slots available before placing a node → invalid
            if (slots == 0) return false;
            
            if (preorder[i] == '#') {
                // Null node: consumes 1 slot, adds 0
                slots--;
                i++;  // Move past '#'
            } else {
                // Non-null node (a number): consumes 1 slot, adds 2 → net +1
                slots++;
                // Skip all digits of this number
                while (i < n && preorder[i] != ',') i++;
            }
            
            // Skip the comma (if any)
            if (i < n && preorder[i] == ',') i++;
        }
        
        // At the end, all slots must be filled exactly
        return slots == 0;
    }
};