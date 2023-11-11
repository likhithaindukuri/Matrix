class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<R;i++)
        {
            mn=min(mn,matrix[i][0]);
            mx=max(mx,matrix[i][C-1]);
        }
        while(mn<mx)
        {
            int mid=(mn+mx)/2;
            int x=0;
            for(int i=0;i<R;i++)
            {
                int ub=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                x+=ub;
            }
            if(x<((R*C+1)/2))
            {
                mn=mid+1;
            }
            else
            {
                mx=mid;
            }
        }
        return mn;
    }
};