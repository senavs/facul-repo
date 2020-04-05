class FullQueue(OverflowError):
    pass


class EmptyList(OverflowError):
    pass


class Queue(object):

    def __init__(self, length: int):     
        self._vector = [None for item in range(0, length)]  # Queue's list
        self._N = int(length)  # Queue max length
        self._length = 0
        self._start = 0  # Index of the first element
        self._end = 0  # Index of the last element

    def to_generator(self):  # Generator with all elements in sequence
        next_element = self._start
        for c in range(0, self._N):
            yield self._vector[next_element]
            next_element = self.next_position(next_element)
            
    def to_list(self):  # Return a list of the self.queue
        return [element for element in self.to_generator()]

    def next_position(self, pos):  # Return the position of the next element
        return (pos + 1) % self._N

    def previous_position(self, pos):  # Return the position of the prev element
        return (pos - 1 + self._N) % self._N

    @property
    def first_element(self):  # Return the first element
        if self.is_empty:
            raise FullQueue("Queue is empty.")
        return self._vector[self._start]

    @property
    def last_element(self):  # Return the last element
        if self.is_empty:
            raise FullQueue("Queue is full.")
        return self._vector[self._end - 1]

    @property
    def is_empty(self):  # If the queue is empty
        return self._start == self._end

    @property
    def is_full(self):  # If the queue is full
        return self.next_position(self._end) == self._start

    def enqueue(self, item):  # Enqueue element
        if self.is_full:
            raise FullQueue("Queue is full.")        
        self._vector[self._end] = item
        self._end = self.next_position(self._end)  
        self._length += 1 

    def dequeue(self):  # Dequeue the fist element
        if self.is_empty:
            raise EmptyList("Queue is empty.")
        dequeued_item = self._vector[self._start]
        self._vector[self._start] = None
        self._start = self.next_position(self._start)
        self._length -= 1
        return dequeued_item

    def __len__(self):
        return self._length
