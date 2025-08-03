import sys
import math
from collections import defaultdict

sys.setrecursionlimit(100000)

# Định nghĩa điểm
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return (self.x, self.y) < (other.x, other.y)

    def __hash__(self):
        return hash((self.x, self.y))

    def __eq__(self, other):
        return (self.x, self.y) == (other.x, other.y)

# Tính góc giữa hai điểm
def angle(p1, p2):
    return math.atan2(p2.y - p1.y, p2.x - p1.x)

# Tính diện tích đa giác (Shoelace)
def polygon_area(poly):
    area = 0
    n = len(poly)
    for i in range(n):
        j = (i + 1) % n
        area += poly[i].x * poly[j].y - poly[j].x * poly[i].y
    return abs(area) / 2

# Tìm face bắt đầu từ cạnh (u -> v)
def trace_face(u, v, adj, visited):
    face = [u]
    start = u
    cur = v
    while True:
        face.append(cur)
        visited.add((u, cur))
        neighbors = adj[cur]

        # Tìm đỉnh trái nhất từ cur (so với hướng u -> cur)
        base_ang = angle(cur, u)
        max_ang = -1
        next_pt = None

        for nei in neighbors:
            if nei == u:
                continue
            ang = angle(cur, nei) - base_ang
            if ang <= 0:
                ang += 2 * math.pi
            if ang > max_ang:
                max_ang = ang
                next_pt = nei

        if next_pt == start:
            break
        u, cur = cur, next_pt
    return face

# Main
n = int(input())
adj = defaultdict(list)
edges = []

for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    p1 = Point(x1, y1)
    p2 = Point(x2, y2)
    adj[p1].append(p2)
    adj[p2].append(p1)
    edges.append((p1, p2))

# Sắp xếp hàng xóm của mỗi đỉnh theo góc
for p in adj:
    adj[p].sort(key=lambda q: math.atan2(q.y - p.y, q.x - p.x))

visited = set()
faces = []

# Tìm tất cả face
for p1 in adj:
    for p2 in adj[p1]:
        if (p1, p2) not in visited:
            face = trace_face(p1, p2, adj, visited)
            faces.append(face)

# Tính diện tích các face
areas = []
for face in faces:
    a = polygon_area(face)
    if a > 0:
        areas.append(a)

# Loại bỏ mặt ngoài (diện tích lớn nhất)
max_area = max(areas)
total_yield = 0
for a in areas:
    if abs(a - max_area) < 1e-6:
        continue
    total_yield += a * a

print(f"{total_yield:.6f}")
