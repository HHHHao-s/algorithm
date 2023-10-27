import random
import time
random.seed(time.time())

print('{', end='')
for i in range(100000):
    if(i*i>1000000000):
        break
    print(f'{i*i},', end='')
    
    
print('}', end='')