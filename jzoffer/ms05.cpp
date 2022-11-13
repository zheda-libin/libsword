#include "base.h"


class Solution {
public:
    string replaceSpace(string s) {
        
        int length = s.size();
        int count = count_if(s.begin(), s.end(), [](auto c){return c==' ';});
        // for (auto c: s) {
        //     if (c == ' ') {
        //         count++;
        //     }
        // }
        s.resize(length+2*count);

        for(int i=length-1, j=s.size()-1; i<j; --i, --j) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j]='0';
                s[j-1]='2';
                s[j-2]='%';
                j-=2;
            }
        }
        return s;
    }
};
