#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
public:

    // Leetcode Problem Number - 1411
    
    int NumberofWays(int n){
        long long mod=1000000007;
        long long abc=6;
        long long aba=6;
        for(int i=1;i<n;i++){
            long long next_aba=(3*aba+2*abc)%mod;
            long long next_abc=(2*aba+2*abc)%mod;
            abc=next_abc;
            aba=next_aba;
        }
        return (int)((abc+aba)%mod);
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
        if(n==0) return 0;
        cout<<"Number of ways: "<<sol.NumberofWays(n)<<endl;
    }
    return 0;
}