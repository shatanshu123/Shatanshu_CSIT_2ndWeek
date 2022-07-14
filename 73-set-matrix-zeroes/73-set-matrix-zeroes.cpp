//STRIVER_SDE_SHEET

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int i,j,x,y;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> v(m, vector<int>(n,0));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(v[i][j]==0)
                {
                    if(matrix[i][j]==0)
                    {
                        for(x=0;x<m;x++)
                        {
                            if(matrix[x][j]!=0)
                            {
                                matrix[x][j]=0;
                                v[x][j]=1;
                            }
                        }
                        
                        for(y=0;y<n;y++)
                        {
                            if(matrix[i][y]!=0)
                            {                            
                                matrix[i][y]=0;
                                v[i][y]=1;
                            }
                        }
                    }
                }
            }
        }
        
        
        
        
    }
};
