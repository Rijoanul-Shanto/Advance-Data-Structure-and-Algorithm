// Rijoanul Hasan
// Lazy Approach

#include <bits/stdc++.h>
#define FIN freopen("in.txt", "rt", stdin)
#define MAX 1000000
#define endl '\n'
using namespace std;

int arr[MAX];

int root(int n)
{
    // Finding root of n
    while(n != arr[n]) n = arr[n];

    return n;
}

bool find_UF(int p, int q)
{
    // Checking if p and q have the same root
    return (root(p) == root(q));
}
void union_UF(int p, int q)
{
    int proot = root(p);
    int qroot = root(q);

    // Conquering roots of p and q
    arr[proot] = qroot;
}

int main()
{
    FIN;

    int n, op, p, q;
    char c;
    bool res;
    // Number of maximum objects
    cin >> n;

    for(int i = 0; i < n; i++) arr[i] = i;

    // Number of operations
    cin >> op;

    while(op--)
    {
        cin >> c >> p >> q;

        if(c == 'U') union_UF(p, q);
        else
        {
            res = find_UF(p, q);
            if(res) cout << p << ' ' << q << " Connected" << endl;
            else cout << p << ' ' << q << " Not Connected" << endl;
        }
    }

    return 0;
}
