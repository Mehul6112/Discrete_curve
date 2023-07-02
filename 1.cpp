#include <iostream>
#include <set>

using namespace std;

class SET {
private:
  set<int> set;

public:
  SET() {}

  void add(int value) {
    set.insert(value);
  }

  void printPowerSet() {
    int n = set.size();
    set<set<int>> powerSet;
    for (int i = 0; i < (1 << n); i++) {
      set<int> subset;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          subset.insert(set[j]);
        }
      }
      powerSet.insert(subset);
    }

    for (auto subset: powerSet) {
      for (auto element: subset) {
        cout << element << " ";
      }
      cout << endl;
    }
  }

  void printUnion(set<int> s1, set<int> s2) {
    set<int> unionSet;
    for (auto element: s1) {
      unionSet.insert(element);
    }
    for (auto element: s2) {
      unionSet.insert(element);
    }

    for (auto element: unionSet) {
      cout << element << " ";
    }
    cout << endl;
  }

  void printIntersection(set<int> s1, set<int> s2) {
    set<int> intersectionSet;
    for (auto element: s1) {
      if (s2.find(element) != s2.end()) {
        intersectionSet.insert(element);
      }
    }

    for (auto element: intersectionSet) {
      cout << element << " ";
    }
    cout << endl;
  }

  bool isElementPresent(int element) {
    return set.find(element) != set.end();
  }

  bool isSubset(set<int> subset) {
    for (auto element: subset) {
      if (set.find(element) == set.end()) {
        return false;
      }
    }

    return true;
  }

  set<int> getComplement(set<int> universalSet) {
    set<int> complement;
    for (auto element: universalSet) {
      if (set.find(element) == set.end()) {
        complement.insert(element);
      }
    }

    return complement;
  }

  set<int> getSetDifference(set<int> s1, set<int> s2) {
    set<int> difference;
    for (auto element: s1) {
      if (s2.find(element) == s2.end()) {
        difference.insert(element);
      }
    }

    return difference;
  }

  set<int> getSymmetricDifference(set<int> s1, set<int> s2) {
    set<int> difference;

    for (auto element: s1) {
      if (s2.find(element) == s2.end()) {
        difference.insert(element);
      }
    }

    for (auto element: s2) {
      if (s1.find(element) == s1.end()) {
        difference.insert(element);
      }
    }

    return difference;
  }
};

int main() {
  SET s;
  s.add(1);
  s.add(2);
  s.add(3);

  set<int> s2 = {1,2,3,4};
  set<int> s3 = {3,4,6,7};
  set<int> uniset = {1,2,3,4,5,6,7,8,9};
    
  s.printPowerSet();

  s.printUnion(s2, s3);
  s.printIntersection(s2, s3);

  cout << s.isElementPresent(5) << endl;
  cout << s.isElementPresent(3) << endl;
    
  set<int> subset = {1,2};
  cout << s.isSubset(subset) << endl;
    
  set<int> complement = s.getComplement(uniset);

  for (auto element: complement) {
    cout << element << " ";
  }
  cout << endl;

  set<int> difference = s.getSetDifference(s2, s3);
  for (auto element: difference) {
    cout << element << " ";

  set<int> difference = s.getSymmetricDifference(s2, s3);
  for (auto element: difference) {
    cout << element << " ";

  return 0;
}
