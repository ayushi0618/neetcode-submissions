#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<std::string> seen;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];
                if (val == '.') continue;

                std::string rowKey = "row" + std::to_string(r) + "_" + val;
                std::string colKey = "col" + std::to_string(c) + "_" + val;
                std::string boxKey = "box" + std::to_string((r / 3) * 3 + (c / 3)) + "_" + val;

                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                    return false;
                }

                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }
        return true;
    }
};