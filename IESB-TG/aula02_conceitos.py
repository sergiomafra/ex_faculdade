from classes import Arc

arcs = [('v','d'), ('d','f'), ('v','w'), ('w','f'), ('a','v'), ('a','c')]

for arc in arcs:
    new_arc = Arc(arc[0], arc[1])
    print(new_arc.__str__())
