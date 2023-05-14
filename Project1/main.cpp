#include <iostream>
#include <vector>

// ������� ���� ������������� ������� �������
// left  - ������ ������ ������ ��������
// right - ������ ������ ������ ��������
// end   - ������ ����� ������ ��������

void merge(std::vector<int>& arr, int left, int right, int end) {
    // ������� ��������� ������ ��� �������
    std::vector<int> temp(end - left + 1);

    // ������� �������� �������� � ������ ��������
    int i = left;
    int j = right + 1;

    // ������ ��� ������ �� ��������� ������
    int pos = 0;

    // ������� ���� ������� �������
    while (i <= right && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[pos++] = arr[i++];
        }
        else {
            temp[pos++] = arr[j++];
        }
    }

    // �������� ���������� �������� ������ �������� (���� ����)
    while (i <= right) {
        temp[pos++] = arr[i++];
    }

    // �������� ���������� �������� ������ �������� (���� ����)
    while (j <= end) {
        temp[pos++] = arr[j++];
    }

    // �������� ��������������� ��������� ������ ������� � ��������
    for (pos = 0; pos < temp.size(); ++pos) {
        arr[left + pos] = temp[pos];
    }
}

// ���������� ��������
void merge_sort(std::vector<int>& arr, int left, int end) {
    if (left < end) {
        int middle = (left + end) / 2;
        merge_sort(arr, left, middle);      // ��������� ����� ��������
        merge_sort(arr, middle + 1, end);   // ��������� ������ ��������
        merge(arr, left, middle, end);      // ��������� ��� ��������������� ��������
    }
}


int main() {
    std::vector<int> arr = { 3, 9, 1, 4, 8, 2, 5, 7, 6 };
    merge_sort(arr, 0, arr.size() - 1);
    for (int i : arr) {
        std::cout << i << " ";
    }
    return 0;
}
