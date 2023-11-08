package sorting

import (
	"testing"
)

func TestBubbleSort(t *testing.T) {
	// Test case 1: Sorting an already sorted array
	arr := []int{1, 2, 3, 4, 5}
	BubbleSort(arr)
	expected := []int{1, 2, 3, 4, 5}
	if !isEqual(arr, expected) {
		t.Error("BubbleSort failed for sorted array")
	}

	// Test case 2: Sorting a reverse-sorted array
	arr = []int{5, 4, 3, 2, 1}
	BubbleSort(arr)
	expected = []int{1, 2, 3, 4, 5}
	if !isEqual(arr, expected) {
		t.Error("BubbleSort failed for reverse-sorted array")
	}

	// Test case 3: Sorting an unsorted array
	arr = []int{3, 2, 5, 1, 4}
	BubbleSort(arr)
	expected = []int{1, 2, 3, 4, 5}
	if !isEqual(arr, expected) {
		t.Error("BubbleSort failed for unsorted array")
	}
}

func isEqual(arr1 []int, arr2 []int) bool {
	if len(arr1) != len(arr2) {
		return false
	}
	for i := range arr1 {
		if arr1[i] != arr2[i] {
			return false
		}
	}
	return true
}
