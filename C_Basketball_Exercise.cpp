/*
 * Author: Jaivardhan D Rao
 * Date: 2025-05-28 10:04
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double  long double
#define endl    '\n' 
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
#define ff      first
#define pb      push_back
#define ss      second
#define gi      greater<int>
#define vvi      vector<vector<int>>
#define vi      vector<int>
#define v      vector
#define mii      map<int , int>
#define yes     cout<<"YES"<<endl;
#define no      cout<<"NO"<<endl;
#define JaivardhanDRao      cin.tie(nullptr)->sync_with_stdio(false);
using pii = pair<int , int>;
#define uset      unordered_set<int>
#define JVR
#ifdef JVR
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__);
#else
    #define debug(...);
#endif
template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) { for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; } return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) { for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) { stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) { stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) { string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) { bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) { if (!first) { res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) { string res = ""; for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << to_string(H); debug_out(T...); }
int gcd(int a , int b){if(b == 0) return a;return gcd(b , a%b);}
int lcm(int a, int b){return (a / gcd(a, b)) * b;}
int dx[4] = {-1 , 1 , 0 , 0};
int dy[4] = {0 , 0 , 1 , -1};
const int MOD = 1e9 + 7;
const int INF = 1e6 + 1;

const bool test = 0;

vvi dp(3 , vi(1e5 + 7 , -1));


int rec(int lastArr , int idx , v<pii> &arr){
    if(idx >= arr.size()){
        return 0;
    }
    // skip

    int &ansdp = dp[lastArr][idx];
    if(ansdp != -1){
        return ansdp;
    }
    int res = rec(lastArr , idx + 1 , arr);
    int ans = 0;
    // choose upar neeche
    if(lastArr == 1){
        lastArr = 2;
        ans = arr[idx].ss + rec(lastArr , idx + 1 , arr);
    }else{
        lastArr = 1;
        ans = arr[idx].ff + rec(lastArr , idx + 1 , arr);
    }

    return ansdp = max(ans , res);
}

void solve(){
    
    int n,k; cin >> n;
    // vi arr(n); for(auto &it : arr) cin >> it;    
    // vi arr2(n); for(auto &it : arr2) cin >> it;  

    v<pii> arr(n);
    for(auto &it : arr){
        cin >> it.ff;
    }
    for(auto &it : arr){
        cin >> it.ss;
    }





    int ans1 = rec(1 , 0 , arr);
    int ans2 = rec(2 , 0 , arr);

    cout << max(ans1 , ans2) << endl;


    
    
    
}


signed main(){
    JaivardhanDRao
    int t=1;
    test && cin >> t;
    for(int i = 0; i < t; i++){
      //cout << "Case #" << i + 1 << ": " << endl;
        solve();
    }
}