import heapq
import sys

def get_next_birth_time(current_time, current_population):
    wait_time = max(1000 - current_population, 1)
    return current_time + wait_time

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    n = int(input_data[0])
    populations = [int(x) for x in input_data[1:]]

    event_heap = []
    
    for i in range(n):
        first_birth = get_next_birth_time(0, populations[i])
        heapq.heappush(event_heap, (first_birth, i))

    current_pos = 0   
    current_time = 0  

    while event_heap:
        fish_time, tank_idx = heapq.heappop(event_heap)

        travel_time = abs(tank_idx - current_pos)
        arrival_time = current_time + travel_time

        if arrival_time > fish_time:
            print(fish_time)
            return

        current_pos = tank_idx
        current_time = max(arrival_time, fish_time)

        populations[tank_idx] += 1
        
        next_birth = get_next_birth_time(current_time, populations[tank_idx])
        heapq.heappush(event_heap, (next_birth, tank_idx))

if __name__ == '__main__':
    main()
