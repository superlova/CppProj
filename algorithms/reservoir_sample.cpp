#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int binary_search(vector<int> nums, int target) {
    int left = -1, right = nums.size();
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid;
        else right = mid;
    }
    if (right == nums.size() || nums[right] != target) return -1;
    else return right;
}

int main() {
    srand((unsigned)time(NULL));

    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int target = 0;
    cin >> target;
    int pivot = binary_search(nums, target);
    int count = 0, res = 0;
    while (nums[pivot] == target) {
        if (rand()%(count+1) == count) res = nums[pivot + count];
        
        ++count;
    }
    cout << res << endl;
    system("PAUSE");
    return 0;
}