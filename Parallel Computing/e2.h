//
// Zeyu Chen
//

#ifndef E2_E2_H
#define E2_E2_H


// Suppose 8 threads to work, iterate seprately. Then merge the result.
// Each thread has a solution, merge in the main

template <typename It, typename T>
class Solution {
    T min;
    T max;
    double sum;
public:
    Solution();
    ~Solution();
// iterator
    void iterate (It head, int num);

//// Sum
//    T Sum (T* res, int num);
//
//// Max
//    T Max (T* res, int num);
//
//// Min
//    T Min  (T* res, int num);

// Return sum
    long Show_Sum();
// Return sum
    T Show_Max();
// Return sum
    T Show_Min();
};
#endif //E2_E2_H