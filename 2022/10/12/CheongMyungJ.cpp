//Runtime: 22 ms, faster than 71.28% of C++ online submissions for Flatten Nested List Iterator.
//Memory Usage: 13.1 MB, less than 73.95% of C++ online submissions for Flatten Nested List Iterator.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> _inner;
    int _size;
    int _cur;
    void initialize(vector<NestedInteger>& nestedList){
        for (int i = 0; i < nestedList.size(); i++){
            if (nestedList[i].isInteger()){
                _inner.push_back(nestedList[i].getInteger());
            }
            else{
                initialize(nestedList[i].getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        _inner.clear();
        initialize(nestedList);
        _size = _inner.size();
        _cur = 0;
    }
    
    int next() {
        int ret = _inner[_cur++];
        return ret;
    }
    
    bool hasNext() {
        return _cur < _size;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
