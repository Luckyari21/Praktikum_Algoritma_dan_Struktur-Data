#include <iostream>
#include "queue.h"

int main() {
    int n, k;
    std::cin >> n >> k;

    int arr[100];
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    if (k <= 0 || k > n) return 0;

    Queue q;
    init(&q);
    int sum = 0;
    bool first = true;

    for (int i = 0; i < k; i++) {
        enqueue(&q, arr[i]);
        sum += arr[i];
    }

    std::cout << sum;

    for (int i = k; i < n; i++) {
        sum -= front(&q);
        dequeue(&q);
        enqueue(&q, arr[i]);
        sum += arr[i];
        std::cout << " " << sum;
    }

    std::cout << std::endl;
    return 0;
}