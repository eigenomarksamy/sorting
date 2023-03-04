#include "misc_sort.hpp"
#include "vector_operators.hpp"

void selectionSort(std::vector<std::uint32_t>& vec) {
    std::uint32_t min_idx;

    for (std::uint32_t i = 0; i < vec.size() - 1; i++) {
        min_idx = i;
        for (std::uint32_t j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[min_idx])
                min_idx = j;
        if (min_idx != i)
            vutils::swapElementsByIdx(vec, min_idx, i);
    }
}

void executeSelectionSortDemo(const std::vector<std::uint32_t>& vec) {
    std::vector<std::uint32_t> vec_it = vec;
    selectionSort(vec_it);
    vutils::printVector(vec_it, "selection sorted (it)");
}

void insertionSort(std::vector<std::uint32_t>& vec) {
    for (std::uint32_t i = 1; i < vec.size(); i++) {
        auto key = vec[i];
        std::int64_t j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j -= 1;
        }
        vec[j + 1] = key;
    }
}

void executeInsertionSortDemo(const std::vector<std::uint32_t>& vec) {
    std::vector<std::uint32_t> vec_it = vec;
    insertionSort(vec_it);
    vutils::printVector(vec_it, "insertion sorted (it)");
}

void shellSort(std::vector<std::uint32_t>& vec) {
    auto n = vec.size();
    for (std::uint32_t gap = n / 2; gap > 0; gap /= 2) {
        for (std::uint32_t i = gap; i < n; i++) {
            auto tmp = vec[i];
            auto j = i;
            for (; j >= gap && vec[j - gap] > tmp; j -= gap)
                vec[j] = vec[j - gap];
            vec[j] = tmp;
        }
    }
}

void executeShellSortDemo(const std::vector<std::uint32_t>& vec) {
    std::vector<std::uint32_t> vec_it = vec;
    shellSort(vec_it);
    vutils::printVector(vec_it, "shell     sorted (it)");
}