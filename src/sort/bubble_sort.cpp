#include "bubble_sort.hpp"
#include "vector_operators.hpp"

void BubbleIt::sort(std::vector<std::uint32_t>& vec, std::size_t size) const {
    for (std::uint32_t i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (std::uint32_t j = 0; j < size - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                vutils::swapElementsByIdx(vec, j, j + 1);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void BubbleRe::sort(std::vector<std::uint32_t>& vec, std::size_t size) const {
    if (size == 0 || size == 1)
        return;
    for (std::uint32_t i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            vutils::swapElementsByIdx(vec, i, i + 1);
        }
    }
    sort(vec, size - 1);
}

void executeBubbleSortDemo(const std::vector<std::uint32_t>& vec) {
    std::vector<std::uint32_t> vec_re = vec;
    BubbleRe bubble_sort_re_obj;
    bubble_sort_re_obj.sort(vec_re, vec_re.size());
    vutils::printVector(vec_re, "bubble    sorted (re)");
    std::vector<std::uint32_t> vec_it = vec;
    BubbleIt bubble_sort_it_obj;
    bubble_sort_it_obj.sort(vec_it, vec_it.size());
    vutils::printVector(vec_it, "bubble    sorted (it)");
}