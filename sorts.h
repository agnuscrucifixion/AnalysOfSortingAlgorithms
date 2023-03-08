#include <vector>
#include <chrono>


int64_t selectSort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int min, k;
    for (int i = 0; i < v.size(); ++i) {
        min = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (i != min) {
            k = v[i];
            v[i] = v[min];
            v[min] = k;
        }

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}
int64_t bubbleSort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int t;
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = 0; j < v.size() - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}
int64_t bubbleSortWithAiverson1(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < v.size(); ++i) {
        bool memory;
        for (int j = 0; j < v.size() - 1; ++j) {
            if (v[j] > v[j + 1]) {
                memory = true;
                std::swap(v[j], v[j + 1]);
            }
        }
        if (!memory) {
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}
int64_t bubbleSortWithAiverson2(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int ls = static_cast<int>(v.size() - 1);
    int k;
    for (int i = 0; i < v.size(); ++i) {
        k = ls;
        ls = 0;
        for (int j = 0; j < k; ++j) {
            if (v[j] > v[j + 1]) {
                ls = j;
                std::swap(v[j], v[j + 1]);
            }
        }
        if (ls == 0) {
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}

int64_t insertionSort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int m,l;
    int k;
    for (m = 0; m < v.size(); ++m) {
        k = v[m];
        for (l = m - 1; l >= 0 && v[l] > k ; l--) {
            v[l + 1] = v[l];
        }
        v[l + 1] = k;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}

int64_t binaryInsertionSort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int x, l, right, mid;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] > v[i]) {
            x = v[i];
            l = 0;
            right = i - 1;
            do {
                mid = (l + right) / 2;
                if (v[mid] < x) {
                    l = mid + 1;
                } else {
                    right = mid - 1;
                }
            } while (l <= right);
            for (int j = i - 1; j >= l; j--) {
                v[j + 1] = v[j];
            }
            v[l] = x;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}
int64_t countingSort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int maximum = -1000;
    int pos = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > maximum) {
            maximum = v[i];
        }
    }
    std::vector<int> result(maximum + 1, 0);
    for (int i = 0; i < v.size(); ++i) {
        ++result[v[i]];
    }
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i]; ++j) {
            v[pos++] = i;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}

void merge(std::vector<int>& data, size_t left, size_t mid, size_t right) {
    std::vector<int> L(data.begin() + left, data.begin() + mid + 1);
    std::vector<int> R(data.begin() + mid + 1, data.begin() + right + 1);
    size_t i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            ++i;
        } else {
            data[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < L.size()) {
        data[k] = L[i];
        ++i;
        ++k;
    }
    while (j < R.size()) {
        data[k] = R[j];
        ++j;
        ++k;
    }
}
 void mergeS(std::vector<int>& v, size_t left, size_t right) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    if (left >= right) {
        return;
    }
    size_t mid = left + (right - left) / 2;
    mergeS(v, left, mid);
    mergeS(v, mid + 1, right);
    merge(v, left, mid, right);
}
int64_t mergeSort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int l = 0;
    int r = static_cast<int>(v.size() - 1);
    mergeS(v, l, r);
    auto end = std::chrono::high_resolution_clock::now();
    auto rr = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return rr.count();
}
int partition(std::vector<int>& v, int l, int r)
{
    int k = l + 1;
    int x = r;
    int pivot = v[l];
    while (true) {
        while (k <= x && v[k] <= pivot) {
            k++;
        }
        while (k <= x && v[x] >= pivot) {
            x--;
        }
        if (k <= x) {
            std::swap(v[k], v[x]);
        } else {
            break;
        }
    }
    std::swap(v[l], v[x]);
    return x;
}

void preQuick(std::vector<int>& v, int l, int r) {
    if (l < r) {
        int index = partition(v, l, r);
        preQuick(v, l, index - 1);
        preQuick(v, index + 1, r);
    }
}

int64_t quicksort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int l = 0;
    int r = static_cast<int>(v.size()) - 1;
    preQuick(v, l, r);
    auto end = std::chrono::high_resolution_clock::now();
    auto d = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return d.count();
}
void heap(std::vector<int>& v, int n, int root) {
    int big = root;
    int left_child = 2 * root + 1;
    int right_child = 2 * root + 2;
    if (right_child < n && v[right_child] > v[big]) {
        big = right_child;
    }
    if (left_child < n && v[left_child] > v[big]) {
        big = left_child;
    }
    if (root != big) {
        int swap = v[root];
        v[root] = v[big];
        v[big] = swap;
        heap(v, n, big);
    }
}
int64_t heapSort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = static_cast<int>(v.size() / 2 - 1); i >= 0; i--) {
        heap(v, static_cast<int>(v.size()), i);
    }
    for (int i = static_cast<int>(v.size() - 1); i >= 0; i--) {
        int swap = v[0];
        v[0] = v[i];
        v[i] = swap;
        heap(v, i, 0);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}
int max(const std::vector<int>& v) {
    int max = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

void countSort256(std::vector<int>& v, int ep) {
    int *pInt = new int[v.size()];
    int i;
    int count[256] = {0};
    for (i = 0; i < v.size(); i++) {
        count[(v[i] / ep) % 256]++;
    }
    for (i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    for (i = static_cast<int>(v.size() - 1); i >= 0; i--) {
        pInt[count[(v[i] / ep) % 256] - 1] = v[i];
        count[(v[i] / ep) % 256]--;
    }
    for (i = 0; i < v.size(); i++) {
        v[i] = pInt[i];
    }
    delete[] pInt;
}
int64_t radix(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    int m = max(v);

    for (int exp = 1; m / exp > 0; exp *= 256) {
        countSort256(v, exp);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}
int64_t shellSortCiur(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    size_t size = v.size();
    size_t pre = 1;
    while (pre < size / 3) {
        pre = pre * 3 + 1;
    }
    while (pre > 0) {
        for (size_t i = pre; i < size; ++i) {
            int temp = v[i];
            size_t j;
            for (j = i; j >= pre && v[j - pre] > temp; j-= pre) {
                v[j] = v[j - pre];
            }
            v[j] = temp;
        }
        pre = (pre - 1) / 3;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}
int64_t shellSort(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    size_t gap = v.size() / 2;
    while (gap > 0) {
        for (size_t i = gap; i < v.size(); ++i) {
            int time = v[i];
            size_t j = i;
            while (j >= gap && v[j - gap] > time) {
                v[j] = v[j - gap];
                j -= gap;
            }
            v[j] = time;
        }
        gap /= 2;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return r.count();
}



