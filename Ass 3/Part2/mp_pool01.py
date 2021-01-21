import multiprocessing as mp

def job(x):
    return x*x

def multicore():
    pool = mp.Pool(processes=4)
    res = pool.map(job, range(10))
    print(res)
    res = pool.apply_async(job, (2,))
    print(res.get())
    multi_res =[pool.apply_async(job, (i,)) for i in range(10)]
    print([res.get() for res in multi_res])

if __name__ == '__main__':
    print("Number of processors: ", mp.cpu_count())     # how many processors are present in the machine
    multicore()
