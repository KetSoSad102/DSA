#include<bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

#define ll long long
#define ull unsigned long long
#define str string
#define db double
#define vl vector<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define FOR(i,a,b) for(int i = (int)a; i<=(int)b; ++i)
#define ROF(i,a,b) for(int i = (int)a; i>=(int)b; i--)
#define rep(a, x) for(auto& a : x)
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define __lcm(a, b) (1ll * ((a) / __gcd((a), (b))) * (b))

// BITMASKS
#define BIT(x, i) (((x) >> (i)) & 1) 
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define BTO1(x, i) (x | (1 << i))
#define BTO0(x, i) (x & ~(1 << i))  
#define BSWP(x, i) (x ^ (1 << i))
#define INDEX(i, j)  ((i) * c + (j))

const ll MOD = 998244353;
const ll INF = 1e18+10;
const int maxn = 1e6+1000;
const ll base = 31;
const int LOG = 19;

void MergePart(vector<int>& arr, int low, int mid, int high) {
    int i = low, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= high)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[low + k] = temp[k];
}

void MergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    MergePart(arr, low, mid, high);
}

void process() 
{  
    ifstream inputFile("input.inp");
    vector<vector<int>> arrs;
    string line;

    // Read Input
    while (getline(inputFile, line)) {
        int n = stoi(line), num;
        vector<int> arr;

        if (getline(inputFile, line)) {
            stringstream ss(line);
            while (ss >> num)
                arr.push_back(num);
        }

        arrs.push_back(arr);
    }

    inputFile.close();

    // Sort and Check Time
    for (int i = 0; i < arrs.size(); i++) {
        auto start = high_resolution_clock::now();
        MergeSort(arrs[i], 0, arrs[i].size() - 1);
        auto end = high_resolution_clock::now();

        duration<double> exec_time = end - start;
        cout << "Array " << i + 1 << " (Sorted in " << exec_time.count() << " seconds)" << endl;
    }
}   
int main()
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin); 
    freopen("output.out", "w", stdout);
    // #else 
    // freopen("abba.inp", "r", stdin); 
    // freopen("abba.out", "w", stdout);
    #endif
    // freopen("DAYCON.inp", "r", stdin); 
    // freopen("DAYCON.out", "w", stdout);
    IOS;
    // ll t;
    // cin>>t;
    // while(t--)
    process();

    // cout << setprecision(3) << fixed;
    // cout << "[" << 1.0 * clock() / CLOCKS_PER_SEC << "s]  \n";
}