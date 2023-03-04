#ifndef VECTOR_OPERATORS_HPP_
#define VECTOR_OPERATORS_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <ctime>

namespace vector_utils
{

template <class T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& values)
{
    stream << "[ ";
    std::copy(std::begin(values), std::end(values),
              std::ostream_iterator<T>(stream, " "));
    stream << ']';
    return stream;
}

template <class T>
void printVector(std::vector<T>& values, const std::string& txt,
                 bool print_size = false) {
    if (print_size)
        std::cout << "size: " << values.size() << std::endl;
    std::cout << txt << ": " << values << std::endl;
}

template <class T>
void getRandomVector(std::vector<T>& values, T offset = 0,
                     std::size_t range = UINT32_MAX, T max_value = UINT32_MAX,
                     bool is_srand = true) {
    if (is_srand)
        srand(time(NULL));
    std::size_t vec_size = offset + (rand() % range);
    values.resize(vec_size);
    for (auto& v : values) {
        v = rand() % max_value;
    }
}

template <class T>
void swapElementsByIdx(std::vector<T>& values,
                       const std::uint32_t idx_a, const std::uint32_t idx_b) {
    std::swap(values[idx_a], values[idx_b]);
}

} // namespace vector_utils

namespace vutils = vector_utils;

#endif /* VECTOR_OPERATORS_HPP_ */