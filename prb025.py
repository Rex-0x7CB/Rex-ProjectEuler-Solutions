# Problem
# The Fibonacci sequence is defined by the recurrence relation:
#     Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
# Hence the first 12 terms will be:
#     F1 = 1
#     F2 = 1
#     F3 = 2
#     F4 = 3
#     F5 = 5
#     F6 = 8
#     F7 = 13
#     F8 = 21
#     F9 = 34
#     F10 = 55
#     F11 = 89
#     F12 = 144
# The 12th term, F12, is the first term to contain three digits.
# What is the index of the first term in the Fibonacci sequence to contain 1000 digits?


# Solution
# According to Binet's formula fib(n) = round(Golden^n / SqRoot(5)) 
# Number of digits in fib(n) = log10(fib(n))
# Number of digits in fib(n) = n*Log10(Golden) - (Log10(5)/2)

from scipy import constants
import math

i = 1
G = constants.golden
while True:
    number_of_digits = i*math.log(G, 10) - (math.log(5, 10)/2)
    #print("i=",i, "number_of_digits=", number_of_digits)
    if number_of_digits >= 999:
        break
    i = i + 1


print("Index of first Fibonacci number with 1000 digits: ", i)
