#include "BKTree.h"

#include "LevenshtainDistance.h"

namespace StringUtils {

BKTree::BKTree()
  : root{nullptr}
{}


void BKTree::insert(NodePtr& root, const std::string& str) {
  if (!root) {
    root = std::make_unique<Node>();
    root->word = str;
    return;
  }
  const int dist = levenshtainDistance(root->word, str);
  if (dist == 0) {
    // drop dublicates
    return;
  }
  auto it = root->edges.find(dist);
  if (it != root->edges.end()) {
    insert(it->second, str);
    return;
  }
  auto newNode = std::make_unique<Node>();
  newNode->word = str;
  root->edges[dist] = std::move(newNode);
}

void BKTree::find(const NodePtr& root, const std::string& str, const int threshold, std::vector<std::string>& result) {
  if (!root) {
    return;
  }

  const int dist = levenshtainDistance(root->word, str);
  if (dist <= threshold) {
    result.push_back(root->word);
  }

  auto it = root->edges.lower_bound(dist - threshold);
  for (; it != root->edges.end() && it->first <= dist + threshold; it++) {
    find(it->second, str, threshold, result);
  }
}

void BKTree::insert(const std::string& str) {
  insert(root, str);
}
    
std::vector<std::string> BKTree::find(const std::string& str, const int threshold) const {
  std::vector<std::string> result;
  find(root, str, threshold, result);
  return result;
}

}
