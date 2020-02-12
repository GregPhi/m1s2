#include "set_operations.hpp"

using namespace std;

vector<int> set_intersection(const vector<int> &s, const vector<int> &b){
  vector<int> res;
  int size_s = s.size();
  int size_b = b.size();

  for(int i = 0; i < size_s; i++){
    for(int j = 0; j < size_b; j++){

    }
  }
  return res;
}

vector<int> set_union(const vector<int> &s, const vector<int> &b){
  vector<int> res;
  res = s;
  for(int i = 0; i < b.size(); i++){
    if(res[i] != b[i]){
      res.push_back(b[i]);
    }
  }
  return res;
}
