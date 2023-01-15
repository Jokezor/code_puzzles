#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>

using namespace std;

void solution(void) {
  int result = 0;
  int results[4] = {0, 0, 0, 0};
  int w, d, h;

  int L_x, L_y;
  int P_x, P_y;

  scanf("%d", &w);
  scanf("%d", &d);
  scanf("%d", &h);

  scanf("%d", &L_x);
  scanf("%d", &L_y);

  scanf("%d", &P_x);
  scanf("%d", &P_y);

  int P_x_copy = P_x;
  int P_y_copy = P_y;

  results[0] = abs(w - P_x);
  P_x = w;
  results[0] += abs(L_x - P_x) + abs(L_y - P_y) + h;

  P_x = P_x_copy;
  results[1] = P_x;
  P_x = 0;
  results[1] += abs(L_x - P_x) + abs(L_y - P_y) + h;

  P_x = P_x_copy;
  results[2] = abs(d - P_y);
  P_y = d;
  results[2] += abs(L_x - P_x) + abs(L_y - P_y) + h;

  P_y = P_y_copy;
  results[3] = P_y;
  P_y = 0;
  results[3] += abs(L_x - P_x) + abs(L_y - P_y) + h;

  int *min = std::min_element(std::begin(results), std::end(results));

  result = results[std::distance(results, min)];
  printf("%d\n", result);
}

int main(void) {
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
