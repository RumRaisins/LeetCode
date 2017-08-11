
#include <stdlib.h>
#include <stdio.h>
#define max( a,b)
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int get_max_depth(struct TreeNode* root, int depth) {
	if (!root)return depth;
	return max(get_max_depth(root->left, depth + 1), get_max_depth(root->right, depth + 1));
}

void calc_column_num(struct TreeNode* root, int depth, int *columnNum) {
	if (!root)return;
	++columnNum[depth];
	calc_column_num(root->left, depth + 1, columnNum);
	calc_column_num(root->right, depth + 1, columnNum);

}
void fetch_result(struct TreeNode *root, int **ret, int depth, int *index) {
	if (!root) return;
	ret[depth][index[depth]++] = root->val;
	fetch_result(root->left, ret, depth + 1, index);
	fetch_result(root->right, ret, depth + 1, index);
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	int tree_depth = get_max_depth(root, 0);
	int *columnNum = (int*)calloc(tree_depth, sizeof(int));
	calc_column_num(root, 0, columnNum);
	int  **result = (int **)malloc(sizeof(int *) * tree_depth);
	int *index = (int*)calloc(tree_depth, sizeof(int));
	for (int i = 0; i < tree_depth; ++i) {
		result[i] = (int*)malloc(columnNum[i] * sizeof(int));
	}
	fetch_result(root, result, 0, index);
	*returnSize = tree_depth;
	*columnSizes = columnNum;
	free(index);
	return result;
}

