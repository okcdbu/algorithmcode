#include <iostream>
#include <algorithm>
using namespace std;
int p[1001],dp[1001],n;
void init(){
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> p[i];
  }
}
int find(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      dp[i] = max(dp[i],dp[i-j] + p[j]);
    }
  }
  return dp[n];
}
void answer(){
  cout << find() << '\n';
}
int main() {
  init();
  answer();
}