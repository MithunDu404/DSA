// Avish's Candy Factory (Optimization Problem)
// Context: Avish runs a candy factory that produces different varieties of candy. Each variety produces a different number of candies per batch. A merchant wants to order candies with specific constraints.
// Problem Statement:

// Avish produces different candy varieties in batches
// Each batch of a variety produces a specific number of candies
// The merchant wants at least 2 varieties of candy
// Each variety must have the same quantity (k candies per box)
// Avish wants to maximize total candies delivered
// He won't send partial boxes (no leftover candies)

// Goal: Find the optimal value of k (candies per box) that maximizes total candies delivered.
// Constraints:

// 2 ≤ N ≤ 10^6 (number of varieties)
// 1 ≤ Candies per batch ≤ 10^7

// Input Format:
// First line: N (number of varieties)
// Second line: N space-separated integers (candies per batch for each variety)

// Output Format:
// Single integer: maximum number of candies that can be delivered

// Sample Input 1:
// N (Number of varieties): 3
// Candies per batch: [2, 3, 6]
// Expected Output: 6

// Sample Input 2:
// N (Number of varieties): 5
// Candies per batch: [3, 8, 4, 6, 12]
// Expected Output: 12

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    map<int, int> frequency;
    vector<int> candies(n); 
    int maxi = 0;

    for(int i=0;i<n;i++){
        cin>>candies[i];
        frequency[candies[i]]++;
        maxi = max(maxi, candies[i]);
    }
 
    long long ans = 0;
    for(int k=1;k<=maxi;k++){
        int count = 0;
        for(int mul=k;mul<=maxi;mul+=k)
            count += frequency[mul];   
        
        ans = max(ans, (long long)count * k);
    }
    cout << ans << endl;
}