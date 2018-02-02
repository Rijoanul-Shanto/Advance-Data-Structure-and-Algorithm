///Rijoanul Hasan

#include <bits/stdc++.h>
#define endl '\n'
#define IN freopen("input.in", "rt", stdin);
#define OUT freopen("output.and", "wt", stdout);
#define PF printf
#define SF scanf
#define SF1(a) scanf("%d", &a)
#define SF2(a, b) scanf("%d %d", &a, &b)
#define SF3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define FOR(a, b, c) for(int i = a; i < b; i += c)
#define TC int t;scanf("%d", &t);while(t--)
#define WHO(a) printf("This is %d", a);
#define DB printf("Debug\n");
const int MAX = 100000;
using namespace std;

int arr[MAX], tree[MAX*3];

void update(int node, int l, int r, int n, int key)
{
    //DB
    if(r < n or l > n) return;
    if(r == n and l == n)
    {
        tree[node] = key;
        return;
    }

    int mid = (l+r) / 2;
    int left = node * 2;
    int right = left + 1;

    update(left, l, mid, n, key);
    update(right, mid+1, r, n, key);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int l, int r, int p, int q)
{
    if(l > q or r < p) return 0;
    if(l >= p and r <= q) return tree[node];

    int left = node * 2;
    int right = left + 1;
    int mid = (l+r) / 2;

    int sum1 = query(left, l, mid, p, q);
    int sum2 = query(right, mid+1, r, p, q);

    return sum1 + sum2;
}

void create(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = arr[l];
        return;
    }

    int mid = (l+r) / 2, left = node * 2, right = node * 2 + 1;

    create(left, l, mid);
    create(right, mid+1, r);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;
    while(cin >> n)
    {
        FOR(1, n+1, 1) cin >> arr[i];

        create(1, 1, n);

        //FOR(1, n, 1) cout << i << ':' << tree[i*2] << ' ' << tree[i*2+1] << endl;

        cout << query(1, 1, n, 4, 7) << endl;

        update(1, 1, 7, 5, 23);

        cout << query(1, 1, n, 4, 7) << endl;
    }

    return 0;
}
