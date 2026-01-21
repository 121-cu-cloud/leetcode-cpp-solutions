#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> indexMap;

    for (int i = 0; i < nums.size(); i++) {
        if (indexMap.count(nums[i])) {
            if (i - indexMap[nums[i]] <= k) {
                return true;
            }
        }
        indexMap[nums[i]] = i;
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    bool result = containsNearbyDuplicate(nums, k);
    cout << "Contains Nearby Duplicate: " << (result ? "true" : "false") << endl;

    return 0;
}
