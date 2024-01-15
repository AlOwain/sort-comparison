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

std::vector<int> sort_and_merge(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> array(left.size() + right.size());
    
    int array_iter = 0, left_iter = 0, right_iter = 0;
    while (left_iter < left.size() && right_iter < right.size())
    {
        if (left[left_iter] < right[right_iter])
        {
            array[array_iter] = left[left_iter];
            array_iter++;
            left_iter++;
        }
        else
        {
            array[array_iter] = right[right_iter];
            array_iter++;
            right_iter++;
        }
    }

    for (;left_iter < left.size();  left_iter++)
    {
        array[array_iter] = left[left_iter];
        array_iter++;
    }

    for (;right_iter < right.size(); right_iter++)
    {
        array[array_iter] = right[right_iter];
        array_iter++;
    }
    return array;
}

std::vector<int> merge_sort(std::vector<int> array)
{
    std::vector<int> left, right;

    left = split(array, 0, array.size() / 2);
    right = split(array, array.size() / 2, array.size());

    if (array.size() > 2)
    {
        left = merge_sort(left);
        right = merge_sort(right);
    }
    array = sort_and_merge(left, right);

    return array;
}

int main(int argc, char** argv)
{
    std::vector<int> test = {1, 12, 9, 0, 8, 2, 6, 11, 53, 28, 5, 3};
    std::vector<int> test1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> test2 = {0, 0, 0, 0, 0, 0 ,0};
    std::vector<int> test3 = {1};
    std::vector<int> test4 = {-1, -43, -3, 0, 0, 43, 22, 1};

    print(merge_sort(test));
    print(merge_sort(test1));
    print(merge_sort(test2));
    print(merge_sort(test3));
    print(merge_sort(test4));

    std::cout << "\n\n";
    print(insertion_sort(test));
    print(insertion_sort(test1));
    print(insertion_sort(test2));
    print(insertion_sort(test3));
    print(insertion_sort(test4));

    return 0;
}
