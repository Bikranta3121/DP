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
class Solution {
public:
    vector<TreeNode*> permute(int start,int end)
    {
        vector<TreeNode*> list;
       if(start>end)
       {
           list.push_back(NULL);
           return list;
       }
        
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> lefttree=permute(start,i-1);//left subtree
            vector<TreeNode*> righttree=permute(i+1,end);// right subtree
            
            
            for(int m=0;m<lefttree.size();m++)//combination formed by left subtree and right subtree
            {
                struct TreeNode* LEFT=lefttree[m];
                for(int n=0;n<righttree.size();n++)
                {
                    struct TreeNode* RIGHT=righttree[n];
                    struct TreeNode* node=new TreeNode(i);
                    node->left=LEFT;
                    node->right=RIGHT;
                    list.push_back(node);
                }
            }
            
        }
        return list;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> vis(n+1,0);
        vector<TreeNode*> res;
        struct TreeNode* ans=new TreeNode();
        return permute(1,n);
    }
};
