#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void subsequencesWithSumK(int index, vector<int>& arr, vector<int>& temp,set<vector<int>>& ansSet, int k, int currSum) {
        if(index==arr.size()) {
            if(currSum==k && !temp.empty()) {
                vector<int> tempCopy = temp;
                sort(tempCopy.begin(), tempCopy.end());
                ansSet.insert(tempCopy);
            }
            return;
        }
        temp.push_back(arr[index]);
        subsequencesWithSumK(index + 1, arr, temp, ansSet, k, currSum + arr[index]);
        temp.pop_back();
        subsequencesWithSumK(index + 1, arr, temp, ansSet, k, currSum);
    }
    vector<vector<int>> getSubsequencesWithSumK(vector<int>& arr, int k) {
        set<vector<int>> ansSet;
        vector<int> temp;
        subsequencesWithSumK(0, arr, temp, ansSet, k, 0);
        vector<vector<int>> ans(ansSet.begin(), ansSet.end());
        return ans;
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
        int n, k;
        fin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) fin>>arr[i];
        vector<vector<int>> ans=sol.getSubsequencesWithSumK(arr, k);
        fout<<"[\n";
        for(auto &vec : ans){
            fout<<"  [";
            for(size_t i = 0; i < vec.size(); i++){
                fout<<vec[i];
                if(i != vec.size() - 1) fout<<", ";
            }
            fout<<"]\n";
        }
        fout<<"]\n";
    }
    return 0;
}
