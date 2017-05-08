'''
Non-abundant sums
Problem 23

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

'''


#!/usr/bin/env python3
import math

def is_abundant(n):
    temp = 1
    divisors = [1]

    while 1:
        temp = temp + 1
        # if temp > math.floor(n/2):
        #     break
        if n % temp == 0:
            if temp < n/temp:
                divisors.append(temp)
                divisors.append(n/temp)
            elif temp == n/temp:
                divisors.append(temp)
            else:
                break

    if sum(divisors) > n:
        return 1
    else:
        return 0


def main():
    abundant = []
    sums = 0
    for i in range(12,28123):
        if is_abundant(i) == 1:
            abundant.append(i)
    # print(abundant)
    CanBeExpressedAsSum = [0] * (28123+1)
    total = len(abundant)
    for i in range(0,total):
        for j in range(i,total):
            if abundant[i] + abundant[j] <= 28123:
                CanBeExpressedAsSum[abundant[i] + abundant[j]] = 1
            else:
                break

    for i in range(1,28123+1):
        # print( (i,CanBeExpressedAsSum[i]) )
        if CanBeExpressedAsSum[i] != 1:
            sums = sums + i

    print(sums)


if __name__ == '__main__':
    main()
