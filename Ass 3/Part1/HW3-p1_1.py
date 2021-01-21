import multiprocessing as mp

def job(l1, l2):
    l2 = set(l2)
    return [val for val in l1 if val in l2]

def multicore(list_a, list_b):
    pool = mp.Pool(processes=4)
    res = [pool.apply(job, (l1,l2)) for l1, l2 in zip(list_a, list_b)]
    print(res)

if __name__ == '__main__':
    #print("Number of processors: ", mp.cpu_count())     # how many processors are present in the machine
    list_a = [[1, 2, 3], [5, 6, 7, 8], [10, 11, 12], [20, 21]]
    list_b = [[2, 3, 4, 5], [6, 9, 10], [11, 12, 13, 14], [21, 24, 25]]
    multicore(list_a, list_b)
