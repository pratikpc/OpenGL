def Fib(n):
   if n == 0 or n == 1:
      return n;
   return Fib(n-1) + Fib(n-2);

for i in range(5):
	print ("Fib is ", Fib(i));