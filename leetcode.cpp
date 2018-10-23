#include <iostream>
using namespace std;

class ToLowerCase {  //Problem 709
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

class JewelsAndStones {  //Problem 771
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
