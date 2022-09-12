//Runtime: 89 ms, faster than 40.19% of C++ online submissions for Max Points on a Line.
//Memory Usage: 36.5 MB, less than 5.02% of C++ online submissions for Max Points on a Line.
//nC2로 2개 점 선택해서 라인 만들면 기울기, 절편으로 유일한 직선의 방정식을 하나 얻을 수 있음.
//이 직선의 방정식을 key로 하는 hash를 통해서 count를 누적해나갈수 있음
//다만 위 hash에선 point가 key에 포함되지 않으니 check배열을 써서 중복을 방지 할 수 있음
//기울기, 절편은 double형 값인데 double 오차로 인한 error가 발생하지 않은게 약간 의아한데 hash_fn이 size_t로 만드는 과정에서 오차가 사라진건가 싶고 
//무튼 key가 좀 비효율적인 연산을 통해 만들어지는거 같아서 더 좋은 방법이 없나 궁금하네

#define inf (20001)

class Solution {
private:
    char check[45000][300];
public:
    struct Node
    {
        double slope;
        double y_intercept;
        Node(double slope, double y_intercept){
            this->slope = slope;
            this->y_intercept = y_intercept;
        }

        bool operator==(const Node& p) const {
            return slope == p.slope && y_intercept == p.y_intercept;
        }
    };

    struct hash_fn
    {
        size_t operator() (const Node& node) const
        {
            size_t h1 = hash<double>()(node.slope);
            size_t h2 = hash<double>()(node.y_intercept);

            return h1 ^ h2;
        }
    };

    int maxPoints(vector<vector<int>>& points) {
        unordered_map<Node, int, hash_fn> line_hash;
        unordered_map<Node, int, hash_fn> index_hash;
        
        //memset(check, 0, 45000*300);

        int check_count = 0;

        int max = 1;
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                Node temp{ 0,0 };
                if (points[i][0] == points[j][0]) {
                    temp.slope = inf;
                    temp.y_intercept = points[i][0];
                }
                else {
                    temp.slope = ((double)(points[j][1] - points[i][1])) / (points[j][0] - points[i][0]);
                    temp.y_intercept = ((double)(points[j][0] * points[i][1] - points[i][0] * points[j][1])) /
                        (points[j][0] - points[i][0]);
                }
                if (line_hash.count(temp) == 0) {
                    line_hash[temp] = 2;
                    index_hash[temp] = check_count;
                    check[check_count][i] = 1;
                    check[check_count][j] = 1;
                    check_count++;
                    if (max < 2)
                        max = 2;
                }
                else {
                    if (check[index_hash[temp]][j] == 0) {
                        check[index_hash[temp]][j] = 1;
                        int count = line_hash[temp];
                        line_hash[temp] = count + 1;
                        if (max < count + 1)
                            max = count + 1;
                    }
                }
            }
        }
        return max;
    }
};
