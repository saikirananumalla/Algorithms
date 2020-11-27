// C++ program for the above approach
 
#include <bits/stdc++.h>

using namespace std;
 
// Function to find the maximum size
// of matrix with sum <= K

void findMaxMatrixSize(vector<vector<int> > arr, int K)
{
 

    int i, j;
 

    // N size of rows and M size of cols

    int n = arr.size();

    int m = arr[0].size();
 

    // To store the prefix sum of matrix

    int sum[n + 1][m + 1];
 

    // Create Prefix Sum

    for (int i = 0; i <= n; i++) {
 

        // Traverse each rows

        for (int j = 0; j <= m; j++) {
 

            if (i == 0 || j == 0) {

                sum[i][j] = 0;

                continue;

            }
 

            // Update the prefix sum

            // till index i x j

            sum[i][j] = arr[i - 1][j - 1] + sum[i - 1][j]

                        + sum[i][j - 1] - sum[i - 1][j - 1];

        }

    }
 

    // To store the maximum size of

    // matrix with sum <= K

    int ans = 0;
 

    // Traverse the sum matrix

    for (i = 1; i <= n; i++) {
 

        for (j = 1; j <= m; j++) {
 

            // Index out of bound

            if (i + ans - 1 > n || j + ans - 1 > m)

                break;
 

            int mid, lo = ans;
 

            // Maximum possible size

            // of matrix

            int hi = min(n - i + 1, m - j + 1);
 

            // Binary Search

            while (lo < hi) {
 

                // Find middle index

                mid = (hi + lo + 1) / 2;
 

                // Check whether sum <= K

                // or not

                // If Yes check for other

                // half of the search

                if (sum[i + mid - 1][j + mid - 1]

                        + sum[i - 1][j - 1]

                        - sum[i + mid - 1][j - 1]

                        - sum[i - 1][j + mid - 1]

                    <= K) {

                    lo = mid;

                }
 

                // Else check it in first

                // half

                else {

                    hi = mid - 1;

                }

            }
 

            // Update the maximum size matrix

            ans = max(ans, lo);

        }

    }
 

    // Print the final answer

    cout << ans << endl;
}
 
// Driver Code

int main()
{

    vector<vector<int> > arr;
 

    arr = { { 1, 1, 3, 2, 4, 3, 2 },

            { 1, 1, 3, 2, 4, 3, 2 },

            { 1, 1, 3, 2, 4, 3, 2 } };
 

    // Given target sum

    int K = 4;
 

    // Function Call

    findMaxMatrixSize(arr, K);

    return 0;
}