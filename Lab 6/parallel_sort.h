//
// Created by Liu Zhao on 2024/4/22.
//

#ifndef PARALLEL_SORT_H
#define PARALLEL_SORT_H

#include <algorithm> // For std::sort
#include <thread>    // For std::thread
#include <iterator>  // For std::distance and std::advance
#include <vector>    // For std::vector

template<typename Iterator>
void parallelSort(Iterator first, Iterator last) {
    // Determine the size of the data to be sorted
    auto size = std::distance(first, last);

    // If the data is small, just use a regular sort
    //if (size < 1000) {
    //    std::sort(first, last);
    //    return;
    //}

    // Determine the midpoint of the data range
    Iterator middle = first;
    std::advance(middle, size / 2);

    // Sort the first half of the data in a separate thread
    std::thread sort_first_half(std::sort<Iterator>, first, middle);

    // Sort the second half of the data in this thread
    std::sort(middle, last);

    // Wait for the first half of the data to be sorted
    sort_first_half.join();

    // Merge the two halves (requires the data to be sorted already)
    std::inplace_merge(first, middle, last);
}

#endif // PARALLEL_SORT_H
