import sys
import multiprocessing
from multiprocessing import Process

def func1(a, res):
    print('func1: starting')
    for i in range(10000000): pass
    print('func1: finishing')
    res.update({a:1}) 
    print("appended")
 
def func2(a, res):
    print('func2: starting')
    for i in range(10000000): pass
    print('func2: finishing')
    res.update({a:2}) 
    print("appended")

def runInParallel(dict):
    manager = multiprocessing.Manager()
    res = manager.dict()
    proc = [] 
    print(dict)
    for d in dict:
	    print("h1")
        func = getattr(sys.modules[__name__], d)
        dict[d].append(res)
        print(dict[d])
        p = Process(target=func, args= tuple(dict[d],))
        print("h3")
        p.start()
        proc.append(p)
    for p in proc:
        p.join()
	return res
 
dict = {'func1' : [1], 'func2': [2]}
ans = runInParallel(dict)


