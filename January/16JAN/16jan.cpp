#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge(vector<int> &arr,int left,int mid,int right){
        vector<int>temp;
        int i=left,j=mid+1;
        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }
        while(i<=mid)temp.push_back(arr[i++]);
        while(j<=right)temp.push_back(arr[j++]);
        for(int k=0;k<temp.size();k++) arr[left+k]=temp[k];
    }
    void mergeSort(vector<int> &arr,int left,int right){
        if(left>=right)return;
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    int partition(vector<int>&arr,int left,int right){
        int pivot=arr[right];
        int i=left-1;
        for(int j=left;j<right;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[right]);
        return i+1;
    }
    void quickSort(vector<int>&arr,int left,int right){
        if(left<right){
            int pi=partition(arr,left,right);
            quickSort(arr,left,pi-1);
            quickSort(arr,pi+1,right);
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
    Solution sol;
    int t;
    fin >> t;
    while(t--){
        int n;
        fin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) fin>>arr[i];
        fout<<"Before: ";
        for(int i=0;i<n;i++) fout<<arr[i]<<" ";
        fout<<endl;
        // sol.mergeSort(arr,0,n-1);
        sol.quickSort(arr,0,n-1);
        fout<<"After: ";
        for(int i=0;i<n;i++) fout<<arr[i]<<" ";
        fout<<endl;
    }
    return 0;
}
