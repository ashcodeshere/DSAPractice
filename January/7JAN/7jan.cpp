#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;

// Leetcode Problem Number - 1339

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

    long long mod=1e9+7;
    long long total=0;
    long long ans=LLONG_MIN;

    long long subTreesum(TreeNode *root){
        if(!root)return 0;
        long long leftsum=subTreesum(root->left);
        long long rightsum=subTreesum(root->right);
        long long subtree=leftsum+rightsum+root->val;
        ans=max(ans,subtree*(total-subtree));
        return subtree;
    }

    long long totalsum(TreeNode *root){
        if(!root) return 0;
        return root->val+totalsum(root->left)+totalsum(root->right);
    }

    int maxProduct(TreeNode *root){
        total=totalsum(root);
        ans=LLONG_MIN;
        subTreesum(root);
        return ans%mod;
    }
}; 

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
    while(t--){    
        int n;
        fin>>n;
        vector<int>nodes(n);
        for(int i=0;i<n;i++) fin>>nodes[i];
        TreeNode* root=buildTree(nodes);
        Solution sol;
        fout<<"Maximum Product: "<<sol.maxProduct(root)<<endl;
        deleteTree(root);
    }
    fin.close();
    fout.close();
    return 0;
}
