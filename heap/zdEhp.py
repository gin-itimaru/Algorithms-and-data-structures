import sys
import heapq

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    numbers = [int(x) for x in input_data[1:]]
    heapq.heapify(numbers)
    
    total_intermediate_sum = 0
    
    while len(numbers) > 1:
        first = heapq.heappop(numbers)
        second = heapq.heappop(numbers)
        
        current_sum = first + second
        total_intermediate_sum += current_sum
        
        heapq.heappush(numbers, current_sum)
    total_cost = total_intermediate_sum * 0.05
    
    print(f"{total_cost:.2f}")

if __name__ == '__main__':
    main()
