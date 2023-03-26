#include <bits/stdc++.h>

using namespace std;

int main() {

  time_t timer;
  time_t start = time(&timer);

  map<int, string> integer_dictionary = {
      {1, "one"},       {2, "two"},        {3, "three"},     {4, "four"},
      {5, "five"},      {6, "six"},        {7, "seven"},     {8, "eight"},
      {9, "nine"},      {10, "ten"},       {11, "eleven"},   {11, "eleven"},
      {12, "twelve"},   {13, "thirteen"},  {14, "fourteen"}, {15, "fifteen"},
      {16, "sixteen"},  {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
      {20, "twenty"},   {30, "thirty"},    {40, "fourty"},   {50, "fifty"},
      {60, "sixty"},    {70, "seventy"},   {80, "eighty"},   {90, "ninety"},
      {100, "hundred"}, {1000, "thousand"}};

  // I need 1-9, 10-19, 20-90, 100 - 900
  // Then the rest is a conversion from them and using and as separator.
  // When 1 <= x <= 20, just map directly.
  // 20 < x < 100, map with 10*(x/10) + x % 10
  // 100 <= x < 999, map with (x / 100) + 100  + and (x - 100*(x/100)) from the
  // previous map. x == 1000, map with x / 1000 and 1000

  // Simply put, make a conversion from number to string.

  time_t end = time(&timer);

  printf("took %.f seconds\n", difftime(end, start));

  return 0;
}
