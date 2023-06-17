#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main() {

  clock_t start = clock();

  //
  // 1 jan 1900 was a Monday.
  // that means we should count up the days until 1 Jan 1901
  // In order to know what day it starts with.
  // 1900 is not divisible by 400.
  // Which means there's 365 days.
  // 365 = 52*7 + 1
  // So 1 Jan 1901 was a tuesday.
  int day_of_week = 1;  // 0 - 6 (day % 7)
  int day_of_month = 0; // 0-days_per_month.
  int month = 1;        // 1 - 12
  int year = 1901;      // 1901-2000
  int sundays_on_first = 0;

  while (year <= 2000) {
    day_of_week = (day_of_week + 1) % 7;
    day_of_month++;

    int days_per_month = 31;

    if (month == 9 || month == 4 || month == 6 || month == 11) {
      days_per_month = 30;
    } else if (month == 2) {
      days_per_month = 28;
      if (year % 4 == 0 && year % 100) {
        days_per_month = 29;
      }
      if (year % 400 == 0) {
        days_per_month = 29;
      }
    }
    if (day_of_month == days_per_month) {
      month++;
      day_of_month = 0;
    }
    if (month == 13) {
      year++;
      month = 1;
    }
    if (day_of_week == 6 && day_of_month == 0) {
      sundays_on_first++;
    }
    cout << "date: " << year << month << day_of_month << " is a " << day_of_week
         << "\n";
  }

  cout << sundays_on_first << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
