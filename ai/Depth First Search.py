def dfs(graph, start , visited = None):
	if visited == None:
		visited = []
	if start not in visited:
		visited.append(start) 
		for ng in graph[start]:
			dfs(graph , ng , visited)
	return visited
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
print(dfs(graph , 'A')) 
