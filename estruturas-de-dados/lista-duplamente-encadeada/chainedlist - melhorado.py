class Cell(object):
    
    def __init__(self, prv, data, nxt):
        self.previous = prv  # Cell type
        self.data = data  # Any type for data (int, float, str, bool, None, bytes)
        self.next = nxt  # Cell type
    
    def __repr__(self):  # show
        return '{"prev": %s, "data": %s, "next": %s}' % (self.previous, self.data, self.next)
    
    def __str__(self):  # show as string
        return '%s' % self.data
    
    def __del__(self):  # clear RAM
        del self


class ChainedListIterator(object):
    
    def __init__(self, chainedlist):
        self._beginning = chainedlist._beginning
        self._end = chainedlist._end
        self._lenth = chainedlist.length
        self.current_cell = self._beginning
        
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current_cell == self._beginning:
            self._beginning = None
            return self.current_cell
        
        self.current_cell = self.current_cell.next
        if self.current_cell is None:
            raise StopIteration
        return self.current_cell


class ChainedList(object):
    
    def __init__(self, data=None):
        self._beginning = None  # Cell type
        self._end = None  # Cell type
        self._length = 0  # New empty list
        
        if data is not None:
            for item in data:
                self.append(item)
        
    def insert(self, data, position):  # arrumar -1
        new_cell = Cell(None, data, None)
        
        if self.length  == 0 and (position == 0 or position == -1):  # First new item
            self._beginning = new_cell
            self._end = new_cell
            self._length += 1
            return
        # Others not new items
        current_cell = self[position]
        new_cell = Cell(None, data, None)
            
        if position == 0:
            new_cell.next = current_cell
            current_cell.previous = new_cell
            self._beginning = new_cell
        elif position == -1:
            self._end.next = new_cell
            new_cell.previous = self._end
            self._end = new_cell
        else:
            new_cell.previous = current_cell.previous
            new_cell.next = current_cell
            current_cell.previous.next = new_cell
            current_cell.previous = new_cell
        self._length += 1
        
    def append(self, data):
        self.insert(data, -1)
        
    def remove(self, data):
        if data not in self.to_list() or self.length == 0:
            raise  ValueError("list.remove(x): x not in list")
        
        for current_cell in self:
            if current_cell.data == data:
                if current_cell.previous is None and current_cell.next is None:
                    self._beginning = None
                    self._end = None
                elif current_cell.previous is None:
                    current_cell.next.previous = None
                    self._beginning = current_cell.next
                elif current_cell.next is None:
                    current_cell.previous.next = None
                    self._end = current_cell.previous
                else:
                    current_cell.previous.next = current_cell.next
                    current_cell.next.previous = current_cell.previous
                del current_cell
            
    def to_list(self):
        cell_list = list()
        if self._beginning is None and self._end is None:
            return cell_list
        for cell in self:
            cell_list.append(cell.data)
        return cell_list
    
    def copy(self):
        return ChainedList(self.to_list())
        
    def __getitem__(self, position):  # add -1
        if self.length == 0:  # Raise an erro if it's empty
            raise IndexError("list index out of range")     
        
        if position < 0:  # If self[-1]
            position = self.length + position
        
        if position < 0 or position >= self.length:  # Index out of the range
            raise IndexError("list index out of range")
        
        current_cell = self._beginning        
        for counter in range(0, self.length):  # If self[:]
            if counter == position:
                return current_cell
            current_cell = current_cell.next
            
    @property
    def length(self):
        return self._length
        
    def __len__(self):
        return self.length
    
    def __class__(self):
        return 'clist'
    
    def __repr__(self):
        return str(self.to_list())
    
    def __iter__(self):
        return ChainedListIterator(self)
    
    def __contains__(self, data):
        return data in self.to_list()
    
    def __reversed__(self):
        return ChainedList(reversed(self.to_list()))

