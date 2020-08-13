// 力扣 347. 前 K 个高频元素

// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]

// 首先统计频次，用hash
// 然后前k个最大用优先队列
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 先用hash统计频次
        unordered_map<int, int> umap;
        for (auto n : nums) umap[n]++;
        // 再优先队列得到前k个最大   存储的是<频次, 元素>，容器必须是数组类容器，小顶堆（要保留最大的）
        priority_queue<pair<int ,int>, vector<pair<int, int>>, \
                        greater<pair<int, int>>> pq;
        for (auto m : umap) {
            if (pq.size() == k) {                           // 如果队列满，则需要判断条件 频次是否大于队列中最小的
                if (m.second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(m.second, m.first));
                }
            } else {                                        // 否则，继续放就是了
                pq.push(make_pair(m.second, m.first));
            }
        }

        // 结果处理
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return vector(res.rbegin(), res.rend());            // 出列是从前到后，但是前面是最小的，所以结果需要反向
    }
};