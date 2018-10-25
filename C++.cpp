#include <iostream>
#include <vector>
using namespace std;


class MaximumDepthofBinaryTree { // Problem 104 
public:
    struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int leftdepth=maxDepth(root->left);
        int rightdepth=maxDepth(root->right);
        return (leftdepth>rightdepth ? leftdepth:rightdepth)+1 ;
    }
};

class HammingDistance {  //Problem 461
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int hammingDistance = 0;
        while (z != 0) {
            hammingDistance++;
            z = z & (z - 1);
        }
        return hammingDistance;
    }
};

class ToLowerCase {  // Problem 709
public:
    string toLowerCase(string str) {
        for(unsigned int i = 0; i < str.length(); i++)
        {
            if ((str[i] >= 'A') && (str[i] <= 'Z'))
		    str[i]= str[i] + ('a' - 'A');
        }
        return str;
    }
};

class JewelsAndStones {  // Problem 771
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for (char s : S) {
            for (char j : J) {
                if (s == j) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};

class SortArrayByParity {  // Problem 905
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size() - 1;
        while(i < j)
        {
            while(i < j && A[i] % 2 == 0) i++;
            if(A[i] % 2 == 1)
            {
                int temp = A[j];
                A[j--] = A[i];
                A[i] = temp;
            }
        }
        return A;
    }
};

class SortArrayByParityII {  // Problem 922
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i= 0 , j = 1, n = A.size();
        while (i<n && j<n) {
            while ((A[i] & 1) == 0) {
                i += 2;
            } if (i >= n) {
                break;
            } while ((A[j] & 1) == 1) {
                j += 2;
            } if (j >= n) {
                break;
            } swap(A[i], A[j]);
        }
        return A;
    }
};
