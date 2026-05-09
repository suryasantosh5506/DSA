class Solution {
public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();

        int m = grid[0].size();

        int top = 0, bottom = n - 1;

        int left = 0, right = m - 1;

        while(top < bottom && left < right){

            vector<int> arr;

            for(int i = left; i <= right; i++){
                arr.push_back(grid[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++){
                arr.push_back(grid[i][right]);
            }
            right--;

            for(int i = right; i >= left; i--){
                arr.push_back(grid[bottom][i]);
            }
            bottom--;

            for(int i = bottom; i >= top; i--){
                arr.push_back(grid[i][left]);
            }
            left++;

            int size = arr.size();

            int rot = k % size;

            reverse(arr.begin(), arr.end());

            reverse(arr.begin(),arr.begin() + (size - rot));

            reverse(arr.begin() + (size - rot), arr.end());

            top--;
            right++;
            bottom++;
            left--;

            int idx = 0;

            for(int i = left; i <= right; i++){
                grid[top][i] = arr[idx++];
            }
            top++;

            for(int i = top; i <= bottom; i++){
                grid[i][right] = arr[idx++];
            }
            right--;

            for(int i = right; i >= left; i--){
                grid[bottom][i] = arr[idx++];
            }
            bottom--;

            for(int i = bottom; i >= top; i--){
                grid[i][left] = arr[idx++];
            }
            left++;
        }

        return grid;
    }
};