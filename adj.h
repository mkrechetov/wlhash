#ifndef ADJ_H
#define ADJ_H

#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

typedef vector<vector<int>> adj;

void zero(adj& a, int n) {
  a.clear();
  for (int i=0;i<n;i++) {
    vector<int> row = {};
    for (int j=0;j<n;j++) {row.push_back(0);}
    a.push_back(row);
  }
}

adj fromstr(string s) {
  int i=0, j=0, n=sqrt(s.size()); adj a; zero(a, n);
  for (char c: s) { a[i][j] = (int)c - 48; i++; if (i==n) {i=0;j++;} }
  return a;
}

void adjprint(adj a) {
  for (int i=0;i<a.size();i++) {
    for (int j=0;j<a.size();j++) {cout << a[i][j];}
    cout << endl;
  }
  cout << endl;
}

adj subgraph(adj a, vector<int> comb) {
  adj s; zero(s, comb.size());
  for (int i=0;i<comb.size();i++) {
    for (int j=0;j<comb.size();j++) {s[i][j] = a[comb[i]][comb[j]];}
  }
  return s;
}

#endif
