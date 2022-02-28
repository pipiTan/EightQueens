#include <iostream>
#include "vector"
class Queen {
public:
    int x, y;
    Queen(int x, int y) : x(x), y(y) {}

    bool operator==(Queen q) const {
        if (x == q.x || y == q.y) return true;
        if (x - y == q.x - q.y || x + y == q.x + q.y) return true;
        return false;
    }
};


class solution {
    int n;
public:
    solution(int n) : n(n) {}
    int res = 0;
    void sol() {
        std::vector<Queen> queen;
        int x = 0, y = 0;
        queen.emplace_back(Queen(0, 0));
        y++;
        while (queen.size() <= n) {
            while (x < n) {
                if (std::find(queen.begin(), queen.end(), Queen(x, y)) != queen.end()) {
                    x++;
                } else {
                    queen.emplace_back(Queen(x, y));
                    y++; x = 0;
                    break;
                }
            }
            if (x == n) {
                y--; x = queen.back().x + 1;
                queen.pop_back();
            }
            if (queen.size() == n) {
                res++;
                y--; x = queen.back().x + 1;
                queen.pop_back();
            }
            if (x == n && y == 0) return;

        }
    }

};

int main() {
    solution s(8);
    s.sol();
    std::cout << s.res << std::endl;
    return 0;
}
