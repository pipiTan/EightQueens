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
    explicit solution(int n) : n(n) {}
    int res = 0;
    void sol() {
        std::vector<Queen> queen;
        Queen q(0, 0);
        do {
            if (queen.size() == n || q.y == n) {
                q.x = queen.back().x; q.y = ++queen.back().y;
                queen.pop_back();
            }
            while (q.y < n) {
                if (std::find(queen.begin(), queen.end(), q) != queen.end()) {
                    q.y++;
                } else {
                    queen.emplace_back(q);
                    if (queen.size() == n) res++;
                    q.x++; q.y = 0;
                    break;
                }
            }
        } while (0 < q.x || q.y < n);
    }

};

int main() {
    solution s(8);
    s.sol();
    std::cout << s.res << std::endl;
    return 0;
}
