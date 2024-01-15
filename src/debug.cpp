#include <iostream>
#include <ostream>
#include <vector>

void print(std::vector<int> array);

std::vector<int> insertion_sort(std::vector<int> array)
{
    int max, j = 0;
    for (int i = 1; i < array.size(); i++) {
        max = array[i];

        for (j = i - 1; j >= 0; j--)
            if (array[j] <= max) break;
            else array[j + 1] = array[j];
        array[j + 1] = max;
    }
    return array;
}

std::vector<int> split(std::vector<int> array, int start, int end)
{
    auto s_iter = array.begin() + start;
    auto e_iter = array.begin() + end;

    return std::vector<int>(s_iter, e_iter);
}

std::vector<int> merge_sort(std::vector<int> arr) {
    print(arr);
    if (1 < arr.size()) {
        merge_sort(split(arr, 0, arr.size() / 2));
        merge_sort(split(arr, arr.size() / 2, arr.size()));
    }

    // HERE YOU SHOULD START SORTING
    return insertion_sort(arr);
}

void print(std::vector<int> array)
{
    for (int i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    std::vector<int> test = {1, 12, 9, 0, 8, 2, 6, 11, 53, 28, 5, 3};

    print(merge_sort(test));

    return 0;
}
