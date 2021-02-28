#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long dp[1000001];
int main() {
  cin.tie(0);
  cout.tie(0);
  int maxval=0;
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  vector<int> arr;
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    arr.push_back(n);
    maxval = max(n,maxval);
  }
  for(int i=3;i<=maxval;i++){
    dp[i] = (dp[i - 3] % 1000000009 + dp[i - 2] % 1000000009+ dp[i - 1]% 1000000009)% 1000000009;
  }
  for(int i=0;i<arr.size();i++){
    cout << dp[arr[i]] << '\n';
  }
}