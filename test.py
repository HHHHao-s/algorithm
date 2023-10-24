import random
import time
random.seed(time.time())

print('[', end='')
for i in range(3*(10**4)):
    a = random.randint(1,3*(10**4))
    print(f'{a},', end='')
    
    
print(']', end='')