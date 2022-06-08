/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


class Solution {
public:
    int ar[128] = {0,};
    int br[128] = {0,};
    int i = 1;
    int last = 0;
    int maxcount = 0;
    int count=0;
    int lengthOfLongestSubstring(string s) {
        //문자가 반복되지 않을때까지 집어넣는다 (maxcount 올린다)
        //string ptr = s;
        const char *ptr = s.c_str();
        //char a = "a";
        while(*ptr)
        {
            //if(ptr[0] == 'a') return 1;
            if((ar[*ptr]!=0)&&(br[*ptr]>last))
            {
                if(maxcount<count) maxcount = count;
                count = i - br[*ptr];
                //count = count + 1 - br[*ptr];
                last = br[*ptr];
                br[*ptr]=i;
            }
            else if((ar[*ptr]!=0)&&(br[*ptr]<=last))
            {
                br[*ptr]=i;
                count++;
            }
            else
            {
                br[*ptr] = i;
                ar[*ptr] = 1;
                count++;
                
            }

            i++;
            ptr++;
        }
        //3.
        if(maxcount<count) maxcount = count;
        return maxcount;
    }
};
