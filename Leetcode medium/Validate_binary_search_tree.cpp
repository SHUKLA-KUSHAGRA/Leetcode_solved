/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
public:
    vector <int> v; 
    bool isValidBST(TreeNode* root) {
         if(root==NULL)
        return true;
        bool flag=isValidBST(root->left);
        if(!flag)
            return false;
        v.push_back(root->val);
        flag=isValidBST(root->right);
        if(!flag)
            return false;
        for(int i=0;i<v.size()-1;i++)     
        {     
            if(v[i]>=v[i+1])
               return false;                    
        }
        return true;
    }
