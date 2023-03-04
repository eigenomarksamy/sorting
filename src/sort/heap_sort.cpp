#include "heap_sort.hpp"
#include "vector_operators.hpp"

void HeapSortRe::heapify(std::vector<std::uint32_t>& vec,
                         std::size_t size, std::uint32_t idx) const {
    auto largest = idx;
    auto left = 2 * idx + 1;
    auto right = 2 * idx + 2;

    if (left < size && vec[left] > vec[largest])
        largest = left;
    if (right < size && vec[right] > vec[largest])
        largest = right;
    if (largest != idx) {
        vutils::swapElementsByIdx(vec, idx, largest);
        heapify(vec, size, largest);
    }
}

void HeapSortRe::sort(std::vector<std::uint32_t>& vec,
                      std::size_t size) const {
    for (std::int64_t i = size / 2 - 1; i >= 0; i--)
        heapify(vec, size, i);
    for (std::int64_t i = size - 1; i > 0; i--) {
        vutils::swapElementsByIdx(vec, 0, i);
        heapify(vec, i, 0);
    }
}

void HeapSortIt::buildMaxHeap(std::vector<std::uint32_t>& vec,
                              std::size_t size) const {
    for (auto i = 1; i < size; i++) {
        if (vec[i] > vec[(i - 1) / 2]) {
            auto j = i;
            while (vec[j] > vec[(j - 1) / 2]) {
                vutils::swapElementsByIdx(vec, j, (j - 1) / 2);
                j = (j - 1) / 2;
            }
        }
    }
}

void HeapSortIt::sort(std::vector<std::uint32_t>& vec, std::size_t size) const {
    buildMaxHeap(vec, size);
    for (auto i = size - 1; i > 0; i--) {
        vutils::swapElementsByIdx(vec, 0, i);
        std::int64_t j = 0, idx;
        do {
            idx = (2 * j + 1);
            if (vec[idx] < vec[idx + 1] && idx < (i - 1))
                idx++;
            if (vec[j] < vec[idx] && idx < i)
                vutils::swapElementsByIdx(vec, j, idx);
            j = idx;
        } while (idx < i);
    }
}

void executeHeapSortDemo(const std::vector<std::uint32_t>& vec) {
    std::vector<std::uint32_t> vec_re = vec;
    HeapSortRe heap_sort_re_obj;
    heap_sort_re_obj.sort(vec_re, vec_re.size());
    vutils::printVector(vec_re, "heap      sorted (re)");
    std::vector<std::uint32_t> vec_it = vec;
    HeapSortIt heap_sort_it_obj;
    heap_sort_it_obj.sort(vec_it, vec_it.size());
    vutils::printVector(vec_re, "heap      sorted (it)");
}