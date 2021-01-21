
import pandas as pd
import numpy as np
import multiprocessing as mp
import time

df = pd.DataFrame(np.random.randint(3, 10, size=[20000, 100]))

def sq_root_parallel(row):
    root = np.sqrt((row**2).sum())
    return round(root,2)

if __name__ == '__main__':
    for num in (2,4,8):
        pool= mp.Pool(processes = num)
        start = time.time()
        it = pool.imap(sq_root_parallel, df.iterrows())
        end = time.time()
        print("When CPU = %s, the elapsed time is %0.6f seconds."%(num,end-start))
    
