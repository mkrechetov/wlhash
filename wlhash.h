#ifndef WLHASH_H
#define WLHASH_H

#include <vector>
#include <string>
#include <algorithm>

// for wl hash
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

// for graphs
#include "adj.h"

using namespace std;

string sha256(const string str){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

string wlhash(adj a, int iterations) {
  vector<string> labels, new_labels, adj_labels;
  for (int i=0;i<a.size();i++) {labels.push_back("1");}

  for (int k=0;k<3;k++) {
    new_labels.clear();

    for (int i=0;i<a.size();i++) {
      adj_labels.clear();
      adj_labels.push_back(labels[i]);
      for (int j=0;j<a.size();j++) {
        if (a[i][j]) { adj_labels.push_back(labels[j]); }
      }
      sort(adj_labels.begin(),adj_labels.end());

      new_labels.push_back("");
      for (const auto &piece : adj_labels) new_labels[i] += piece;
      new_labels[i] = sha256(new_labels[i]);
    }

    labels = new_labels;
  }

  // final step
  adj_labels.clear();
  for (int i=0;i<a.size();i++) {
    adj_labels.push_back(labels[i]);
    sort(adj_labels.begin(),adj_labels.end());
    labels[0] = "";
    for (const auto &piece : adj_labels) labels[0] += piece;
  }
  return sha256(labels[0]);
}

#endif
