#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
public:

    // Leetcode Problem number 961
    
    int repeatedNTimes(vector<int>&digits){
        unordered_map<int,int>mp;
        int n=digits.size()/2;
        for(int i:digits){
            mp[i]++;
            if(mp[i]==n) return i;
        }
        return -1;
    }

    // Code360 problem number - ZIG ZAG String

    string zigzagstring(string str,int n,int m){
        if(m==1) return str;
        vector<string> rows(m);
        int row=0;
        int direction=1;
        for(char c:str){
            rows[row]+=c;
            row+=direction;
            if(row==0 || row==m-1) direction*=-1;
        }
        string res;
        for(string s:rows) res+=s;
        return res;
    }

}; 
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){    
        int n,s,m;
        cin>>n; //length of vector
        cin>>s; //Length of string
        cin>>m; //No of rows
        char a;
        string str;
        vector<int>digits(n);
        for(int i=0;i<n;i++) cin>>digits[i]; //elems of vector
        for(int i=0;i<s;i++){
            cin>>a; //Input String
            str+=a;
        }
        Solution sol;
        int x=sol.repeatedNTimes(digits);
        string res=sol.zigzagstring(str,s,m);
        cout<<x<<" is repeated"<<endl;
        cout<<"Final String : "<<res<<endl;
    }
    return 0;
}