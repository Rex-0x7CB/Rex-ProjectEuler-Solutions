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
