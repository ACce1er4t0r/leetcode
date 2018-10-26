#include <iostream>
#include <vector>
#include <set>
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

class NimGame {  // Problem 292
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

class ReverseString {  //Problem 344
public:
    void my_swap(char *s, char *t)
    {
        char temp = *s;
        *s = *t;
        *t = temp;
    }

    string reverseString(string s) {
        int length = s.size();
        int i = 0;
        int j = length - 1;

        while (i < j)
        {
            my_swap(&s[i], &s[j]);
            i++;
            j--;
        }
        return s;
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

class KeyboardRow {  // Problem 500
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        vector<set<char>> v(3);
        string s1 = "QWERTYUIOPqwertyuiop", s2 = "ASDFGHJKLasdfghjkl", s3 = "ZXCVBNMzxcvbnm";
        for (unsigned int i = 0; i < s1.length(); i++) {
            v[0].insert(s1[i]);
        }
        for (unsigned int i = 0; i < s2.length(); i++) {
            v[1].insert(s2[i]);
        }
        for (unsigned int i = 0; i < s3.length(); i++) {
            v[2].insert(s3[i]);
        }
        for (unsigned int i = 0; i < words.size(); i++) {
            int tag = -1;
            bool flag = true;
            if (words[i].length() == 0) {
                continue;
            }
            if (v[0].find(words[i][0]) != v[0].end()) {
                tag = 0;
            }
            if (v[1].find(words[i][0]) != v[1].end()) {
                tag = 1;
            }
            if (v[2].find(words[i][0]) != v[2].end()) {
                tag = 2;
            }
            for (unsigned int j = 1; j < words[i].length(); j++) {
                if (v[tag].find(words[i][j]) == v[tag].end()) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};

class ReverseWordsinaStringIII {  // Problem 557
public:
    string reverseWords(string s) {
        int i = 0, j = 0, t1;
        char t;
        int s1 = s.size();
        while(j < s1) {
            while(s[j] != ' ' && j < s1) {
                j++;
            }
            t1 = j + 1;
            j--;
            while(i < j) {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
                i++;
                j--;
            }
            i = t1;
            j = t1 + 1;
        }
        return s;
    }
};

class RobotReturntoOrigin {  // Problem 657
public:
    bool judgeCircle(string moves) {
        int len = moves.length();
        int x = 0, y = 0;
        for(int i = 0; i < len; i++) {
            if(moves[i] == 'U') {
                y++;
            } else if(moves[i] == 'D') {
                y--;
            } else if(moves[i] == 'R') {
                x++;
            } else {
                x--;
            }
        }
        if(x == 0 && y == 0) {
            return true;
        } else {
            return false;
        }
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

class SelfDividingNumbers {  // Problem 728
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i = left; i <= right; i++) {
            int temp = i;
            int t = i;
            while(temp != 0) {
                if(t % 10 == 0) {
                    break;
                }
                if(temp % (t % 10) != 0) {
                    break;
                } else {
                    t = t / 10;
                }
                if(t == 0) {
                    ret.push_back(temp);
                }
            }
        }
        return ret;
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

class PeakIndexinaMountainArray {  // Problem 852
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (unsigned int i = 1; i < A.size() - 1; i++)
            if (A[i] > A[i-1] && A[i] > A[i+1])
                return i;
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
