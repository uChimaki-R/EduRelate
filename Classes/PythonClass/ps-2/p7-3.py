import queue


q = queue.Queue()
ans_str = ''
n, m, k = [int(i) for i in input().strip().split(' ')]
for i in range(1, n+1):
    q.put(i)
while q.qsize() > k:
    for i in range(m-1):
        q.put(q.get())
    ans_str += (str(q.get())+' ')
print(ans_str.strip())
