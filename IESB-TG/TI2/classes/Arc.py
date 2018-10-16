from .Vertex import Vertex

class Arc:

    def __init__(self, base, arrow, distance):
        self.base = base
        self.arrow = arrow
        self.distance = distance

    def __str__(self):
        return '{} -> {} | distance: {}'.format(self.base.name,
                self.arrow.name, self.distance)
