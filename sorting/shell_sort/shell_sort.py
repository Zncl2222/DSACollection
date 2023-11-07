def shell_sort(data):
    n = len(data)
    interval = n // 2
    while interval > 0:
        for i in range(interval, n):
            value = data[i]
            j = i
            while j >= interval and data[j - interval] > value:
                data[j] = data[j - interval]
                j -= interval
            data[j] = value
        interval //= 2
