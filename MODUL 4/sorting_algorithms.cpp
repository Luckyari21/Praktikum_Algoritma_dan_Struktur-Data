#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            m.comparisons++;
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
            }
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            m.comparisons++;
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(data[i], data[min_idx]);
            m.swaps++;
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            m.comparisons++;
            data[j + 1] = data[j];
            m.shifts++;
            j--;
        }
        if (j >= 0) m.comparisons++;

        data[j + 1] = key;
        m.shifts++;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void merge_helper(std::vector<int>& data, int left, int right, Metrics& m) {
    m.recursive_calls++;
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_helper(data, left, mid, m);
    merge_helper(data, mid + 1, right, m);

    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        m.comparisons++;
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }
    while (i <= mid) temp[k++] = data[i++];
    while (j <= right) temp[k++] = data[j++];

    for (int x = 0; x < k; x++) {
        data[left + x] = temp[x];
    }
}

void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    merge_helper(data, 0, (int)data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


int partition(std::vector<int>& data, int low, int high, Metrics& m) {
    int mid = low + (high - low) / 2;
    int pivot = data[mid];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        m.comparisons++;
        if (data[j] <= pivot) {
            i++;
            std::swap(data[i], data[j]);
            m.swaps++;
        }
    }

    std::swap(data[i + 1], data[high]);
    m.swaps++;
    return i + 1;
}

void quick_helper(std::vector<int>& data, int low, int high, Metrics& m) {
    m.recursive_calls++;
    if (low >= high) return;

    int pi = partition(data, low, high, m);
    quick_helper(data, low, pi - 1, m);
    quick_helper(data, pi + 1, high, m);
}

void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    quick_helper(data, 0, (int)data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int n = data.size();
    int max_val = *std::max_element(data.begin(), data.end());

    std::vector<int> output(n);
    std::vector<int> count(10);

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        std::fill(count.begin(), count.end(), 0);

        for (int i = 0; i < n; i++) {
            int digit = (data[i] / exp) % 10;
            count[digit]++;
            m.array_accesses++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = (data[i] / exp) % 10;
            output[--count[digit]] = data[i];
            m.array_accesses += 2;
        }
        for (int i = 0; i < n; i++) {
            data[i] = output[i];
            m.array_accesses++;
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}