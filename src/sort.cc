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

// сортировка: методом Шелла
void sortShell(std::vector<int>& arr) {
	int size = static_cast<int>(arr.size());
	int step = size / 2;
	while (step) {
		for (int i = 0; i < size - step; i++) {
			if (arr[i + step] < arr[i])
				std::swap(arr[i + step], arr[i]);
		}
		step /= 2;
	}
}

// сортировка простым выбором (извлечением)
	
void choiceSort(std::vector<int>& arr) {
	for (size_t i = 0; i < arr.size() - 1; i++) {
		size_t min_index = i;
		for (size_t j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[min_index]) min_index = j;
		}
		std::swap(arr[i], arr[min_index]);
	}
}

// Обменная сортировка (пузырьком)
void buubleSort(std::vector<int>& arr) {
	size_t size = arr.size();
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (arr[j + 1] < arr[j])
				std::swap(arr[j + 1], arr[j]);
		}
	}
}