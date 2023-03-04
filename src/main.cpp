#include "sort.hpp"

int main() {
    std::vector<std::uint32_t> vec_og;
    vutils::getRandomVector(vec_og, 3U, 7U);
    vutils::printVector(vec_og, "initial          (og)", true);
    executeMergeSortDemo(vec_og);
    executeHeapSortDemo(vec_og);
    executeQuickSortDemo(vec_og);
    executeSelectionSortDemo(vec_og);
    executeInsertionSortDemo(vec_og);
    executeBubbleSortDemo(vec_og);
    executeShellSortDemo(vec_og);
}