#ifndef BUBBLE_SORT_HPP_
#define BUBBLE_SORT_HPP_

#include <vector>
#include <string>

class BubbleSort
{
public:
    BubbleSort() {}
    ~BubbleSort() {}

    virtual void sort(std::vector<std::uint32_t>& vec, std::size_t size) const = 0;
};

class BubbleIt : public BubbleSort
{
public:
    BubbleIt() {}
    ~BubbleIt() {}

    void sort(std::vector<std::uint32_t>& vec, std::size_t size) const;
};

class BubbleRe : public BubbleSort
{
public:
    BubbleRe() {}
    ~BubbleRe() {}

    void sort(std::vector<std::uint32_t>& vec, std::size_t size) const;
};

void executeBubbleSortDemo(const std::vector<std::uint32_t>& vec);

#endif /* BUBBLE_SORT_HPP_ */