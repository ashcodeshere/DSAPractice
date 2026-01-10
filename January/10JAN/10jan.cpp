#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;

class Solution{
public:
    void bubblesort(vector<int>&arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            bool swapped=false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped=true;
                }
            }
            if(!swapped) break;
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
        sol.bubblesort(arr);
        for(int i=0;i<n;i++) fout<<arr[i]<<" ";
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
