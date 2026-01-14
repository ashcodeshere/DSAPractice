// Basic Programs of Recursion
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int fibonacci(int n){
        if(n<=1) return n;
        return fibonacci(n-1)+fibonacci(n-2);
    }
    void subsequences(int idx,vector<int>&arr,vector<vector<int>>&ans,vector<int>& temp){
        if(idx>=arr.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(arr[idx]);
        subsequences(idx+1,arr,ans,temp);
        temp.pop_back();
        subsequences(idx+1,arr,ans,temp);
    }
}; 

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if(!fin){
        cerr<<"Error opening inout file!"<<endl;
        return 1;
    }
    if(!fout){
        cerr<<"Error opening output file!"<<endl;\
        return 1;
    }
    Solution sol;
    int t;
    fin>>t;
    while(t--){
        int n;
        fin>>n;
        vector<int>arr(n);
        vector<vector<int>>ans;
        vector<int>temp;
        // cout<<sol.fibonacci(n);
        for(int i=0;i<n;i++) fin>>arr[i];
        sol.subsequences(0,arr,ans,temp);
        fout<<"[ ";
        for(auto vec:ans){
            fout<<" [";
            for(int it:vec)fout<<" "<<it<<" ";
            fout<<"]"<<", ";
        }
        fout<<" ]";
        fout<<endl;
    }
    return 0;
}
