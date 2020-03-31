class UnderFlow(Exception):
    pass


class Cell(object):
    
    def __init__(self, data, nxt):
        self._data = data
        self.next = nxt
        
    def __repr__(self):
        if self.next is not None:
            return 'Cell(%s, %s)' % (self._data, self.next._data)
        else:
            return 'Cell(%s, None)' % (self._data)


class SimpleQueue(object):
    
    def __init__(self, data=None):
        self._beginning = None
        self._end = None
        self._length = 0

        if data is not None:
            for item in data:
                self.enqueue(item)
    
    def enqueue(self, data):
        new_cell = Cell(data, None)
        if len(self) == 0:
            self._beginning = new_cell
            self._end = new_cell
        else:
            self._end.next = new_cell
            self._end = new_cell
        self._length += 1
    
    def dequeue(self):
        if len(self) == 0:
            raise UnderFlow('Queue is already empty')
        elif len(self) == 1:
            dequeued_item = self._beginning
            self._beginning = None
            self._end = None
        else:
            dequeued_item = self._beginning
            self._beginning = self._beginning.next
        self._length -= 1
        return dequeued_item._data
    
    def peek(self):
        if self._beginning is None:
            return None
        return self._beginning._data
        
    def __len__(self):
        return self._length
    
    def __repr__(self):
        if len(self) == 0:
            return '| |'
        elif len(self) == 1:
            return '| %s |' % (self.peek())
        else:
            return '| %s | +%s |' % (self.peek(), len(self) - 1)

