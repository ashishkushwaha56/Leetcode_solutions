// 2nd Approach

class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int t){
        if(root==NULL)
            return;
        t = t^(1<<root->val);
        if(root->left==NULL and root->right == NULL){
            if((t&(t-1)) == 0)
                res++;
        }
        dfs(root->left,t);
        dfs(root->right,t);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return res;
    }
};


// 1st Approach

class Solution {
public:
    int res =0;
    void dfs(TreeNode* root, vector<int> &v){
        if(root == NULL)
            return;
        v[root->val]++;
        if(root->left == NULL and root->right == NULL){
            int num_odd = 0;
            int num_even = 0;
            int total = 0;
            for(int i = 0;i<10;i++){
                total+=v[i];
                if(v[i]&1)
                    num_odd++;
                else
                    num_even++;
            }
            if(((total&1) and num_odd == 1) or (!(total&1) and !num_odd))
                res++;
        }
        dfs(root->left,v);
        dfs(root->right,v);
        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10);
        dfs(root,v);
        return res;
    }
};
