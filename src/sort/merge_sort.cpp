#include "merge_sort.hpp"

void MergeSort::merge(std::vector<std::uint32_t>& vec,
                      const std::uint32_t left,
                      const std::uint32_t right,
                      const std::uint32_t mid) const {
    auto const len_sub_vec_1 = mid - left + 1, len_sub_vec_2 = right - mid;

    std::vector<std::uint32_t> left_vec(len_sub_vec_1), right_vec(len_sub_vec_2);
    for (auto i = 0; i < len_sub_vec_1; ++i)
        left_vec[i] = vec[left + i];
    for (auto i = 0; i < len_sub_vec_2; ++i)
        right_vec[i] = vec[mid + 1 + i];

    auto idx_sub_vec_1 = 0, idx_sub_vec_2 = 0;
    auto idx_merge_arr = left;
    while (idx_sub_vec_1 < len_sub_vec_1
           && idx_sub_vec_2 < len_sub_vec_2) {
        if (left_vec[idx_sub_vec_1] <= right_vec[idx_sub_vec_2]) {
            vec[idx_merge_arr] = left_vec[idx_sub_vec_1];
            idx_sub_vec_1++;
        }
        else {
            vec[idx_merge_arr] = right_vec[idx_sub_vec_2];
            idx_sub_vec_2++;
        }
        idx_merge_arr++;
    }

    while (idx_sub_vec_1 < len_sub_vec_1) {
        vec[idx_merge_arr] = left_vec[idx_sub_vec_1];
        idx_sub_vec_1++;
        idx_merge_arr++;
    }
    while (idx_sub_vec_2 < len_sub_vec_2) {
        vec[idx_merge_arr] = right_vec[idx_sub_vec_2];
        idx_sub_vec_2++;
        idx_merge_arr++;
    }
}

void MergeRecursive::divide(std::vector<std::uint32_t>& vec,
                            const std::uint32_t begin,
                            const std::uint32_t end) const {
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    divide(vec, begin, mid);
    divide(vec, mid + 1, end);
    merge(vec, begin, end, mid);
}

void MergeRecursive::sort(std::vector<std::uint32_t>& vec) const {
    divide(vec, 0, vec.size() - 1);
}

void MergeIterative::sort(std::vector<std::uint32_t>& vec) const {
    std::uint32_t curr_size, left_start;
    for (curr_size = 1; curr_size <= vec.size() - 1; curr_size *= 2) {
        for (left_start = 0; left_start < vec.size() - 1; left_start += 2 * curr_size) {
            std::uint32_t mid = std::min(left_start + curr_size - 1,
                                static_cast<std::uint32_t>(vec.size() - 1));
            std::uint32_t right_end = std::min(left_start + 2 * curr_size - 1,
                                      static_cast<std::uint32_t>(vec.size() - 1));
            merge(vec, left_start, right_end, mid);
        }
    }
}

void executeMergeSortDemo(const std::vector<std::uint32_t>& vec) {
    std::vector<std::uint32_t> vec_re = vec;
    MergeRecursive merge_sort_re_obj;
    merge_sort_re_obj.sort(vec_re);
    vutils::printVector(vec_re, "merge     sorted (re)");
    std::vector<std::uint32_t> vec_it = vec;
    MergeIterative merge_sort_it_obj;
    merge_sort_it_obj.sort(vec_it);
    vutils::printVector(vec_it, "merge     sorted (it)");
}