import random
# 质数筛
def sieve_of_eratosthenes(limit):
    primes = [True] * limit
    primes[0] = primes[1] = False

    for ind, val in enumerate(primes):
        if val is True:
            primes[ind*2::ind] = [False] * (((limit - 1)//ind) - 1)

    return [ind for ind, val in enumerate(primes) if val is True]

def gen(n):
    print(n)
    for i  in range(0,n):
        print(str( random.randrange(1,2^15)))
        
gen(500000)