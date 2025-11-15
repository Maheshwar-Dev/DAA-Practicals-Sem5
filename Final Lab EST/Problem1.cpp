// Problem 1 : Leetcode 378 (Kth Smallest Element in a Sorted Matrix)

class Solution {
public:
   int countLessEqual(vector<vector<int>>& matrix, int mid) {
    int n = matrix.size();
    int m = matrix[0].size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    }
    return cnt;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    int low = matrix[0][0];
    int high = matrix[n - 1][m - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int cnt = countLessEqual(matrix, mid);

        if (cnt < k) 
            low = mid + 1;
        else 
            high = mid;
    }
    return low;
}

};
