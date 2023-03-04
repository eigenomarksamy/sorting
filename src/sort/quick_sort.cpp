#include "vector_operators.hpp"
#include "misc_sort.hpp"

static std::int64_t partition(std::vector<std::uint32_t>& vec,
                              std::uint32_t low, std::uint32_t high)
{
    std::uint32_t pivot = vec[high];
    std::uint32_t i = (low - 1);
  
    for (auto j = low; j <= high - 1; j++) {
        if (vec[j] < pivot) {
            i++;
            vutils::swapElementsByIdx(vec, i, j);
        }
    }
    vutils::swapElementsByIdx(vec, i + 1, high);
    return (i + 1);
}

static void quickSort(std::vector<std::uint32_t>& vec,
                      std::int64_t low, std::int64_t high) {
    if (low < high) {
        auto pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void executeQuickSortDemo(const std::vector<std::uint32_t>& vec) {
    std::vector<std::uint32_t> vec_re = vec;
    quickSort(vec_re, 0, vec_re.size() - 1);
    vutils::printVector(vec_re, "quick     sorted (re)");
}