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

#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void preorderTraversalFind(TreeNode* root, int target, TreeNode*& targetNode, std::unordered_map<int, TreeNode*>& nodeFatherMap){
        if(root == nullptr)return;
        if(root->val == target) targetNode = root;
        if(root->left != nullptr){
            nodeFatherMap.insert({root->left->val, root});
            preorderTraversalFind(root->left, target, targetNode, nodeFatherMap);
        }
        if(root->right != nullptr){
            nodeFatherMap.insert({root->right->val, root});
            preorderTraversalFind(root->right, target, targetNode, nodeFatherMap);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* startNode = nullptr;
        std::unordered_map<int, TreeNode*> nodeFatherMap;
        preorderTraversalFind(root, start, startNode, nodeFatherMap);
        std::queue<TreeNode*> node_queue;
        TreeNode* p;
        node_queue.push(startNode);
        int result = 0;
        std::unordered_set<int> infected_node{start};
        ///层序遍历，深度就是感染分钟数
        while(!node_queue.empty()){
            int level_size = node_queue.size();
            for(int i = 0; i < level_size; ++i){    
                p = node_queue.front();
                node_queue.pop();
                if(p->left != nullptr && infected_node.find(p->left->val) == infected_node.end()){
                    node_queue.push(p->left);
                    infected_node.insert(p->left->val);
                }
                if(p->right != nullptr && infected_node.find(p->right->val) == infected_node.end()){
                    node_queue.push(p->right);
                    infected_node.insert(p->right->val);
                }
                if(nodeFatherMap[p->val] != nullptr && infected_node.find(nodeFatherMap[p->val]->val) == infected_node.end()){
                    node_queue.push(nodeFatherMap[p->val]);
                    infected_node.insert(nodeFatherMap[p->val]->val);
                }
            }
            ++result;
        }
        return result - 1;
    }
};

TreeNode* buildTree(const std::vector<int>& d){
    TreeNode* root = new TreeNode(d[0]);
    TreeNode* p;
    std::queue<TreeNode*> node_queue;
    node_queue.push(root);
    int i = 1;
    while(!node_queue.empty()&&i<d.size()){
        p = node_queue.front();
        node_queue.pop();
        if(i < d.size()){
            if(d[i] != -1){
                p->left = new TreeNode(d[i]);
                node_queue.push(p->left);
            }
            else p->left = nullptr;
            ++i;
        }
        if(i < d.size()){
            if(d[i] != -1){
                p->right = new TreeNode(d[i]);
                node_queue.push(p->right);
            }
            else p->right = nullptr;
            ++i;
        }        
    }
    return root;
}

void preorderTraversal(TreeNode* root){
    if(root == nullptr)return;
    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    std::vector<int>d{1,5,3,-1,4,10,6,9,2};
    TreeNode* root = buildTree(d);
    preorderTraversal(root);
    Solution s;
    std::cout << "result:" << s.amountOfTime(root, 3) << std::endl;

    // std::vector<int>d{1};
    // TreeNode* root = buildTree(d);
    // preorderTraversal(root);
    // Solution s;
    // std::cout << "result:" << s.amountOfTime(root, 1) << std::endl;
}