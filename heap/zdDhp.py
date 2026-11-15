import heapq
import sys

heap = []
output = []

for line in sys.stdin:
    parts = line.split()
    if not parts:
        continue
        
    cmd = parts[0] 
    if cmd == 'CLEAR':
        heap.clear()
    elif cmd == 'ADD':
        heapq.heappush(heap, -int(parts[1])) 
    else:
        if heap:
            max_val = -heapq.heappop(heap) 
            output.append(str(max_val))
        else:
            output.append('CANNOT')
sys.stdout.write('\n'.join(output) + '\n')
