// Rijoanul Hasan
// Eager Approach

#include <bits/stdc++.h>
#define MAX 10000000
#define FIN freopen("in.txt", "rt", stdin)
#define FOUT freopen("out.txt", "wt", stdout)
#define endl '\n'
using namespace std;

int arr[MAX];

bool find_UF(int p, int q)
{
    return (arr[p] == arr[q]);
}

void union_UF(int p, int q)
{
    int pid = arr[p];
    int qid = arr[q];
    for(int i = 0; i < 100; i++)
    {
        // q is the parent of p
        // so change the index of all element
        // who have same index vaule of p
        // change to q
        if(arr[i] == pid) arr[i] = qid;
    }
    /*
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    */
}

int main()
{
    FIN;

    int n, op, p, q;
    bool res;
    char c;
    // Number of maximum objects
    cin >> n;

    // Initilize array
    for(int i = 0; i < n; i++) arr[i] = i;

    // Number of operations
    cin >> op;

    while(op--)
    {
        // C || U --> union_UF() and F --> find_UF()
        cin >> c >> p >> q;

        if(c == 'U') union_UF(p, q);
        else
        {
            res = find_UF(p, q);
            if(res) cout << p << ' ' << q << " Connected" << endl;
            else cout << p << ' ' << q << " Not Connected" << endl;
        }
    }

    /*
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    */


    return 0;
}
