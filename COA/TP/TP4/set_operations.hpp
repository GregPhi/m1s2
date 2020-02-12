#include <vector>

std::vector<int> set_intersection(const std::vector<int> &s, const std::vector<int> &b);
std::vector<int> set_union(const std::vector<int> &s, const std::vector<int> &b);

void set_intersect(std::vector<int>::const_iterator a_begin,
                   std::vector<int>::const_iterator a_end,
                   std::vector<int>::const_iterator b_begin,
                   std::vector<int>::const_iterator b_end,
                   std::back_insert_iterator<std::vector<int>> c_begin)
{
  // TO DO
}
