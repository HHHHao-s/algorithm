import random


# 生成 10 个范围在 1 到 100 之间的随机数
random.seed(123)
for i in range(1000000):
    num = random.randint(1, 10000000)
    print(num, end=' ')
print()