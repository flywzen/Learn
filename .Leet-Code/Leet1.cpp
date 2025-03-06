class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         int n = grid.size();
        int total = n * n;
        vector<int> freq(total + 1, 0); // Frequency array from 0 to total

        // Count occurrences of each number in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = grid[i][j];
                freq[num]++;
            }
        }

        int a = -1, b = -1;
        for (int i = 1; i <= total; ++i) {
            if (freq[i] == 2) {
                a = i;
            } else if (freq[i] == 0) {
                b = i;
            }
        }

        return {a, b};
    }
};
