#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:

    // Leetcode Problem Number - 1975

    long long maxMatrixsum(vector<vector<int>>&nums){
        long long totalsum=0;
        int neg_cnt=0;
        int minval=INT32_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(nums[i][j]<0) neg_cnt++;
                if(minval>abs(nums[i][j])) minval=abs(nums[i][j]);
                totalsum+=abs(nums[i][j]);

            }
        }
        if(neg_cnt%2==1) totalsum-=2LL*minval;
        return totalsum; 
    }
}; 
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    cin.ignore();
    Solution sol;
    while(t--){    
        int n;
        cin>>n;
        cin.ignore();
        vector<vector<int>> nums(n,vector<int>(n));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)cin>>nums[i][j];
        cout<<"Maximum sum: "<<sol.maxMatrixsum(nums)<<endl;
    }
    return 0;
}