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
