from .Arc import Arc
from .Vertex import Vertex
from constants.constants import EARTH_RADIUS
from math import atan2, cos, pi, radians, sin, sqrt
from math import pow as mpow

class Digraph:

    def __init__(self, dados):
        self.vertexes = self._create_vertexes_from_file(dados)
        self.arcs = self._create_arcs()

    def _create_vertexes_from_file(self, dados):

        vertexes = []

        vertexes.append( Vertex('User',-15.836073,-47.912019,'User',True) )

        with open(dados, 'r') as vertex_data:
            for line in vertex_data:
                raw = line.split(';')
                latlong = raw[1].split(',')
                vertexes.append(
                    Vertex( raw[0],
                            float(latlong[0]),
                            float(latlong[1]),
                            raw[2],
                            raw[3]
                    )
                )

        return vertexes

    def _calc_distance(self, v1_la, v2_la, v1_lo, v2_lo):
        ''' Calculates distance with Haversine Formula '''

        lat1 = radians(v1_la)
        lat2 = radians(v2_la)
        delta_lat = radians(v2_la - v1_la)
        delta_lon = radians(v2_lo - v1_lo)

        a = ( mpow(sin(delta_lat/2), 2) + cos(lat1) * cos(lat2) *
            mpow(sin(delta_lon/2), 2) )

        c = 2 * atan2(sqrt(a), sqrt(1-a))

        return c * EARTH_RADIUS

    def _create_arcs(self):

        arcs = []

        for i, vertex1 in enumerate(self.vertexes[:-1], start=0):
            for vertex2 in self.vertexes[i+1:]:
                distance = self._calc_distance( vertex1.latitude,
                                                vertex2.latitude,
                                                vertex1.longitude,
                                                vertex2.longitude)
                arcs.append( Arc(vertex1, vertex2, distance) )
                arcs.append( Arc(vertex2, vertex1, distance) )

        return arcs

    def vprint(self):
        for v in self.vertexes:
            print(v)

    def aprint(self):
        for i, a in enumerate(self.arcs, start=1):
            print('{} {}'.format(i, a))
