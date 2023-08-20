class Solution {
public:
    int getSum(int a, int b) {
        while(b){          
            int temp = a ^ b;
            unsigned int c = (unsigned int) (a & b) << 1;
            a = temp;
            b = c;
        }
        return a;
    }
};