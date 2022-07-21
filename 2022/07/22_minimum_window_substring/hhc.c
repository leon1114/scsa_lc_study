// 음주한 관계로 일단 체크.. 내일 풀겠슴다
// 음 ?? 이거 내일문제네

char * minWindow(char * s, char * t){
    int ret_s, ret_e, ptr_s = 0, ptr_e = 0, ptr = 0;
    int t_cnts[80], s_cnts[80];
    int min_len = -1;
    
    // t를 밀어가면서 cnts 세기
    while(*t != '\0') {
        t_cnts[*t - 'A']++;
        t++;
    }
    
    int find_sol = 0, tmp_char;
    while (true) {
        tmp_char = s[ptr] - 'A';
        
        if (tmp_)
        s_cnts[];
        // ptr_e 뒤로 밀면서 sol 찾기
        if (s[ret_e] == '\0') ret_e++;
                
        // sol 찾은 이후일 경우 ptr_s 뒤로 하나씩 밀면서
        
        
        // min_sol 찾기
        if (min_len > ptr_e - ptr_s + 1) {
            min_len = ptr_e - ptr_s + 1;
            ret_e = ptr_e;
            ret_s = ptr_s;
        }
        
        // ptr_s, ptr_e 둘다 끝에 가면 나가기
        if (s[ptr_s] == '\0' && s[ptr_e] == '\0') break;
    }
    
    s[ret_e] = '\0';
    return s + ret_s;
}
