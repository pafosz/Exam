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

// шейкерная сортировка
void cocktailSort(std::vector<int>& arr) {
	size_t size = arr.size();
	size_t left = 0, right = size - 1;
	size_t last_compare = 0;
	while (left <= right) {		
		for (size_t i = left; i < right; i++) {
			if (arr[i + 1] < arr[i]) {
				std::swap(arr[i + 1], arr[i]);
				last_compare = i;
			}
		}
		right = last_compare;
		for (size_t i = right; i > left; i--) {
			if (arr[i] < arr[i - 1]) {
				std::swap(arr[i], arr[i - 1]);
				last_compare = i;
			}
		}
		left = last_compare;
	}
}

// быстрая сортировка
int partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[low];
	int left = low + 1, right = high;
	while (left < right) {
		while (left <= high && pivot >= arr[left]) {
			left++;
		}
		while (right >= low && pivot < arr[right]) {
			right--;
		}
		if (left < right) {
			std::swap(arr[left], arr[right]);
		}
	}
	std::swap(arr[low], arr[right]);
	return right;
}

void quickSortHelper(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(arr, low, high);
		quickSortHelper(arr, low, pivotIndex - 1);
		quickSortHelper(arr, pivotIndex + 1, high);
	}
}

void quickSort(std::vector<int>& arr) {
	quickSortHelper(arr, 0, arr.size() - 1);
}