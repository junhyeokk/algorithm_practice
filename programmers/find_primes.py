from itertools import permutations
from math import sqrt

def is_prime(num):
    if num == 0 or num == 1:
        return False
    for i in range(2, int(sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def solution(numbers):
    primes = set()
    
    numbers = list(numbers)
    for i in range(1, len(numbers) + 1):
        for num in permutations(numbers, i):
            if is_prime(int(''.join(num))):
                primes.add(int(''.join(num)))
    print(primes)
    return len(primes)

print(solution("17"))