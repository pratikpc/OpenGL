from math import sqrt

print('Quadratic function : (a*x^2) + b*X + c')
a = float(input('a : '))
b = float(input('b : '))
c = float(input('c : '))

r = b**2 - 4*a*c 

if r > 0:
    num_roots = 2
    x1 = (((-b) + sqrt(r)) / (2*a))
    x2 = (((-b) - sqrt(r)) / (2*a))
    print('There are two roots %f and %f' % (x1,x2))
elif r == 0:
    num_roots = 1 
    x = (-b) / 2*a
    print("There is one root" % x)
else:
    print('There is no solution')
