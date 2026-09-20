class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def create(n):
    points = []
    for i in range(n):
        x, y = map(int, input().split())
        p = Point(x, y)
        points.append(p)
    return points

n = int(input())
points = create(n)


points.sort(key=lambda p: p.x**2 + p.y**2)

for p in points:
    print(f"{p.x} {p.y}")
