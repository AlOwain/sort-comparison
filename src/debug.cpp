#include <iostream>
#include <vector>

// FIXME: report edge case: (only 1 entry)

void print(std::vector<int> array)
{
    for (int i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

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

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> array(left.size() + right.size());
    
    int i = 0;
    for (int x : left)
    {
        array[i] = x;
        i++;
    }

    for (int x : right)
    {
        array[i] = x;
        i++;
    }
    return array;
}

std::vector<int> merge_sort(std::vector<int> array)
{
    std::vector<int> left, right;

    left = split(array, 0, array.size() / 2);
    right = split(array, array.size() / 2, array.size());

    if (array.size() > 3)
        array = merge(merge_sort(left), merge_sort(right));

    return array;
}

int main(int argc, char** argv)
{
    std::vector<int> test = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    print(merge_sort(test));

    return 0;
}
