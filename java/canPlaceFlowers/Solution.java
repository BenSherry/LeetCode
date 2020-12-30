package canPlaceFlowers;

class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int length = flowerbed.length;
        int count = n;
        if (n <= 0) {
            return true;
        }
        
        for (int i = 0; i < length && count > 0; i++) {
            if (flowerbed[i] == 0) {
                int left = (i - 1 >= 0 ? flowerbed[i - 1] : 0);
                int right = (i + 1 < length ? flowerbed[i + 1] : 0);
                if (left + right == 0) {
                    flowerbed[i] = 1;
                    count --;
                    i ++;
                }
            }
        }
        return count == 0;
    }
}