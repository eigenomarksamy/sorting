#ifndef MERGE_SORT_HPP_
#define MERGE_SORT_HPP_

#include <vector>
#include <string>
#include <cstdlib>
#include <stdint.h>
#include "vector_operators.hpp"

class MergeSort
{
protected:
    void merge(std::vector<std::uint32_t>& vec,
               const std::uint32_t left,
               const std::uint32_t right,
               const std::uint32_t mid) const;

public:
    MergeSort() {}
    ~MergeSort() {}

    virtual void sort(std::vector<std::uint32_t>& vec) const = 0;
};

class MergeIterative : public MergeSort
{
public:
    MergeIterative() {}
    ~MergeIterative() {}

    void sort(std::vector<std::uint32_t>& vec) const;
};

class MergeRecursive : public MergeSort
{
private:
    void divide(std::vector<std::uint32_t>& vec,
                const std::uint32_t begin, const std::uint32_t end) const;
public:
    MergeRecursive() {}
    ~MergeRecursive() {}

    void sort(std::vector<std::uint32_t>& vec) const;
};

void executeMergeSortDemo(const std::vector<std::uint32_t>& vec);

#endif /* MERGE_SORT_HPP_ */