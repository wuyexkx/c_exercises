
// 先排序，
// 然后取中间的元素key，
// 再遍历对key计数，
// 再判断是否超过一半。
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int count = 0;
        int key = numbers[numbers.size() / 2];
        for (int i=0; i<numbers.size(); i++) {
            if (numbers[i] == key) {
                count++;
            }
        }
        return count > numbers.size() / 2 ? key : 0;
    }
};


// 一次遍历找频次最高的元素key，
// 再次遍历对key计数，
// 最后判断是否超过一半。
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 1;
        int key = numbers[0];
        for (int i=1; i<numbers.size(); i++) {
            numbers[i] == key ? count++ : count--;
            if (count < 0) {
                count = 1;
                key = numbers[i];
            }
        }

        count = 0;
        for (int i=0; i<numbers.size(); i++) {
            if (numbers[i] == key) {
                count++;
            }
        }

        return (count > numbers.size() / 2 ? key : 0);
    }
};