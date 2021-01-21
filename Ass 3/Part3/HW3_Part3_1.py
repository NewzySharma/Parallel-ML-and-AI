
import pandas as pd
import numpy as np
import multiprocessing as mp

df = pd.DataFrame(np.random.randint(3, 10, size=[20000, 100]))

def sq_root():
    sq_roots = []
    for i in range(len(df)):
        roots = np.sqrt((df.iloc[i]**2).sum())
        sq_roots.append(round(roots,2))
    return sq_roots

if __name__ == '__main__':
    roots = sq_root()
    print(roots[:10])
