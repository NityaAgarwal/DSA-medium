//https://leetcode.com/problems/sum-of-two-integers/description/

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int temp = (a & b) << 1;
            a = a^b; //step 1 - equivalent to adding but without carry
            b = temp; //step 2 - equivalent to carry
        }
        return a;
    }
};
