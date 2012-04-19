ms = {}
n = int(raw_input())
earn = [0]*(n + 1)
lwin = 0
flag = 0

for i in xrange(n):
    action, x = raw_input().split()
    if (action[0] == 'w'):
        if (flag == 1):
            flag = 0
            ms.clear ()

        ms[x] = 1
        earn[i + 1] = earn[i]
        lwin = earn[i]
    else:
        flag = 1
        if (ms.has_key(x)):
            if (lwin + 2**int(x) > earn[i]):
                earn[i + 1] = lwin + 2**int(x)
                del ms[x]
            else:
                earn[i + 1] = earn[i]
        else:
            earn[i + 1] = earn[i]

print earn[n]
