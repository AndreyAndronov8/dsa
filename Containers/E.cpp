#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Deque 
{
private:
    vector<int> items;
    int len = 0;
public:
    void push_front(int n) {
        this->items.insert(this->items.begin(), n);
        this->len++;
        cout << "ok\n";
    }

    void push_back(int n) {
        this->items.push_back(n);
        this->len++;
        cout << "ok\n";
    }

    void pop_front() {
        if (this->len > 0) {
            cout << this->items.front() << "\n";
            this->items.erase(this->items.begin());
            this->len--;
        } else {
            cout << "error\n";
        }
    }

    void pop_back() {
        if (this->len > 0) {
            cout << this->items.back() << "\n";
            this->items.pop_back();
            this->len--;
        } else {
            cout << "error\n";
        }
    }

    void front() {
        if (this->len > 0) {
            cout << this->items.front() << "\n";
        } else {
            cout << "error\n";
        }
    }

    void back() {
        if (this->len > 0) {
            cout << this->items.back() << "\n";
        } else {
            cout << "error\n";
        }
    }

    void size() {
        cout << this->len << "\n";
    }

    void clear() {
        this->items.clear();
        this->len = 0;
        cout << "ok\n";
    }

    void exit() {
        cout << "bye\n";
        std::exit(0);
    }
};

int main()
{
    vector<string> lines;
    string line;
    Deque q;

    while (getline(cin, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++) {
        line = lines[i];
        if (line == "pop_front") {
            q.pop_front();
        } else if ((line == "pop_back")) {
            q.pop_back();
        } else if (line == "front") {
            q.front();
        } else if (line == "back") {
            q.back();
        } else if (line == "size") {
            q.size();
        } else if (line == "clear") {
            q.clear();
        } else if (line == "exit") {
            q.exit();
        } else {
            stringstream stream(line);
            int num;
            stream >> line;
            stream >> num;
            if (line == "push_back") {
                q.push_back(num);
            } else {
                q.push_front(num);
            }
        }
    }
}