class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que; // list 的底层实现是链表 插入操作比较方便
        int len = people.size();
        for(int i=0; i<len; i++){
            int pos = people[i][1];
            std::list<vector<int>>::iterator it = que.begin();
            while (pos--) {
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};