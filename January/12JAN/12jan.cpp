#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution{
public:
    void insertionsort(vector<int>&arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            int pivot=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>pivot){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=pivot;
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
        sol.insertionsort(arr);
        for(int i=0;i<n;i++) fout<<arr[i]<<" ";
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
