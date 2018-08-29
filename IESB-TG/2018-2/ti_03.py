class Queue:

    def __init__(self):
        self.queue = []

    def put(self, value):
        self.queue.append(value)

    def get(self):
        return self.queue.pop(0)

    def empty(self):
        return len(self.queue)

    def printqueue(self):
        print(self.queue)

if __name__ == '__main__':

    q = Queue()

    A = [[0,0,1,1,1,0], [0,0,1,0,1,0], [0,0,0,0,1,0], [0,0,0,0,1,1],
            [0,0,0,0,0,1], [0,1,0,0,0,0]]

    for row in A:
        for i, element in enumerate(row, start=0):
            if element == 1:
                q.put(i)
