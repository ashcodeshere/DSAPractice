#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:

    //Leetcode Problem Number - 29

    int dividewithoutdivison(int divisor,int dividend){
        if(divisor==dividend) return 1;
        bool pos=(divisor>0)==(dividend>0);
        if(dividend==INT32_MIN && divisor==-1) return INT32_MAX;
        long long n=llabs((long long)dividend);
        long long d=llabs((long long)divisor);
        long long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))) cnt++;
            ans+=(1ll<<cnt);
            n-=(d<<cnt);
        }
        if(!pos) ans=-ans;
        if(ans>INT32_MAX) return INT32_MAX;
        if(ans<INT32_MIN) return INT32_MIN;
        return (int)ans;
    }

    //Leetcode Problem Number - 66

    vector<int> plusOne(vector<int>&digits){
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]+=1;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
}; 
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    while(cin>>n){
        vector<int> digits(n);
        for(int i=0;i<n;i++) cin>>digits[i];
        Solution sol;
        vector<int>results=sol.plusOne(digits);
        for(int x:results) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}