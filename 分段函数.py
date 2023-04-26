def f(x):
    if x<5:
        return x
    elif x<15:
        return x+6
    else :
        return x-6
a=eval(input())
if a>0:
    print(f(a))
else:
    print('illegal input')