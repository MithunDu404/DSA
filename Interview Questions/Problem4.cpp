// Problem Statement
// You're given an N×N chessboard with K knights and R rooks. You need to determine if it's possible to place all these pieces on the board such that none of them attack each other.
// Piece Movement Rules

// Knight: Moves in an "L-shape" - 2 squares in one direction and 1 square perpendicular to that. It only captures the piece it lands on.
// Rook: Moves any number of squares horizontally or vertically. It captures any piece in its path.

// Goal
// Determine if you can place all K knights and R rooks on the N×N board without any piece threatening another.
// Input/Output Format

// Input: Three integers - N (board size), K (number of knights), R (number of rooks)
// Output: "YES" if possible to place all pieces safely, "NO" if impossible

// Sample Test Cases
// Test Case 1: N=1, K=1, R=1
// Output: NO
// Explanation: On a 1×1 board, you can only place one piece, but you have 2 pieces total.

// Test Case 2: N=5, K=3, R=2
// Output: YES
// Explanation: On a 5×5 board, it's possible to arrange 3 knights and 2 rooks so none attack each other


#include <iostream>
using namespace std;

int main() {
    int n,k,r;cin>>n>>k>>r;
    if(r > n) {
        cout<<"NO"<<endl;
        return 0;
    }
    
    int remainingSize = n-r;
    
    // Maximum knights that can be placed in remaining area
    int maxKnights = (remainingSize * remainingSize + 1) / 2;
    
    // Check if we can place K knights
    if (k <= maxKnights) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}