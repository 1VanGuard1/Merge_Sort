#include <iostream>
#include <vector>

// —ли€ние двух упор€доченных половин массива
// left  - индекс начала первой половины
// right - индекс начала второй половины
// end   - индекс конца второй половины

void merge(std::vector<int>& arr, int left, int right, int end) {
    // —оздаем временный массив дл€ сли€ни€
    std::vector<int> temp(end - left + 1);

    // »ндексы текущего элемента в каждой половине
    int i = left;
    int j = right + 1;

    // »ндекс дл€ записи во временный массив
    int pos = 0;

    // —ли€ние двух половин массива
    while (i <= right && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[pos++] = arr[i++];
        }
        else {
            temp[pos++] = arr[j++];
        }
    }

    //  опируем оставшиес€ элементы первой половины (если есть)
    while (i <= right) {
        temp[pos++] = arr[i++];
    }

    //  опируем оставшиес€ элементы второй половины (если есть)
    while (j <= end) {
        temp[pos++] = arr[j++];
    }

    //  опируем отсортированный временный массив обратно в исходный
    for (pos = 0; pos < temp.size(); ++pos) {
        arr[left + pos] = temp[pos];
    }
}

// —ортировка сли€нием
void merge_sort(std::vector<int>& arr, int left, int end) {
    if (left < end) {
        int middle = (left + end) / 2;
        merge_sort(arr, left, middle);      // —ортируем левую половину
        merge_sort(arr, middle + 1, end);   // —ортируем правую половину
        merge(arr, left, middle, end);      // —оедин€ем две отсортированные половины
    }
}


int main() {
    int n = 100;
    srand(time(NULL));
    std::vector<int> arr = std::vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    std::cout << "Unsorted array:\n";
    for (int i : arr)
    {
        std::cout << i << " ";
    }
    merge_sort(arr, 0, arr.size() - 1);
    std::cout << "\nSorted array\n";
    for (int i : arr) {
        std::cout << i << " ";
    }
    return 0;
}
