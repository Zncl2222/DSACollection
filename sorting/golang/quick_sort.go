package sorting

func QuickSort(data []int) {
	if len(data) <= 1 {
		return
	}

	pivot := partition(data)

	QuickSort(data[:pivot])
	QuickSort(data[pivot+1:])
}

func partition(data []int) int {
	pivot := data[0]
	left, right := 1, len(data)-1

	for left <= right {
		for left <= right && data[left] <= pivot {
			left++
		}

		for left <= right && data[right] > pivot {
			right--
		}

		if left <= right {
			data[left], data[right] = data[right], data[left]
		}
	}

	data[0], data[right] = data[right], data[0]

	return right
}
