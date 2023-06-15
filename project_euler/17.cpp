#include <bits/stdc++.h>
#include <time.h>

using namespace std;

string get_singles(int m, map<int, string> integer_dictionary) {
  return integer_dictionary[m];
}

string get_teens(int m, map<int, string> integer_dictionary) {
  string number = "";
  number += integer_dictionary[m - m % 10];
  number += integer_dictionary[m % 10];

  return number;
}

int main() {

  // I need 1-9, 10-19, 20-90, 100 - 900
  // Then the rest is a conversion from them and using and as separator.
  // When 1 <= x <= 20, just map directly.
  // 20 < x < 100, map with 10*(x/10) + x % 10
  // 100 <= x < 999, map with (x / 100) + 100  + and (x - 100*(x/100)) from the
  // previous map. x == 1000, map with x / 1000 and 1000

  // Simply put, make a conversion from number to string.
  // Or you can think of how many times you need to cover the range of numbers.

  int start = clock();

  map<int, string> integer_dictionary = {
      {1, "one"},        {2, "two"},       {3, "three"},     {4, "four"},
      {5, "five"},       {6, "six"},       {7, "seven"},     {8, "eight"},
      {9, "nine"},       {10, "ten"},      {11, "eleven"},   {12, "twelve"},
      {13, "thirteen"},  {14, "fourteen"}, {15, "fifteen"},  {16, "sixteen"},
      {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"},
      {30, "thirty"},    {40, "forty"},    {50, "fifty"},    {60, "sixty"},
      {70, "seventy"},   {80, "eighty"},   {90, "ninety"},   {100, "hundred"},
      {1000, "thousand"}};

  int x = 1000;
  int res = 0;

  for (int i = 1; i <= 1000; i++) {
    string number = "";

    if (i <= 20) {
      number += get_singles(i, integer_dictionary);
    }
    if (i > 20 && i < 100) {
      number += get_teens(i, integer_dictionary);
    }
    if (i >= 100 && i <= 999) {
      number += integer_dictionary[i / 100];
      number += integer_dictionary[100];
      int tens = (i - 100 * (i / 100));
      if (tens)
        number += "and";
      if (tens <= 20) {
        number += get_singles(tens, integer_dictionary);
      } else {
        number += get_teens(tens, integer_dictionary);
      }
    }
    if (i == 1000) {
      number += integer_dictionary[x / 1000];
      number += integer_dictionary[i];
    }

    res += number.length();
    cout << number << ": " << number.length() << "\n";
  }
  cout << res << "\n";

  int end = clock();

  printf("took %d ms\n", (end - start) / 1000);

  return 0;
}
