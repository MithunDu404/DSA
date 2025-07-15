// Geeta's River Crossing
// Geeta wants to cross a river that has no bridge. She finds several logs floating in the water, tied together at their left ends but with their right ends free. The logs are of different lengths and are arranged parallel to each other. Geeta can only jump from the right end of one log to another, but the logs are slippery, so she must be careful with her jumps.

// Jumping Constraints:
// Geeta can jump at most X steps to her left.
// Geeta can jump at most Y steps to her right.
// If the distance to the next log exceeds her jumping capacity, she must turn back toward her starting position.
// Her priority is to reach the opposite bank, but if that's impossible, she will return to her starting position.

// Task:
// Write a program that calculates the number of jumps Geeta makes before reaching either the opposite bank or her starting position.

// Input Format:
// The first line contains three integers separated by spaces:
// N: Number of logs (1 ≤ N ≤ 1000)
// X: Maximum left jump distance (0 ≤ X ≤ 1000)
// Y: Maximum right jump distance (0 ≤ Y ≤ 1000)
// The second line contains N integers separated by spaces, representing the lengths of the logs (each length ≥ 1).

// Output Format:
// A single integer representing the total number of jumps Geeta makes.

// Sample Input 1:
// 5 3 5
// 1 6 5 4 1
// Sample Output 1:
// 6
// Explanation:
// Geeta starts at the bank and jumps to the first log (1 jump).
// She then jumps to the second log (distance 5, within her right jump capacity).
// She continues jumping to subsequent logs as long as the distances are within her X and Y limits.
// If she cannot proceed further, she turns back toward the starting position.
// The total jumps in this case are 6.

// Sample Input 2:
// 5 1 5
// 1 6 5 4 1
// Sample Output 2:
// 8
// Explanation:
// With a left jump capacity of only 1, Geeta cannot jump left as far as in the first example, requiring more jumps to navigate the logs.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,l,r;cin>>n>>l>>r;
    vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];

    vector<int> d(n+1); d[0] = a[0];
    for(int i=1;i<n;i++) d[i] = a[i]-a[i-1];
    d[n] = -a[n-1];

    for(int i=0;i<=n;i++){
        if(d[i] < 0){
            if(d[i] < -l){
                cout<<i*2<<endl;
                return 0;
            }
        }
        else if(d[i] > 0){
            if(d[i] > r){
                cout<<i*2<<endl;
                return 0;
            }
        }
    }
    cout<<n+1<<endl;
}