// Basic Programs of Recursion

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution{
public:
    void print5times(int n){
        if(n>4)return;
        n++;
        print5times(n);
        cout<<"NAME"<<n<<' ';
    }
    void print1toN(int a,int n){
        if(a>n)return;
        cout<<a<<' ';
        a++;
        print1toN(a,n);
    }
    void printNto1(int N){
        if(N==0)return;
        cout<<N<<" ";
        N--;
        printNto1(N);
    }
    void print1toNBT(int n,int i){
        if(i==0)return;
        print1toNBT(n,i-1);
        cout<<i<<" ";
    }
    void printNto1BT(int n,int i){
        if(i==n+1)return;
        printNto1BT(n,i+1);
        cout<<i<<" ";
    }
    void reverseArray(int i,vector<int>&arr,int n){
        if(i>=n/2) return;
        swap(arr[i],arr[n-i-1]);
        reverseArray(i+1,arr,n);
    }
    bool checkPalindrome(char arr[],int i,int n){
        if(i>=n/2) return true;
        if(arr[i]!=arr[n-i-1]) return false;
        return checkPalindrome(arr,i+1,n);
    }
}; 

int main(){
    // int a=0,n;
    Solution sol;
    // sol.print5times(a);
    // cout<<"Enter Number: ";
    // cin>>n;
    // sol.print1toN(a,n);
    int N;
    cout<<"Enter Number: ";
    cin>>N;
    cout<<"Enter Elements: ";
    // vector<int>arr(N);
    // for(int i=0;i<N;i++) cin>>arr[i];
    // cout<<"Before"<<endl;
    // for(int i=0;i<N;i++) cout<<arr[i]<<" ";
    // sol.reverseArray(0,arr,N);
    // cout<<endl<<"After"<<endl;
    // for(int i=0;i<N;i++) cout<<arr[i]<<" ";
    char arr[N];
    for(int i=0;i<N;i++) cin>>arr[i];
    if(sol.checkPalindrome(arr,0,N)){
        cout<<"String is Palindrome"<<endl;
    }else{
        cout<<"Not a Palindrome"<<endl;
    }
    // sol.printNto1(N);
    // sol.print1toNBT(N,N);
    // sol.printNto1BT(N,1);
    return 0;
}
