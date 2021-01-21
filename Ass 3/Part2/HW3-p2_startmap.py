# Solution Without Paralleization
import numpy as np
from time import time
import multiprocessing as mp

# Prepare data
np.random.RandomState(100)
arr = np.random.randint(0, 10, size=[200000, 5])
data = arr.tolist()
#data[:5]

def examp01(row, minimum, maximum):
    """Returns how many numbers between `maximum` and `minimum` in a given `row`"""
    count = 0
    for n in row:
        if minimum <= n <= maximum:
            count = count + 1
    return count


def multicore():
    pool = mp.Pool(processes=4)
    res = [pool.apply(examp01, (row, 4, 8)) for row in data]
    print(res.get())

if __name__ == '__main__':
    multicore()
