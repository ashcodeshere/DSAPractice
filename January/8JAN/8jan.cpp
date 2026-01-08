#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=nullptr;
    }
    TreeNode(int x,TreeNode* l, TreeNode* r){
        val=x;
        left=l;
        right=r;
    }
};

class Solution{
public:

    TreeNode* buildTree(const vector<int> &nodes){
    if(nodes.empty()||nodes[0]==-1) return nullptr;
    TreeNode* root=new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<nodes.size()){
        TreeNode* curr=q.front();
        q.pop();
        if(nodes[i]!=-1){
            curr->left=new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if(i<nodes.size() && nodes[i]!=-1){
            curr->right=new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
    
}; 

void deleteTree(TreeNode* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

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
    Solution sol;
    while(t--){    
        int n;
        fin>>n;
        vector<int>nodes(n);
        for(int i=0;i<n;i++) fin>>nodes[i];
        TreeNode* root=sol.buildTree(nodes);
        fout<<"Tree Build"<<endl;
        deleteTree(root);
    }
    fin.close();
    fout.close();
    return 0;
}
