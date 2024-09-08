class Solution {
public:
struct hash_pair {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// long long findTargetSumWays(int n, vector<int>& arr, int d) {
    
    int findTargetSumWays(vector<int>& arr, int d) {
        int n=arr.size();
         int mod = 1e9 + 7;
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    
    if ((total + d) % 2 != 0)
        return 0;

    int s1 = (total + d) / 2;
    unordered_map<pair<int, int>, int, hash_pair> mp;

    mp[{0, 0}] = 1;
    if (arr[0] == 0) mp[{0, 0}] = 2;
    else mp[{0, arr[0]}] = 1;

    for (int i = 1; i < n; i++) {
        for (int a = s1; a >= 0; a--) {  // Reverse loop to avoid overwriting
            int notTake = mp[{i - 1, a}];
            int take = (arr[i] <= a) ? mp[{i - 1, a - arr[i]}] : 0;
            mp[{i, a}] = (take + notTake) % mod;
        }
    }

    return mp[{n - 1, s1}];
}
    
};