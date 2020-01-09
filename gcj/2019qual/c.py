
def gcd2(u, v):
    if u == 0: return v
    if v == 0: return u
    return gcd2(v, u%v)
    
def gcd(u, v):
	if u == v: return u
	if u == 0: return v
	if v == 0: return u
	if u % 2 == 0 and v % 2 == 0:
		return 2 * gcd(u//2, v//2)
	if u % 2 == 0:
		return gcd(u//2, v)
	if v % 2 == 0:
		return gcd(u, v//2)
	if u >= v:	# both are odd
		return gcd((u-v)//2, v)
	else:
		return gcd((v-u)//2, u)

N = int(raw_input())
for ca in range(1, N+1):
	tmp = raw_input().split(" ")
	n = int(tmp[0])
	L = int(tmp[1])
	tmp = raw_input().split(" ")
	a = [int(x) for x in tmp]
	if len(a) != L:
	    continue
	x = gcd2(a[0], a[1])
	p = [0] * (L+1)
	p[0] = a[0] // x
	for i in range(0, L):
		p[i+1] = a[i] // p[i]
	primes = sorted(set(p))
	ans = ""
	for item in p:
	    idx = 0
	    for x in primes:
	        if x == item: break
	        idx = idx + 1
	    print idx
		ans = ans + chr(ord('A') + idx)
	print "Case #{}: {}".format(ca, ans)
