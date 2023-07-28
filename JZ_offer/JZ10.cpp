class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int Fibonacci(int n) {
        // write code here
        if(n == 0){
            return 0;
        }else if(n==1){
            return 1;
        }
        else{
            int f0 = 0;
            int f1 = 1;
            for(int i=2; i<=n; i++){
                int temp = f0 + f1;
                f0 = f1;
                f1 = temp;
            }
            return f1;
        }
    }
};