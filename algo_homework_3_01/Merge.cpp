#include "Merge.h"

std::vector<int> merge(std::vector<int> arr1, std::vector<int> arr2)
{
    std::vector<int> arr3(arr1.size() + arr2.size());
    int i1{0};
    int i2{0};

    for (int i3 = 0; i3 < arr1.size() + arr2.size(); i3++)
    {
        if (i1 == arr1.size()) { arr3[i3] = arr2[i2]; i2++; }
        else if (i2 == arr2.size()) { arr3[i3] = arr1[i1]; i1++; }
        else
        {
            if (arr1[i1] <= arr2[i2]) { arr3[i3] = arr1[i1]; i1++; }
            else { arr3[i3] = arr2[i2]; i2++; }
        }
    }
    return arr3;
}