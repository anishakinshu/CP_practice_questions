class Solution {
public:

    int solvesubpart(vector<int> &arr, int ind, int dp[], int d, int res=1){

        if(dp[ind])
            return dp[ind];

        for(int j = ind+1; j <= ind+d && j < arr.size()&& arr[j]<arr[ind]; j++){
            res = max(res, 1 + solvesubpart(arr,j,dp,d));
        }

        for(int j = ind-1; j >= 0 && j >= ind-d && arr[j]<arr[ind]; j--){
            res = max(res, 1 + solvesubpart(arr,j,dp,d));

        }

        dp[ind] = res;
        return dp[ind];
    }



    int maxJumps(vector<int>& arr, int d) {
        int i, j, ans = 0;
        int dp[100001];

        memset(dp,'\0',sizeof(dp));

        for(i = 0; i < arr.size(); i++){
            ans = max(ans, solvesubpart(arr, i, dp, d));
        }

        return ans;
    }
};
