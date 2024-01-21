#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>

#include <map>
template <typename K, typename V> class interval_map {
  friend void IntervalMapTest();
  V m_valBegin;

public:
  // constructor associates whole range of K with val
  interval_map(V const &val) : m_valBegin(val) {}
  std::map<K, V> m_map;

  // Assign value val to interval [keyBegin, keyEnd).
  // Overwrite previous values in this interval.
  // Conforming to the C++ Standard Library conventions, the interval
  // includes keyBegin, but excludes keyEnd.
  // If !( keyBegin < keyEnd ), this designates an empty interval,
  // and assign must do nothing.
  void assign(K const &keyBegin, K const &keyEnd, V const &val) {
    // Empty range, do nothing.
    if (!(keyBegin < keyEnd)) {
      return;
    }

    // Lookup current value at end.
    auto endVal = (*this)[keyEnd];

    // Erase existing entries in interval
    auto itlow = m_map.lower_bound(keyBegin);
    auto ithi = m_map.upper_bound(keyEnd);

    m_map.erase(itlow, ithi);

    // Check if the value is already covered.
    bool hasValBegin = (*this)[keyBegin] == val;

    // Revalidate iterators after erase in map.
    itlow = m_map.lower_bound(keyBegin);
    ithi = m_map.upper_bound(keyEnd);

    // Only assign if not the default, as its already covering the range.
    if ((val != m_valBegin || itlow != m_map.begin()) && !hasValBegin) {
      // Assign beginning of interval with val
      m_map.emplace_hint(itlow, keyBegin, val);
    }

    // Mark the end of this interval
    if ((endVal != m_valBegin || ithi != m_map.begin()) && endVal != val) {
      m_map.emplace_hint(ithi, keyEnd, endVal);
    }
  }

  // look-up of the value associated with key
  V const &operator[](K const &key) const {
    auto it = m_map.upper_bound(key);
    if (it == m_map.begin()) {
      return m_valBegin;
    } else {
      return (--it)->second;
    }
  }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

template <class A, class B>
std::ostream &operator<<(std::ostream &out, const std::map<A, B> &a) {
  std::string output = "";
  for (auto p : a) {
    output += "{";
    output += ", ";
    output += p.second;
    output += "}, ";
  }
  return out << output + "\n";
};

template <class A, class B>
std::ostream &operator<<(std::ostream &out, const interval_map<A, B> &a) {
  return out << a.m_map;
};

// int main() {
//
//   interval_map<int, char> m{'C'};
//
//   std::cout << m << "\n";
//
//   m.assign(0, 5, 'A');
//
//   std::cout << m << "\n";
//
//   m.assign(2, 4, 'B');
//
//   std::cout << m << "\n";
//
//   m.assign(0, 5, 'E');
//
//   std::cout << m << "\n";
//
//   return 0;
// }

struct TestKeyType {
  unsigned int val;
  constexpr TestKeyType(unsigned int val) : val(val) {}
  constexpr bool operator<(const TestKeyType &other) const {
    return val < other.val;
  }
};

namespace std {
template <> class numeric_limits<TestKeyType> {
public:
  static constexpr TestKeyType lowest() {
    return TestKeyType(numeric_limits<unsigned int>::lowest());
  }
  // static constexpr TestKeyType lowest() { return TestKeyType(-250); }
};
}; // namespace std

using TestValueType = char;

struct TestFloatKeyType {
  float val;

  TestFloatKeyType() = default;

  TestFloatKeyType(float val) : val(val) {}
  bool operator<(TestFloatKeyType other) const {
    return other.val - val > 1.e-4f;
  }
};

namespace std {
template <> class numeric_limits<TestFloatKeyType> {
public:
  static TestFloatKeyType lowest() {
    return TestFloatKeyType(numeric_limits<float>::lowest());
  }
};
}; // namespace std

TEST_CASE("EmptyRange") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(3, 3, 'B');
  REQUIRE(m.m_map.count(3) == 0);

  m.assign(3, 2, 'B');
  REQUIRE(m.m_map.count(2) == 0);
  REQUIRE(m.m_map.count(3) == 0);
}

TEST_CASE("MyExample") {
  interval_map<int, char> m('C');
  REQUIRE(m[0] == 'C');
  m.assign(0, 5, 'A');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[4] == 'A');
  REQUIRE(m[5] == 'C');
  REQUIRE(m[-1] == 'C');
  m.assign(2, 4, 'B');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[4] == 'A');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[5] == 'C');
  REQUIRE(m[-1] == 'C');
  m.assign(0, 5, 'E');
  REQUIRE(m[0] == 'E');
  REQUIRE(m[4] == 'E');
  REQUIRE(m[5] == 'C');
  REQUIRE(m[-1] == 'C');
}

TEST_CASE("TrivialRange") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 10, 'B');
  REQUIRE(m[0] == 'A');
  for (int i = 1; i < 10; i++) {
    REQUIRE(m[i] == 'B');
  }
  REQUIRE(m[10] == 'A');
}

TEST_CASE("TrivialTwoRange") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 3, 'B');
  m.assign(6, 8, 'C');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'B');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[3] == 'A');
  REQUIRE(m[4] == 'A');
  REQUIRE(m[5] == 'A');
  REQUIRE(m[6] == 'C');
  REQUIRE(m[7] == 'C');
  REQUIRE(m[8] == 'A');
}

