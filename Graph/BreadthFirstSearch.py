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

n = len(graph.keys())
print(n)

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
