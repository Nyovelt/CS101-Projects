def Exgcd(a: int, b: int):
    '''
            gcd(a,b)=ax+by
    '''
    if (not b):
        return [1, 0]
    x, y = Exgcd(b, a % b)
    return [y, x - a // b * y]

a = [ 3 ,5, 7 ,11, 13, 17 ,19 ,23, 29,31 ,37 ,41 ,43, 47, 53, 59, 61, 67 ,71, 73, 79 ,83 ,89 ,97, 101 ,103]
for i in a:
    print (Exgcd(i, 4294967291)[0] % 4294967291, end=',')