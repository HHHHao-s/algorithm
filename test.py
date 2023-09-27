def get_primes(n):
    is_prime = [True] * (n + 1)
    primes = []
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return primes

primes = get_primes(100000)
print("{")
count = 0
for each in primes:
    count += 1
    print(f"{each},", end=' ')
    if(count==100):
        print('\n', end=' ')
        count = 0

print("}")