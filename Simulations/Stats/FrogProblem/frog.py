
from random import randint

def sim(remaining_jumps):
    if remaining_jumps == 0:
        return 0
    else:
        jumps = randint(1, remaining_jumps)
        return 1 + sim(remaining_jumps - jumps)

avg = 0.
sample_size = 10000000
for i in range(sample_size):
    avg += sim(10)

print avg / sample_size # 2.9287143

