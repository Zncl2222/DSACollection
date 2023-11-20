package sorting

func ShellSort(data []int) {
	n := len(data)
	interval := n / 2
	for interval > 0 {
		for i := interval; i < n; i++ {
			value := data[i]
			j := i
			for j >= interval && data[j-interval] > value {
				data[j] = data[j-interval]
				j -= interval
			}
			data[j] = value
		}
		interval /= 2
	}
}
