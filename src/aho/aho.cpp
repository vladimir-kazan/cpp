#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <queue>
#include <tuple>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;
using std::queue;
using std::tuple;
using std::get;

class Node;
typedef map<char, Node*> NodesMap;
typedef tuple<int, string> SearchResult;
typedef vector<SearchResult> SearchResults;

class Node {
  public:
    
    string name;
    NodesMap go;
    vector<string> out;
    Node *fail;
  
    Node(Node *failNode = NULL): fail(failNode) {
    }
};

class Aho {
  public:
    Node root;

    Aho() {
      root.name = "Root";
    }

    void addString(const string & str) {
      Node * current_node = & this->root;
  
      for (int i = 0; i < str.size(); i += 1) {
        const char & c = str[i];
        if (!current_node->go.count(c)) {
          Node * child = new Node();
          child->name = c;
          current_node->go[c] = child;
          current_node = child;
        } else {
          current_node = current_node->go[c];
        }
      }
      current_node->out.push_back(str);
    }

    void prepare() {
      // Build state-machine
      
      /* 1. Init 1-st level children of the root node.
       */
      queue<Node*> nodeQueue;
      for (NodesMap::iterator it = root.go.begin(); it != root.go.end(); it++) {
        nodeQueue.push(it->second);
        it->second->fail = & this->root;
      }

      /** 2. Init other nodes, find longest suffix to fail.
       *     If not found then set to the root node.
       */
      while (nodeQueue.size() > 0) {
        Node * rnode = nodeQueue.front();
        nodeQueue.pop();

        for (NodesMap::iterator it = rnode->go.begin(); it != rnode->go.end(); it++) {
          Node * unode = it->second;
          nodeQueue.push(unode);
          Node * fnode = rnode->fail;
          while (fnode != 0 && !fnode->go.count(it->first)) { 
            fnode = fnode->fail;
          }
          if (fnode != 0) {
            unode->fail = fnode->go[it->first];
          } else {
            unode->fail = & this->root;
          }
          unode->out.insert(unode->out.end(), unode->fail->out.begin(), unode->fail->out.end());

        }
      }
    }

    SearchResults findAll(const string & str) {
      SearchResults list;
      Node * node = & this->root;
      for(int i = 0; i < str.size(); i += 1) {
        const char & c = str[i];
        while (node != 0 && !node->go.count(c)) {
          node = node->fail;
        }
        if (node == 0) {
          node = & this->root;
          continue;
        }
        node = node->go[c];
        for (string & pattern : node->out) {
          list.push_back(make_tuple(i - pattern.size() + 1, pattern));
        }
      }
      return list;
    }
};

string join(const std::vector<std::string>& elements, const char* const separator)
{
    switch (elements.size())
    {
        case 0:
            return "";
        case 1:
            return elements[0];
        default:
            std::ostringstream os; 
            std::copy(elements.begin(), elements.end()-1, std::ostream_iterator<std::string>(os, separator));
            os << *elements.rbegin();
            return os.str();
    }
}


void printDebug(Node & node, int offset = 0) {
  cout << string(offset, '-') + "> " << node.name << ", out: [" << join(node.out, ", ") << "]";
  cout << ", go: [";
  for (NodesMap::iterator it = node.go.begin(); it != node.go.end(); it++) {
    cout << it->second->name;
    if (node.go.end() != next(it)) {
      cout << ", ";
    }
  }
  cout << "]" << (node.fail ? ", fail to -> " + node.fail->name : "") << endl;
  for (NodesMap::iterator it = node.go.begin(); it != node.go.end(); it++) {
    if (it == node.go.begin()) {
      offset += 2;
    }
    printDebug(*it->second, offset);
  }
}

int main() {
  cout << "Aho-Corasick Demo" << endl << endl;
  Aho aho;

  // aho.addString("ab");
  // aho.addString("abcd");
  // aho.addString("azz");
  // aho.prepare();
  // print(aho.root);
  // SearchResults results = aho.findAll("caaab");

  aho.addString("a");
  aho.addString("ab");
  aho.addString("abc");
  aho.addString("bc");
  aho.addString("c");
  aho.addString("cba");
  aho.prepare();
  
  SearchResults results = aho.findAll("abcba");

  // printDebug(aho.root);

  for (SearchResult item : results) {
    int i = get<0>(item);
    cout << "Found \"" << get<1>(item) << "\" at pos. " << i << endl;
  }

  return 0;
}


