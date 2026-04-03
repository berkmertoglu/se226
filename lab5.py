def factorial(x):
    if x<=1:
        return 1
    return x* factorial(x-1)

abs_term=lambda x ,i:(x**(2*i))/factorial(2*i)

def exp_x(x,n):
    total=0
    for i in range(n):
        sign=1  if i%2==0 else -1
        total +=sign*abs_term(x,i)
    return total


global_Gn_sum=0
def calculate_Gn(n,r):
    """
   Recursively adds terms of the geometric series to global_Gn_sum.
    Each call adds r^n, then calls itself with n-1 until n < 0.

    If r is negative, the sign of terms changes automatically.
    """
    global global_Gn_sum
    if n<0:
        return
    global_Gn_sum+=r ** n
    calculate_Gn(n-1,r)
