// by tampering the original matrix
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int oldc=image[sr][sc];
        if (oldc==color) return image;
        dfs(image,sr,sc,oldc,color);
        return image;
    }

    void dfs(vector<vector<int>>& image,int r,int c,int oldc,int newc){
        if(r<0 || r>=image.size() || c<0 || c>=image[0].size() || image[r][c]!=oldc){
            return;
        }

        image[r][c]=newc;

        dfs(image,r+1,c,oldc,newc);
        dfs(image,r-1,c,oldc,newc);
        dfs(image,r,c+1,oldc,newc);
        dfs(image,r,c-1,oldc,newc);
    }
};

// without tampering.. 

// class Solution {
// public:

//     void dfs(int row ,int col , vector<vector<int>>& image , vector<vector<int>>& ans , int dx[] , int dy[] , int ini , int color){
//         ans[row][col] = color;
//         int n = image.size();
//         int m = image[0].size();

//         for(int i = 0 ; i < 4 ; i++){
//             int nx = row + dx[i];
//             int ny = col + dy[i];

//             if(nx >= 0 && nx < n && ny >= 0 && ny < m   
//                 && image[nx][ny] == ini && ans[nx][ny] != color ){
//                     dfs(nx ,ny , image , ans , dx ,dy , ini , color);
//                 }
//         }
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         vector<vector<int>>ans = image;
//         int ini = image[sr][sc];

//          if (ini == color)
//          return image;


//         int dx [] = { -1 , 0 , 1 , 0};
//         int dy [] = { 0 , 1 , 0 , -1};

//         dfs(sr,sc , image , ans , dx ,dy , ini , color);
//         return ans;
//     }
// };