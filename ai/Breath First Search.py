def bfs(graph, start):
	explored = []
	queue = [start]
	while queue:
		node = queue.pop(0)
		if node not in explored:
			explored.append(node)
			neighs = graph[node]

			for ng in neighs:
				queue.append(ng)
	return explored
graph = {'A': ['B', 'C'],
         'B': ['A', 'F'],
         'C': ['A', 'D', 'E'],
         'D': ['C'],
         'E': ['C', 'H'],
         'F': ['B' , 'G'],
         'G': ['F' , 'J' , 'I'],
         'H': ['E'],
         'J': ['G'],
         'I': ['G']}
print(bfs(graph , 'A')) 
