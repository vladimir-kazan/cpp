#include <iostream>
#include <vector>
#include <string>

#define push push_back
#define pop pop_back

using namespace std;

typedef vector<int> vi;

vi current;

void find(const vi& set, int k = 0) {
    if (k == set.size()) {
        cout << '[';
        for (auto& item : current) {
            cout << item;
            cout << (&item != &current.back() ? ", ": "");
        }
        cout << ']' << endl;
    } else {
        current.push(set[k]);
        find(set, k + 1);
        current.pop();
        find(set, k + 1);
    }
}
int main() {
    cout << "Find all combinations:" << endl;
    vi set{1, 2, 3};
    find(set);
    return 0;
}
