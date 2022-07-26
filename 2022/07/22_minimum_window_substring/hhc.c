// Runtime: 5 ms, faster than 80.25% of C online submissions for Minimum Window Substring.
// Memory Usage: 6.5 MB, less than 74.07% of C online submissions for Minimum Window Substring.
// O(2m+n) solution

// sol인지 판단하는 로직에서 loop 제거
// TODO: O(m+n)? 가능?도전? ㄴㄴ

char * minWindow(char * s, char * t){
    int ret_s = -1, ret_e = -1, ptr_s = 0, ptr_e = 0;
    int t_cnts[53] = {0, }, s_cnts[53] = {0, };
    int min_len = 999999;
    int is_sol_cnt = 0, tmp_char;
    
    // t를 밀어가면서 cnts 세기
    while(*t != '\0') {
        tmp_char = *t >= 'A' && *t <= 'Z' ? *t - 'A' : *t - 'a' + 26;
        t_cnts[tmp_char]++;
        if (t_cnts[tmp_char] == 1) is_sol_cnt++;
        t++;
    }
    
    while (true) {
        // is_sol_cnt > 0이면 ptr_e 뒤로 밀면서 sol 찾기
        if (is_sol_cnt > 0 && s[ptr_e] != '\0') {
            tmp_char = s[ptr_e] >= 'A' && s[ptr_e] <= 'Z' ? s[ptr_e] - 'A' : s[ptr_e] - 'a' + 26;
            if (t_cnts[tmp_char]) {
                s_cnts[tmp_char]++;
                // 현재 ptr_s~ptr_e가 sol인지 판단
                if (s_cnts[tmp_char] == t_cnts[tmp_char]) { is_sol_cnt--; }
            }
            ptr_e++;
        }
        // is_sol_cnt == 0이면 ptr_s 뒤로 하나씩 밀면서
        else if (is_sol_cnt == 0 && s[ptr_s] != '\0') {
            tmp_char = s[ptr_s] >= 'A' && s[ptr_s] <= 'Z' ? s[ptr_s] - 'A' : s[ptr_s] - 'a' + 26;
            if (t_cnts[tmp_char]) {
                s_cnts[tmp_char]--;
                // 현재 ptr_s~ptr_e가 sol인지 판단
                if (s_cnts[tmp_char] < t_cnts[tmp_char]) { is_sol_cnt++; }
            }
            ptr_s++;
        }
        
        // is_sol_cnt = 0인 경우 min_sol 췤
        if (is_sol_cnt == 0 && min_len > ptr_e - ptr_s + 1) {
            min_len = ptr_e - ptr_s + 1;
            ret_e = ptr_e;
            ret_s = ptr_s;
        }
        
        // ptr_e 끝에 가고 is_sol_cnt > 0면 나가기
        if (is_sol_cnt > 0 && s[ptr_e] == '\0') break;
    }
    if (ret_e == -1) {
        ret_s = ptr_e; ret_e = ptr_e;
    }
    s[ret_e] = '\0';
    return s + ret_s;
}

// // Runtime: 34 ms, faster than 19.75% of C online submissions for Minimum Window Substring.
// // Memory Usage: 6.5 MB, less than 74.07% of C online submissions for Minimum Window Substring.
// // O(104?m+n) solution

// // TODO: sol인지 판단하는거 hash로 바꿈

// char * minWindow(char * s, char * t){
//     int ret_s = -1, ret_e = -1, ptr_s = 0, ptr_e = 0;
//     int t_cnts[53] = {0, }, s_cnts[53] = {0, };
//     int min_len = 999999;
    
//     // t를 밀어가면서 cnts 세기
//     while(*t != '\0') {
//         if (*t >= 'A' && *t <= 'Z') {
//             t_cnts[*t - 'A']++;
//         } else {
//             t_cnts[*t - 'a' + 26]++;
//         }
//         t++;
//     }
    
//     int is_sol = 0, tmp_char;
//     while (true) {
//         // is_sol == 0이면 ptr_e 뒤로 밀면서 sol 찾기
//         if (is_sol == 0 && s[ptr_e] != '\0') {
//             tmp_char = s[ptr_e] >= 'A' && s[ptr_e] <= 'Z' ? s[ptr_e] - 'A' : s[ptr_e] - 'a' + 26;
//             if (t_cnts[tmp_char]) {
//                 s_cnts[tmp_char]++;
//                 // 현재 ptr_s~ptr_e가 sol인지 판단
//                 is_sol = 1;
//                 for (int i = 0; i < 52; i++) {
//                     if (s_cnts[i] < t_cnts[i]) {is_sol = 0; break;}
//                 }
//             }
//             ptr_e++;
//         }
//         // is_sol == 1이면 ptr_s 뒤로 하나씩 밀면서
//         else if (is_sol == 1 && s[ptr_s] != '\0') {
//             tmp_char = s[ptr_s] >= 'A' && s[ptr_s] <= 'Z' ? s[ptr_s] - 'A' : s[ptr_s] - 'a' + 26;
//             if (t_cnts[tmp_char]) {
//                 s_cnts[tmp_char]--;
//                 // 현재 ptr_s~ptr_e가 sol인지 판단
//                 is_sol = 1;
//                 for (int i = 0; i < 52; i++) {
//                     if (s_cnts[i] < t_cnts[i]) {is_sol = 0; break;}
//                 }
//             }
//             ptr_s++;
//         }
        
//         // is_sol = true인 경우 min_sol 췤
//         if (is_sol && min_len > ptr_e - ptr_s + 1) {
//             min_len = ptr_e - ptr_s + 1;
//             ret_e = ptr_e;
//             ret_s = ptr_s;
//         }
        
//         // ptr_s, ptr_e 둘다 끝에 가면 나가기
//         if (is_sol == 0 && s[ptr_e] == '\0') break;
//     }
//     if (ret_e == -1) {
//         ret_s = ptr_e; ret_e = ptr_e;
//     }
//     s[ret_e] = '\0';
//     return s + ret_s;
// }
