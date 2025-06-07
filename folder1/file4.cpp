#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

#define VALMAX 1000005
constexpr ll mod = 1000000007;

ll add(ll a, ll b) { return (a + b) % mod; }
ll sub(ll a, ll b) { return (a - b + mod) % mod; }
ll mul(ll a, ll b) { return (a * 1LL * b) % mod; }
ll add(ll a, ll b, ll mod1) { return (a + b) % mod1; }
ll sub(ll a, ll b, ll mod1) { return (a - b + mod1) % mod1; }
ll mul(ll a, ll b, ll mod1) { return (a * 1LL * b) % mod1; }

ll binSearch(vector<ll> &v, ll l, ll r, ll val) {
    while(l <= r) {
        ll mid = l + (r-l)/2;
        if (v[mid] == val) return mid;
        else if (v[mid] > val) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

ll binExp(ll x, ll n) {
    ll ans = 1LL;
    while(n > 0) {
        if (n & 1) ans = mul(ans,x);
        x = mul(x,x);
        n >>= 1;
    }
    return ans;
}

ll binExp(ll x, ll n, ll mod1) {
    ll ans = 1LL;
    while(n > 0) {
        if (n & 1) ans = mul(ans,x, mod1);
        x = mul(x,x, mod1);
        n >>= 1;
    }
    return ans;
}

ll inv(ll a) { return binExp(a, mod - 2) % mod; }
ll inv(ll a, ll mod1) { return binExp(a, mod1 - 2) % mod1; }

ll divi(ll a, ll b) { return (a * 1LL * inv(b)) % mod; }
ll divi(ll a, ll b, ll mod1) { return (a * 1LL * inv(b, mod1)) % mod1; }

vector<ll> fact;

vector<ll> calcMobius(ll N) {
    vector<ll> mobius(N,0);
    mobius[1] = -1;
    for (ll i = 1; i < N; i++) {
        if (mobius[i]) {
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j < N; j += i) { mobius[j] += mobius[i]; }
        }
    }
    return mobius;
}

vector<ll> precomputefactorial(ll N) {
    vector<ll> res(N,1);
    for (ll i=2;i<N;i++) {
        res[i] = mul(i,res[i-1]);
    }
    return res;
}

ll BinomialCoefficient(ll a, ll b) {
    if ((a < 0) || (b < 0)) return 0;
    if (a == 0) {
        if (b == 0) return 1;
        return 0;
    } 
    if (a < b) return 0;
    ll numerator = fact[a];
    ll denominator = mul(fact[b], fact[a-b]);
    return divi(numerator, denominator);
}

vector<vector<ll>> matMul(vector<vector<ll>> &a, vector<vector<ll>> &b, ll size) {
    vector<vector<ll>> res(size,vector<ll>(size,0));
    for (ll i=0;i<size;i++) {
        for (ll j=0;j<size;j++) {
            for (ll k=0;k<size;k++) {
                res[i][j] =  add(res[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return res;
}

vector<vector<ll>> matExp(vector<vector<ll>> &a, ll size, ll n) {
    if (n == 0) {
        vector<vector<ll>> temp(size, vector<ll>(size,0));
        for (ll i=0;i<size;i++) temp[i][i] = 1;
        return temp;
    }
    vector<vector<ll>> res = matExp(a,size, n/2);
    res = matMul(res,res, size);
    if (n % 2) return matMul(a,res, size);
    return res;
}

ll mex(unordered_set<ll> &s) {
    ll ans = 0;
    while(s.find(ans) != s.end()) ans++;
    return ans;
}