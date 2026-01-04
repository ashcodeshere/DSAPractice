#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:

    // Leetcode Problem Number - 1390

    int FourDivisor(vector<int>&nums){
        int totalsum=0;
        for(int n:nums){
            int sum=0;
            int count=0;
            for(int i=1;i*i<=n;i++){
                if(n%i==0){
                    int d1=i;
                    int d2=n/i;
                    if(d1==d2){
                        count++;
                        sum+=d1;
                    }else{
                        count+=2;
                        sum+=d1+d2;
                    }
                }
                if(count>4) break;
            }
            if(count==4) totalsum+=sum;
        }
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
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<"Sum of numbers with exact four divisors: "<<sol.FourDivisor(nums)<<endl;
    }
    return 0;
}