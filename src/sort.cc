#pragma once
#include <iostream>
#include <vector>


// сортировка: метод простого включения
std::vector<int> includeSort(std::vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int j = i - 1;
		while (j >= 0 && arr[j + 1] < arr[j]) {
			std::swap(arr[j], arr[j + 1]);
			j--;
		}
	}
	return arr;
}

// сортировка: метод бинарных вставок
void binaryInsertionSort(std::vector<int>& arr) {
	for (size_t i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int left = 0, right = static_cast<int>(i);

		while (left < right) {
			int mid = (right - left)/ 2;
			if (arr[mid] < arr[i])
				left = mid + 1;
			else
				right = mid - 1;
		}

		for (size_t j = i; j > left; j--) {
			arr[j] = arr[j - 1];
		}
		arr[left] = key;
		
	}
}