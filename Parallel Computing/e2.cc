//
// Zeyu Chen
//

#include <vector>
#include "e2.h"

#define MIN(num1, num2) ((num1 < num2) ? num1 : num2)
#define MAX(num1, num2) ((num1 > num2) ? num1 : num2)


template<typename  It, typename T>
Solution<It, T>::Solution() {
    min = 0;
    sum = 0;
    max = 0;
}

template<typename  It, typename T>
Solution<It, T>::~Solution() {
}

template <typename It, typename T>
void Solution<It,T>::iterate (It head, int num) {
    int i;
    long sum_t;
    It ptr = head;
    T min_t, max_t;

    sum_t = 0;
    min_t = *head;
    max_t = *head;

    for (i = 0;i < num; ++i, ++ptr) {
        T temp = *ptr;
        sum_t += temp;
        max_t = MAX(temp, max_t);
        min_t = MIN(temp, min_t);
    }

    sum = sum_t;
    min = min_t;
    max = max_t;

    return;
}

template <typename It, typename T>
long Solution<It,T>::Show_Sum() {
    return sum;
}

template <typename It, typename T>
T Solution<It,T>::Show_Max() {
    return max;
}

template <typename It, typename T>
T Solution<It,T>::Show_Min() {
    return min;
}

//// Sum
//template <typename It, typename T>
//T Solution<It,T>::Sum (T* res, int num) {
//    T* tmp = res;
//    T sum = 0;
//
//    for (int i = 0; i < num; ++i, ++tmp)
//        sum += *tmp;
//
//    return sum;
//}
//
//// Max
//template <typename It, typename T>
//T Solution<It,T>::Max  (T* res, int num) {
//    T* tmp = res;
//    T max = *res;
//
//    for (int i = 0; i < num; ++i, ++tmp)
//        max = ((*tmp) > max) ? (*tmp) : max;
//
//    return max;
//}
//
//// Min
//template <typename It, typename T>
//T Solution<It,T>::Min (T* res, int num) {
//    int* tmp = res;
//    T min = *res;
//
//    for (int i = 0; i < num; ++i, ++tmp)
//        min = ((*tmp) < min) ? (*tmp) : min;
//
//    return min;
//}

