/*
Runtime: 55 ms, faster than 13.78% of C online submissions for Zigzag Conversion.
Memory Usage: 7.5 MB, less than 27.08% of C online submissions for Zigzag Conversion.
*/


char ret[1001] ="\0";

char * convert(char * s, int numRows){
    if(numRows==1)return s;

    char temp[1001][1001]={"\0"};
    int index[1001]={0,};
    int direction = 0;
    int turningPoint = numRows-1;
    for(int i=0, j=0;; i++){
        if(s[i]==NULL)break;
    
        temp[j][index[j]]=s[i];
        index[j]++;

        if( (j==0 && direction==1 )|| i==turningPoint ){
            if(direction==0){
                direction = 1;
            } else if(direction==1){
                direction = 0;
                turningPoint+=numRows*2-2;
            }
        }
        if(direction==0){
            j++;
        }else if (direction==1){
            j--;
        }
    }

    int retIndex = 0;
    for(int i =0;; i++){
        for(int j =0;; j++){
            if(temp[i][j]==NULL) break;
            ret[retIndex]=temp[i][j];
            retIndex++;
        }
        if(temp[i][0]==NULL) break;
    }
    ret[retIndex]='\0';

    return ret;
}
