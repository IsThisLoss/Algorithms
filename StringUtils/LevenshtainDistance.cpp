#include "LevenshtainDistance.h"

#include <algorithm>
#include <numeric>
#include <vector>

/*
 * Assume that
 *
 * replace | insert  |
 * delete  | current |
 *
 * So DP table is
 *
 *     | "" | b | e | p |
 *  "" | 0  | 1 | 2 | 3 |
 *  e  | 1  | 2 | 1 | 2 |
 *  p  | 2  | 2 | 2 | 1 |
 *  h  | 3  | 3 | 3 | 2 |
 */

std::string::size_type levenshtainDistance(const std::string& lhs, const std::string& rhs) {
  using Size = std::string::size_type;

  if (lhs.empty() && rhs.empty()) {
    return 0;
  }
  if (lhs.empty()) {
    return rhs.size();
  }
  if (rhs.empty()) {
    return lhs.size();
  }

  std::vector<Size> prev_row(lhs.size());
  std::iota(prev_row.begin(), prev_row.end(), 1);
  std::vector<Size> current_row(lhs.size());

  for (Size i = 0; i < rhs.size(); i++) {
    const char rhs_ch = rhs[i];
    for (Size j = 0; j < lhs.size(); j++) {
      Size del = 0;
      Size replace = 0;
      Size insert = 0;
      if (j == 0) {
        del = i + 1;
        replace = i;
        insert = prev_row[j];
      } else {
        del = current_row[j-1];
        replace = prev_row[j-1];
        insert = prev_row[j];
      }
      Size current = 0;
      if (rhs_ch != lhs[j]) {
        current++;
      }
      current += std::min({del, replace, insert});
      current_row[j] = current;
    }
    std::swap(current_row, prev_row);
  }
  return prev_row.back();
}
