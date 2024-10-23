#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <future>
#include <thread> // 包含sleep_for
#include <chrono> // 包含chrono_literals
#include <deque>
#include <time.h>
#include <random>
using namespace std;



#include <iostream>
#include <algorithm>

void CardOrder(int A[], int B[], int nLen) {
    int i = 0, j = 0, k = 0;
    while (i < nLen && j < nLen) {
        if (A[i] < B[j]) {
            std::swap(A[k], A[i]);
            i++;
        } else {
            std::swap(A[k], B[j]);
            j++;
        }
        k++;
        if (k < nLen) {
            if (A[i] < B[j]) {
                std::swap(B[k], A[i]);
                i++;
            } else {
                std::swap(B[k], B[j]);
                j++;
            }
            k++;
        }
    }
    while (i < nLen) {
        std::swap(A[k], A[i]);
        i++;
        k++;
        if (k < nLen) {
            std::swap(B[k], A[i]);
            i++;
            k++;
        }
    }
    while (j < nLen) {
        std::swap(A[k], B[j]);
        j++;
        k++;
        if (k < nLen) {
            std::swap(B[k], B[j]);
            j++;
            k++;
        }
    }
}

int main() {
    int A[] = {2, 7, 9, 9, 10};
    int B[] = {1, 3, 6, 6, 7};
    int nLen = sizeof(A) / sizeof(A[0]);

    CardOrder(A, B, nLen);

    std::cout << "A = {";
    for (int i = 0; i < nLen; ++i) {
        std::cout << A[i];
        if (i < nLen - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;

    std::cout << "B = {";
    for (int i = 0; i < nLen; ++i) {
        std::cout << B[i];
        if (i < nLen - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;

    return 0;
}



