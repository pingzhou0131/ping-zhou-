cnt=1
def hnt(n,a,b,c):
    global cnt
    if n==1:
        print('[STEP{:>4}] {}->{}'.format(cnt,a,c))
        cnt+=1
        return
    hnt(n-1,a,c,b)
    print('[STEP{:>4}] {}->{}'.format(cnt,a,c))
    cnt+=1
    hnt(n-1,b,a,c)
a=eval(input())
hnt(a,'A','B','C')

