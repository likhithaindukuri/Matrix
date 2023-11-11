class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=0,count=0;
        for(int i=0;i<mat.size();i++)
        {
            int tempCount=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    tempCount++;
                }
            }
            if(tempCount>count)
            {
                row=i;
                count=tempCount;
            }
        }
        return {row,count};
    }
};