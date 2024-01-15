#include <ctime>
#include <iostream>
#include <vector>
#include <time.h>

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

void test(std::vector<int> array, const char* desc)
{
    std::cout << "CPU time elapsed (" << desc << "): \n";
    clock_t s, e;

    s = clock();
    for (int i = 0; i < 100000; i++)
        merge_sort(array);
    e = clock();

    std::cout << "\t" << (float)((e - s) / (float)CLOCKS_PER_SEC) << "\n";

    s = clock();
    for (int i = 0; i < 100000; i++)
        insertion_sort(array);
    e = clock();

    std::cout << "\t" << (float)((e - s) / (float)CLOCKS_PER_SEC) << "\n";
}

int main(int argc, char** argv)
{
    std::vector<int> test1 = {1, 12, 9, 0, 8, 2, 6, 11, 53, 28, 5, 3};
    std::vector<int> test2 = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> test3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    test(test1, "random");
    test(test2, "reverse");
    test(test3, "sorted");
    return 0;
}
