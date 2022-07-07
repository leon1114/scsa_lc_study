
char * countAndSay(int n){
    char * re = (char*)malloc(sizeof(char)*5000);
    char * temp = (char*)malloc(sizeof(char)*5000); 

    re[0] = '1';
    int re_len = 1;
    
    for(int i=0; i<n-1; i++)
    {
        int cnt = 0;
        int temp_idx = 0;
        char c = re[0];
        int len = re_len;
        for( int j =0; j<= len;)
        {
            if(re[j]==c){
                cnt++;
                j++;
            }else{
                temp[temp_idx] = cnt +'0';
                temp_idx++;
                temp[temp_idx] = c;
                temp_idx++;
                c= re[j];
                cnt = 0;
                re_len = temp_idx;
            }
        }
        strcpy(re,temp);          
    }

    re[re_len]='\0';

    return re;
}
