import numpy as np


def get_biggest_nums(arr):
    # функция нахожит кол-во элементов больших среднего арифмитического

    mean = np.mean(arr)

    return len(
        np.where(arr > mean)[0])  # np.where возвращает кортеж с массив индексов элементов удовлетворяющих условию


test_arr = np.array([1, 1, -500, 1, 2])
print(get_biggest_nums(test_arr))
