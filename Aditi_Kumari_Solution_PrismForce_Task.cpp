/*
Name: Aditi Kumari
Language: C++

I have used recursion to check every possible combination. At every level, we make three different calls:
- To check if we proceed without using any ability
- TO check the outcome when we use power to skip this level
- to check the outcome if we choose to regenerate Abhimanyu

Also after we have crossed levels 3, and 7 we add the energy of regenerated enemies to next level

The Worst case TC of the Recursive solution is: O(3^n), n is number of circles 
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int initialPower;

bool willAbhimanyuWin(int index, int power, int skip, int heal, vector<int>& k) {
    if (power < 0) return false;

    if (index == k.size()) return power >= 0;

    bool possible = false;

    // Normal progression
    possible = willAbhimanyuWin(index + 1, power - k[index], skip, heal, k);

    // Regenerate enemies at circle 3 and 7
    if ((index == 2 || index == 6) && index + 1 < k.size()) {
        k[index + 1] += k[index] / 2;
    }

    // Skip the current battle
    if (skip > 0) {
        possible = possible || willAbhimanyuWin(index + 1, power, skip - 1, heal, k);
    }

    // Heal
    if (heal > 0) {
        possible = possible || willAbhimanyuWin(index, initialPower, skip, heal - 1, k);
    }

    return possible;
}

void solve() {
    int n, p, a, b;
    cin >> n >> p >> a >> b;

    vector<int> k(n, 0);

    for(int i = a; i < n; i++)
        cin >> k[i];
    
    initialPower = p;

    bool canDeafeat = willAbhimanyuWin(0, p, a, b, k);

    cout << "Result: " << (canDeafeat ? "Won" : "Lost");
}

int main() {

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}


/* ************************************************************************************
TC 1:

1
7 100 2 1
10 20 30 40 50 60 70

There are 7 circles.
Abhimanyu starts with 100 power.
He has 2 skips and 1 heal.
Enemies' powers are [10, 20, 30, 40, 50, 60, 70].

Output: Won

------------------------------------------------------
TC 2: 
1
7 60 1 1
10 20 30 40 50 60 70

There are 7 circles.
Abhimanyu starts with 60 power.
He has 1 skip and 1 heal.
Enemies' powers are [10, 20, 30, 40, 50, 60, 70].

Output: Lost

------------------------------------------------------
TC 3:
1
11 150 2 2
10 20 30 40 50 60 70 80 90 100 110

There are 11 circles.
Abhimanyu starts with 150 power.
He has 2 skips and 2 heals.
Enemies' powers are [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110].

Output: Won


**********************************************************************************************/


