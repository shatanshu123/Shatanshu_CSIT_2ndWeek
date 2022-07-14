//STRIVER_SDE_SHEET

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row;
        int col = matrix[0].size() - 1;
        int rowNum = -1;
        
        int low = 0;
        int high = matrix.size() - 1;
        
        if(matrix[0][col] >= target){
            rowNum = 0;
        }
        else{
            while(low <=high){
                int mid = (low+high)/2;
                if(target <= matrix[mid][col] && target > matrix[mid-1][col]){
                    rowNum = mid;
                    break;
                }
                else if(target < matrix[mid][col]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        
        
        if(rowNum == -1){ return false;}
        low = 0;
        high = col;
        
        while(low <= high){
            int mid = (low+high)/2;
            if(target == matrix[rowNum][mid]){
                return true;
            }
            else if(target < matrix[rowNum][mid]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
        
    }
};
