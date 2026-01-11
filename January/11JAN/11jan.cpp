#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;

class Solution{
public:
    void selectionsort(vector<int>&arr){
        int minidx;
        int n=arr.size();
        for(int i=0;i<n;i++){
            minidx=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minidx]) minidx=j;
            }
            swap(arr[i],arr[minidx]);
        }
    }
}; 

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if(!fin){
        cerr<<"Error opening input file!"<<endl;
        return 1;
    }
    if(!fout){
        cerr<<"Error opening output file!"<<endl;
        return 1;
    }
    int t;
    fin>>t;
    while(t--){    
        int n;
        fin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) fin>>arr[i];
        Solution sol;
        sol.selectionsort(arr);
        for(int i=0;i<n;i++) fout<<arr[i]<<" ";
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
