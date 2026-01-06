#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;

// Leetcode Problem Number - 1161

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=nullptr;
    }
};

class Solution{
public:
    int maxlevelsum(TreeNode *root){
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        int answer=1;
        long long maxsum=LLONG_MIN;
        while(!q.empty()){
            int n=q.size();
            long long currsum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                currsum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(currsum>maxsum){
                maxsum=currsum;
                answer=level;
            }
            level++;
        }
        return answer;
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
    Solution sol;
    while(t--){    
        int n;
        fin>>n;
        vector<int>nodes(n);
        for(int i=0;i<n;i++) fin>>nodes[i];
        TreeNode* root=buildTree(nodes);
        fout<<"Maximum sum is at level: "<<sol.maxlevelsum(root)<<endl;
        deleteTree(root);
    }
    fin.close();
    fout.close();
    return 0;
}
