
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Custom hash function to hash std::array<int, 26>
        auto arrayHash = [](const std::array<int, 26>& arr) {
            std::size_t seed = 0;
            for (int i : arr) {
                seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        };

        // Hash map mapping frequency array -> list of anagram strings
        std::unordered_map<std::array<int, 26>, std::vector<std::string>, decltype(arrayHash)> res(0, arrayHash);

        for (const std::string& s : strs) {
            std::array<int, 26> count = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            res[count].push_back(s);
        }

        std::vector<std::vector<std::string>> output;
        output.reserve(res.size());
        for (auto& pair : res) {
            output.push_back(std::move(pair.second));
        }

        return output;
    }
};