#pragma once

#include <iostream>
#include <vector>
#include <queue>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if (root == NULL)
        {
            return ret;
        }
        std::queue<TreeNode*> workQueue;
        workQueue.push(root);
        while(!workQueue.empty())
        {
            int queueSize = workQueue.size();
            std::vector<int> subRet;
            for (int i = 1; i<= queueSize; i++)
            {
                TreeNode* curr = workQueue.front();
                subRet.push_back(curr->val);
                workQueue.pop();
                if (curr->left != NULL)
                {
                    workQueue.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    workQueue.push(curr->right);
                }
            }
            ret.push_back(subRet);
        }
        return ret; 
    }
};