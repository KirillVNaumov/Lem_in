def find_simple_paths(graph, start, end):
    visited = set()
    visited.add(start)

    nodestack = list()
    indexstack = list()
    current = start
    i = 0

    while True:
        # get a list of the neighbors of the current node
        neighbors = graph[current]
        # find the next unvisited neighbor of this node, if any
        while i < len(neighbors) and neighbors[i] in visited: i += 1

        if i >= len(neighbors):
            # we've reached the last neighbor of this node, backtrack
            visited.remove(current)
            if len(nodestack) < 1:
              break  # can't backtrack, stop!
            current = nodestack.pop()
            i = indexstack.pop()
        elif neighbors[i] == end:
            # yay, we found the target node! let the caller process the path
            # yield nodestack + [current, end]
            print nodestack + [current, end]
            i += 1
        else:
            # push current node and index onto stacks, switch to neighbor
            nodestack.append(current)
            indexstack.append(i+1)
            visited.add(neighbors[i])
            current = neighbors[i]
            i = 0

graph = {
    "0": ("1", "2"),
    "1": ("4"),
    "2": ("3"),
    "3": ("4"),
}

find_simple_paths(graph, "0", "4")