TEST_CASE("OverwriteLowest") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(std::numeric_limits<TestKeyType>::lowest(), 10000, 'B');
  REQUIRE(m[0] == 'B');
  REQUIRE(m[9999] == 'B');
  REQUIRE(m[10000] == 'A');
}

TEST_CASE("Negative") {
  interval_map<int, char> m('A');
  m.assign(-1000, 10, 'B');
  REQUIRE(m[-1001] == 'A');
  REQUIRE(m[-1000] == 'B');
  REQUIRE(m[0] == 'B');
  REQUIRE(m[10] == 'A');
}

TEST_CASE("Merge") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(std::numeric_limits<TestKeyType>::lowest(), 10, 'B');
  m.assign(10, 20, 'B');
  REQUIRE(m[0] == 'B');
  REQUIRE(m[10] == 'B');
  REQUIRE(m[19] == 'B');
  REQUIRE(m[20] == 'A');
}

TEST_CASE("FloatKey") {
  interval_map<TestFloatKeyType, TestValueType> m('A');
  m.assign(1.f, 5.f, 'B');
  REQUIRE(m[0.f] == 'A');
  REQUIRE(m[.999999999f] == 'B');
  REQUIRE(m[1.f] == 'B');
  REQUIRE(m[4.999f] == 'B');
  REQUIRE(m[5.f] == 'A');
}

TEST_CASE("OverlappingRangeComplete") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(3, 5, 'B');
  m.assign(1, 6, 'C');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'C');
  REQUIRE(m[2] == 'C');
  REQUIRE(m[3] == 'C');
  REQUIRE(m[4] == 'C');
  REQUIRE(m[5] == 'C');
  REQUIRE(m[6] == 'A');
}

TEST_CASE("OverlappingRangeInner") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 6, 'C');
  m.assign(3, 5, 'B');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'C');
  REQUIRE(m[2] == 'C');
  REQUIRE(m[3] == 'B');
  REQUIRE(m[4] == 'B');
  REQUIRE(m[5] == 'C');
  REQUIRE(m[6] == 'A');
}

TEST_CASE("OverlappingRangeSmallToLarge") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 5, 'B');
  m.assign(3, 6, 'C');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'B');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[3] == 'C');
  REQUIRE(m[4] == 'C');
  REQUIRE(m[5] == 'C');
  REQUIRE(m[6] == 'A');
}

TEST_CASE("OverlappingRangeLargeToSmall") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(3, 6, 'C');
  m.assign(1, 5, 'B');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'B');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[3] == 'B');
  REQUIRE(m[4] == 'B');
  REQUIRE(m[5] == 'C');
  REQUIRE(m[6] == 'A');
}

TEST_CASE("ExtendingRangeBegin") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(3, 5, 'B');
  m.assign(1, 4, 'B');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'B');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[3] == 'B');
  REQUIRE(m[4] == 'B');
  REQUIRE(m[5] == 'A');
}

TEST_CASE("ExtendingRangeEnd") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 5, 'B');
  m.assign(3, 6, 'B');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'B');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[3] == 'B');
  REQUIRE(m[4] == 'B');
  REQUIRE(m[5] == 'B');
  REQUIRE(m[6] == 'A');
}

TEST_CASE("ExtendingRangeBothBeginEnd") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(2, 3, 'B');
  m.assign(1, 5, 'B');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'B');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[3] == 'B');
  REQUIRE(m[4] == 'B');
  REQUIRE(m[5] == 'A');
}

TEST_CASE("OverwriteEndValueSafety") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(2, 5, 'B');
  m.assign(5, 8, 'C');
  m.assign(4, 5, 'A');
}

TEST_CASE("ReusingExistingRangeBothBeginEnd") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 5, 'B');
  m.assign(2, 3, 'B');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'B');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[3] == 'B');
  REQUIRE(m[4] == 'B');
  REQUIRE(m[5] == 'A');
}

TEST_CASE("ReusingEnd") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 5, 'B');
  m.assign(4, 6, 'A');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'B');
  REQUIRE(m[2] == 'B');
  REQUIRE(m[3] == 'B');
  REQUIRE(m[4] == 'A');
  REQUIRE(m[5] == 'A');
}

TEST_CASE("RestoringInitial") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 5, 'B');
  m.assign(1, 5, 'A');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'A');
  REQUIRE(m[2] == 'A');
  REQUIRE(m[3] == 'A');
  REQUIRE(m[4] == 'A');
  REQUIRE(m[5] == 'A');
}

TEST_CASE("RestoringInitial2") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(1, 5, 'B');
  m.assign(0, 7, 'A');
  REQUIRE(m[0] == 'A');
  REQUIRE(m[1] == 'A');
  REQUIRE(m[2] == 'A');
  REQUIRE(m[3] == 'A');
  REQUIRE(m[4] == 'A');
  REQUIRE(m[5] == 'A');
}

TEST_CASE("VeryComplex") {
  interval_map<TestKeyType, TestValueType> m('A');
  m.assign(3, 6, 'B');
  m.assign(2, 5, 'C');
  m.assign(4, 7, 'A');

  REQUIRE(m[1] == 'A');
  REQUIRE(m[2] == 'C');
  REQUIRE(m[3] == 'C');
  REQUIRE(m[4] == 'A');
  REQUIRE(m[5] == 'A');
  REQUIRE(m[6] == 'A');
  REQUIRE(m[7] == 'A');
}
