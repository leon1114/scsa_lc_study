//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fraction to Recurring Decimal.
//Memory Usage: 6.4 MB, less than 9.19% of C++ online submissions for Fraction to Recurring Decimal.
//예외케이스가 많아서 뭔가 코드가 더럽네..
//실제 손으로 나누기 하는것처럼 나누기 함
//순환소수인 경우만 따로 처리해주면 되는데
//나누다가 몫 기준으로 같은 몫이 또 나오면 순환
//따라서 몫과 그 시점의 index를 hash key value로 저장하고 있다가
//똑같은 key가 나오면 괄호 추가하여 


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long long int nu = numerator;
        long long int de = denominator;
        string sol;
        string flag;
        if (nu < 0) {
            flag = "-"; nu *= -1;
        }
        if (de < 0) {
            flag = flag == "-"? "" : "-"; 
            de *= -1;
        }

        if (nu < de) {
            sol += "0";
        }
        else {
            sol += to_string(nu / de);
            nu %= de;
        }
        if (nu > 0) { 
            sol += ".";
        }
        else {
            return flag + sol;
        }
        unordered_map<int, int> hash;
        nu *= 10;
        int index = sol.length();
        while (nu > 0) {
            if (hash.count(nu) == 0)
                hash[nu] = index;
            else {
                sol = sol.substr(0, hash[nu]) + "(" + sol.substr(hash[nu]) + ")";
                return flag + sol;
            }
            if (nu < de) {
                sol += "0";
            }
            else {
                sol += to_string(nu / de);
                nu %= de;
            }
            nu *= 10;
            index++;
        }
        return flag + sol;
    }
};
