#include <vector>

namespace canPlaceFlowers {
class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        if (n <= 0) {
            return true;
        }
        int count = n;

        for (int i = flowerbed[0]; i < flowerbed.size() && count > 0; i++) {
            if (flowerbed[i] == 0) {
                int left = i - 1 >= 0 ? flowerbed[i - 1] : 0;
                int right = i + 1 < flowerbed.size() ? flowerbed[i + 1] : 0;
                if (left + right == 0) {
                    count --;
                    i++;
                }
            }
        }
        return count == 0;
    }
};
}