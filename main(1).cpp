#include <iostream>
#include <climits>

struct Tree
{
    int val;
    Tree *left;
    Tree *right;
    Tree(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxPathSum(Tree *root)
    {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(Tree *node, int &maxSum)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftSum = std::max(0, maxPathSumHelper(node->left, maxSum));
        int rightSum = std::max(0, maxPathSumHelper(node->right, maxSum));

        maxSum = myMax(maxSum, leftSum + rightSum + node->val);

        return myMax(leftSum, rightSum) + node->val;
    }

    int myMax(int a, int b)
    {
        return a > b ? a : b;
    }

    int myMin(int a, int b)
    {
        return a < b ? a : b;
    }
};

int main()
{
    setlocale(LC_ALL, "RU");

    Tree *root1 = new Tree(1);
    root1->left = new Tree(2);
    root1->right = new Tree(3);

    Solution solution;
    std::cout << "Ответ: " << solution.maxPathSum(root1) << std::endl;

    // Очистка памяти
    delete root1->left;
    delete root1->right;
    delete root1;

    return 0;
}