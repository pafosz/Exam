#include <iostream>

int find(const int* arr, int size, int key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) return i;
	}
	return -1;
}

int binary_search(const int* arr, int size, int key) {
	if (size <= 0) return -1;
	int lower = 0, upper = size - 1;
	while (lower <= upper) {
		int current = (lower + upper) / 2;
		if (arr[current] == key) return current;
		else if (arr[current] < key) lower = current + 1;
		else upper = current - 1;
	}
	return -1;
}

int interpolation_search(const int* arr, int size, int key) {
	if (size <= 0) return -1;
	int lower = 0, upper = size - 1;
	while (lower <= upper) {
		int i = lower + (((upper - lower) * (key - arr[lower])) / (arr[upper] - arr[lower]));

		if (arr[i] == key) return i;
		else if (key < arr[i]) upper = i - 1;
		else lower = i + 1;
	}
	return -1;
}