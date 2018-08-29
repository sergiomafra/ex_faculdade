from abc import ABC, abstractmethod
from numpy import loadtxt
import re

class BaseGraph(ABC):

    sscomp = re.compile('(\w+,\w+)')

    def __init__(self, graphfilename):
        """ Initialise the Graph object """

        self.vertexes = []

        """
        Opening a file in a variable to be used thoughtout the script.
        Not recommended, but the program is designed to be short and not
        consume much memory
        """

        print( type(graphfilename) )

        self.graphfilename = open(graphfilename, 'r')

        if graphfilename == 'va.txt':
            self._create_graph_from_va()
        elif graphfilename == 'matrix.txt':
            self._create_graph_from_matrix()

    """
    Import vertexes from va and matrix files
    """

    def _import_vertexes_from_va(self, line):

        return [Vertex(vertex) for vertex in \
                line(0).strip('V A \n = [ ]').split(',')]

    #def _import_vertexes_from_matrix(self, line):

    #    return [Vertex(vertex) for vertex in line]

    """
    Import straight segments (future edges or arcs) from va and matrix files
    """

    @abstractmethod
    def _import_straight_segments_from_va(self, line):

        ss = sscomp.findall(line)

    #@abstractmethod
    #def _import_straight_segments_from_matrix(self):

    """
    Graph creation abstract methods
    """

    @abstractmethod
    def _create_graph_from_va(self):

        # Capturing lines from file
        lines = [line for line in self.graphfile.readlines()]

        # Importing vertexes
        self.vertexes = _import_vertexes_from_va(lines[0])

    #@abstractmethod
    #def _create_graph_fr_om_matrix(self):
