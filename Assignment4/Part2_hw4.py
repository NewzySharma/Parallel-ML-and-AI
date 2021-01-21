#!/usr/bin/env python
# coding: utf-8

# In[4]:


import torch
import time


# In[2]:
start = time.time()

n = 10
A = torch.randn(10000, 10000)
B = torch.randn(10000, 10000)


# In[ ]:


A = A.cuda(0)
B = B.cuda(0)


# In[5]:


s1 = torch.cuda.Stream()
s2 = torch.cuda.Stream()

with torch.cuda.stream(s1):
    A = torch.pow(A,n)
with torch.cuda.stream(s2):
    B = torch.pow(B,n)

C = A+B 


end = time.time()
print("Computation time on GPU is:",end-start)


# In[ ]:




