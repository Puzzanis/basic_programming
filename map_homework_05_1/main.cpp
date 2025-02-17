#include <iostream>
#include <algorithm>
#include <vector>
#include <future>


enum class dividingIntervals
{
    valueOfMinIntervals = 3
};


void multiplyVec(int& MultiplierVec)
{
    MultiplierVec *= 2;
}

template <typename Iterator, dividingIntervals chunkSize = dividingIntervals::valueOfMinIntervals>
void parallelForEachAsyncRecursive(Iterator begin, Iterator end)
{
    int size = std::distance(begin, end);

    if (size <= static_cast<int>(chunkSize))
    {
        std::for_each(begin, end, multiplyVec);
    }
    else
    {
        auto mid = begin;
        std::advance(mid, size / 2);
        auto ftRes = std::async(parallelForEachAsyncRecursive<Iterator>, begin, mid);
        parallelForEachAsyncRecursive(mid, end);

        ftRes.get();
    }
}

int main()
{
    setlocale(0, "");
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "До: ";
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    parallelForEachAsyncRecursive(vec.begin(), vec.end());

    std::cout << "\nПосле: ";
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}