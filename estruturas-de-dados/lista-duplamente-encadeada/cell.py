class Cell(object):
    
    def __init__(self, prv, data, nxt):
        self.previous = prv  # Type Cell
        self.data = data  # Any data
        self.next = nxt  # Type Cell
    
    def __repr__(self):  # show
        return '{"prev": %s, "data": %s, "next": %s}' % (self.previous, self.data, self.next)
    
    def __str__(self):  # show as string
        return '%s' % self.data
    
    def __del__(self):  # clear RAM
        del self
