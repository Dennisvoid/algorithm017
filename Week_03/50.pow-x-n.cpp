/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double Pow(double x, long int n) {//n>=0
        if (x == 1.0) return 1.0;
        if (n == 0) return 1.0; //boudary case

        //the logic for this level

        //drill down
        double small_problem_result = Pow(x,n / 2);

        //combine
        if (n % 2 != 0) {
            return small_problem_result * small_problem_result * x;
        }
        else 
            return small_problem_result * small_problem_result;
        //reverse
    } 
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / Pow(x,-long(n));
        }
        else return Pow(x,n);
    }
};
// @lc code=end

