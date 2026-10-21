# Breadth First Search
# TC - O(V+E) + Queue Shifting Cost degree: number of neighbours
# SC - O(V)

graph = {
  1: [2,6],
  2: [1,3,4],
  6: [1,7,9],
  3: [2],
  4: [2,5],
  7: [6,8],
  9: [6],
  5: [4,8],
  8: [7,5]
}

def BFS(graph, firstnode):
    n = len(graph.keys())
    vis = [0]*(n+1)
    queue = [firstnode]
    vis[firstnode]=1
    bfs = []
    while queue:
      node = queue.pop(0)
      bfs.append(node)

      for neighbour in graph[node]:
        if vis[neighbour]!=1:
          vis[neighbour] = 1
          queue.append(neighbour)

    return bfs

print(BFS(graph, 1))

# Using Deque
from collections import deque

def BFS(graph, firstNode):
  n = len(graph.keys())
  vis = [0]*(n+1)
  queue = deque([firstNode])
  vis[firstNode] = 1
  bfs = []

  while queue:
    node = queue.popleft()
    bfs.append(node)
    for it in graph[node]:
      if vis[it]!=1:
        vis[it] = 1
        queue.append(it)
  return bfs

print(BFS(graph, 1))


# BFS in python
from collections import deque

def BFS(graph,firstNode):
  vis = set()
  queue = deque([firstNode])
  res = []
  vis.add(firstNode)
  while queue:
    node = queue.popleft()
    res.append(node)
    for neighbour in graph[node]:
      if neighbour not in vis:
        queue.append(neighbour)
        vis.add(neighbour)
  return res
    

graph = {
  '1': ['2','3'],
  '2': ['1', '4', '5'],
  '3': ['1','6', '7'],
  '4': ['2'],
  '5': ['2','8'],
  '6': ['3'],
  '7': ['3'],
  '8': ['5']
}

print(BFS(graph,'1'))
#              1
#            /   \
#           2     3
#          / \     \
#         4   5 --- 6
#              \
#               7

# Queue = [4,5]

# Visited = {1,2,3,4,5,6}

# Res = [1,2,3]
