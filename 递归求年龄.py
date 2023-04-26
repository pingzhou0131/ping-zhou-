# 假设现在有N个人，第一个人3岁，第二个人x岁（未知），第三个人的年龄是前两个人年龄之和，以
# 此类推直到第N个人。尝试编写递归函数，当输入第2个人的年龄（x）和总人数（N）时，逆序输出所
# 有人的年龄组成的列表。注：当其中第M个人的年龄大于120岁时，输出"Larger than 120!"和前
# M-1个人的年龄的逆序列表。
# 【输入形式】
#
# 在一行内分别输入x和N，用逗号隔开
# 【输出形式】
#
# 逆序输出N个人的年龄组成的列表。当其中第M个人的年龄大于120岁时，输出"Larger than 120!"
# 和前M-1个人的年龄的逆序列表。
def age(a,b,n,cnt):
    if a+b>120:
        print('Age {} is larger than 120!'.format(cnt))
        return []
    elif n==1:
        return [a+b]
    else:
        return age(b,a+b,n-1,cnt+1)+[a+b]
x,n=eval(input())
print(age(3,x,n-2,3)+[x,3])


