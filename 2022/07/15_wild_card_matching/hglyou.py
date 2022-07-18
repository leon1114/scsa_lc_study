class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False for _ in range(len(s) + 1)] for _ in range(len(p) + 1)]
        
        # base case
        dp[0][0] = True

        for p_i in range(1, len(p) + 1):
            pattern = p[p_i - 1]

            start_idx = 1
            if pattern == '*':
                while not dp[p_i-1][start_idx -1] and start_idx < len(s) + 1:
                    start_idx += 1
                dp[p_i][start_idx - 1] = dp[p_i-1][start_idx-1]

            for s_i in range(start_idx, len(s) + 1):
                if pattern == '*':
                    dp[p_i][s_i] = True
                else:
                    if dp[p_i-1][s_i-1]:
                        if pattern == "?":
                            dp[p_i][s_i] = True
                        else:
                            dp[p_i][s_i] = pattern == s[s_i-1]

                        
        return dp[len(p)][len(s)]
