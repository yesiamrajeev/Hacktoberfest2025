#include <bits/stdc++.h>
using namespace std;

/*
 * Mo's Algorithm for Offline Queries
 * ---------------------------------
 * It answers multiple range queries on an array efficiently by sorting queries in a special order.
 * Time Complexity: O((N + Q) * sqrt(N))
 *
 * Example: Given array arr[], and queries [L, R], return sum of elements in that range.
 */

struct Query {
    int L, R, idx;
};

// Block size for sorting queries
int block;

bool compare(Query a, Query b) {
    if (a.L / block != b.L / block)
        return a.L / block < b.L / block;
    return a.R < b.R;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q; // input size of array and number of queries

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].L--; queries[i].R--; // 0-based indexing
        queries[i].idx = i;
    }

    block = sqrt(n);
    sort(queries.begin(), queries.end(), compare);

    vector<long long> ans(q);
    long long currSum = 0;
    int currL = 0, currR = -1;

    for (auto query : queries) {
        int L = query.L, R = query.R;

        // expand range
        while (currR < R) currSum += arr[++currR];
        while (currR > R) currSum -= arr[currR--];
        while (currL < L) currSum -= arr[currL++];
        while (currL > L) currSum -= arr[--currL];

        ans[query.idx] = currSum;
    }

    for (long long res : ans) cout << res << "\n";

    return 0;
}
