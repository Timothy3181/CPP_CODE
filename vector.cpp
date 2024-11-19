#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
        Solution(vector<int> arr)
        {
            for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
                cout << *it << " ";
            } //普通迭代器
            cout << endl;
            for (vector<int>::const_iterator cit = arr.cbegin(); cit != arr.cend(); ++cit) {
                cout << *cit << " ";
            } //常量迭代器
            cout << endl;
            for (vector<int>::reverse_iterator rit = arr.rbegin(); rit != arr.rend(); ++rit) {
                cout << *rit << " ";
            } //反向迭代器
            cout << endl;
            for (const auto& a : arr) {
                cout << a << " ";
            }
            cout << endl;
            for (size_t i = 0; i < arr.size(); i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        Solution(vector<int> arr, int n)
        {
            cout << arr.at(2) << endl;
            cout << arr.size() << endl;
            cout << arr.capacity() << endl;
            auto rt = find(arr.begin(), arr.end(), 100);
            cout << *rt << endl;
            if (rt == arr.end()) {
                cout << "cannot find" << endl;
            }
            else {
                cout << "found, the place is:arr[" << distance(arr.begin(), rt) << "]" << endl;
            }
        }
};

vector<int> arr;
int n;

int main()
{
    cin >> n;
    arr.reserve(n);
    for (int i = 0; i < n; i++) {
        arr.emplace_back(i);
    }
    arr.insert(arr.begin() + 2, 100);
    arr.erase(arr.begin() + 1);
    Solution solution = Solution(arr);
    Solution solution2 = Solution(arr, 1);
}