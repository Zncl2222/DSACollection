package sorting

func swap(a *int, b *int) {
	temp := *a
	*a = *b
	*b = temp
}

func BubbleSort(array []int) {
	arraySize := len(array)
	for i := 0; i < arraySize; i++ {
		for j := arraySize - 1; j > i; j-- {
			if array[j] < array[j-1] {
				swap(&array[j], &array[j-1])
			}
		}
	}
}
