#ifndef HEAP_SORT_HPP_
#define HEAP_SORT_HPP_

#include <vector>
#include <string>

class HeapSort
{
private:
    virtual void sort(std::vector<std::uint32_t>& vec,
                      std::size_t size) const = 0;
public:
    HeapSort() {}
    ~HeapSort() {}
};

class HeapSortRe : private HeapSort
{
private:
    void heapify(std::vector<std::uint32_t>& vec,
                 std::size_t size, std::uint32_t idx) const;

public:
    HeapSortRe() {}
    ~HeapSortRe() {}

    void sort(std::vector<std::uint32_t>& vec, std::size_t size) const;
};

class HeapSortIt : private HeapSort
{
private:
    void buildMaxHeap(std::vector<std::uint32_t>& vec, std::size_t size) const;

public:
    HeapSortIt() {}
    ~HeapSortIt() {}

    void sort(std::vector<std::uint32_t>& vec, std::size_t size) const;
};

void executeHeapSortDemo(const std::vector<std::uint32_t>& vec);

#endif /* HEAP_SORT_HPP_ */