#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>

class BKTree {
  public:
    BKTree();

    void insert(const std::string& str);

    std::vector<std::string> find(const std::string& str, const int threshold) const;
  private:
    struct Node;
    using NodePtr = std::unique_ptr<Node>;

    struct Node {
      std::string word;
      std::map<int, NodePtr> edges;
    };

    NodePtr root;

    static void insert(NodePtr& root, const std::string& str);
    static void find(const NodePtr& root, const std::string& str, const int threshold, std::vector<std::string>& result);
};
