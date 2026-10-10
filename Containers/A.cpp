#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Stack
{
private:
    vector<int> items;
    int len = 0;

public:
    void push(int n) 
    {
        this->items.push_back(n);
        this->len++;
        cout << "ok\n";
    }

    void pop() 
    {
        if (this->len > 0) {
            cout << this->items.back() << "\n";
            this->items.pop_back();
            this->len--;
        } else {
            cout << "error\n";
        }
    }

    void back() 
    {
        if (this->len > 0) {
            cout << this->items.back() << "\n";  
        } else {
            cout << "error\n";
        }
    }

    void size() {cout << this->len << "\n";}

    void clear() 
    {
        this->items.clear();
        this->len = 0;
        cout << "ok\n";
    }

    void exit() 
    {
        cout << "bye\n";
        std::exit(0);
    }
};

int main()
{
    Stack stack;
    string line;
    vector<string> vec;
    while(getline(cin, line)) {
        vec.push_back(line);
    }

    for (int i = 0; i < vec.size(); i++) {
        line = vec[i];
        if (line == "pop") {
            stack.pop();
        } else if (line == "back") {
            stack.back();
        } else if (line == "size") {
            stack.size();
        } else if (line == "clear") {
            stack.clear();
        } else if (line == "exit") {
            stack.exit();
        } else {
            stringstream stream(line);
            int num;
            stream >> line;
            stream >> num;
            stack.push(num);
        }
    }
}