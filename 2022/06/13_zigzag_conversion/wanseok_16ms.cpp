class Solution {
public:
    string convert(string s, int numRows) {
        
        const char* ptr = s.c_str();
        char dtr[1002];
        char* str = dtr;
        int len = s.length();
        int i,j;
        
        if(numRows ==1) return s;
        
        for(i=0;i<numRows;i++)
        {
            
            int jmax = 1 + len/(2*(numRows-1));
            for(j=0; j<jmax*2 /**/; j++) //곱하기 2 안하니까 ABCDE, 4 인 케이스가 통과가 안되서 넉넉잡아서 2곱해줌;;
            {
                int row0num = j*2*(numRows-1);
                if((row0num-i >= 0) && (i!=(numRows-1)) && (row0num-i < len))
                {
                    *str = *(ptr+ row0num-i);
                    str++;
                }
                
                if((row0num+i < len)&&(i!=0))
                {
                    *str = *(ptr+ row0num+i);
                    str++;
                }

            }
            
        }
        
    *str = NULL;
    string ret(dtr);
        
        
    return ret;        
    }
};
