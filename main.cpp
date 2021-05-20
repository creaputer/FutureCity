#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9
#define MAX_N 100

int N, M;
int graph[MAX_N + 1][MAX_N + 1];
int K, X;

int main() {
  freopen("input.txt", "r", stdin);
  
  cin >> N >> M;
  
  for (int i = 1 ; i <= (MAX_N+1); ++i) {
    // fill_n(graph[i], N+1, INF);
    fill(graph[i], graph[i] +(MAX_N+1), INF);
  }
  
  for (int i = 1 ; i <= N; ++i) {
    graph[i][i] = 0;
  }
  
  for (int i = 1 ; i <= M ; ++i) {
    int a, b;
    cin >> a >> b;
    
    graph[a][b] = 1;
    
    graph[b][a] = 1;
  }
  
  cin >> X >> K;
  
  for (int k = 1; k <= N ; ++k) {
    for (int a = 1 ; a <= N ; ++a) {
      for (int b = 1 ; b <= N ; ++b) {
        
        graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
      }
    }
  }
  
  int ret = graph[1][K] + graph[K][X];
  if (ret >= INF) {
    ret = -1;
  }
  
  cout << ret << endl;
  
}