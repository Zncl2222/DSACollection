package sorting

import (
	"testing"
)

func TestShellSort(t *testing.T) {
	// Test case 1: Sorting an already sorted array
	arr := []int{1, 2, 3, 4, 5}
	ShellSort(arr)
	expected := []int{1, 2, 3, 4, 5}
	if !isEqual(arr, expected) {
		t.Error("BubbleSort failed for sorted array")
	}

	// Test case 2: Sorting a reverse-sorted array
	arr = []int{5, 4, 3, 2, 1}
	ShellSort(arr)
	expected = []int{1, 2, 3, 4, 5}
	if !isEqual(arr, expected) {
		t.Error("BubbleSort failed for reverse-sorted array")
	}

	// Test case 3: Sorting an unsorted array
	arr = []int{3, 2, 5, 1, 4}
	ShellSort(arr)
	expected = []int{1, 2, 3, 4, 5}
	if !isEqual(arr, expected) {
		t.Error("BubbleSort failed for unsorted array")
	}
}
