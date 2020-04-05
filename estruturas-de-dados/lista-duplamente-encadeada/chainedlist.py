from cell import Cell


class ChainedList(object):
    
    def __init__(self):
        self._beginning = None  # Type Cell
        self._end = None  # Type Cell
        self.length = 0  # New empty ChainedList
        
    def is_empty(self):  # True is the ChainedList is empty
        return self._beginning is None
    
    def append(self, data):  # Add a new item at the end of the ChainedList
        new_cell = Cell(None, data, None)  # Create a new empty Cell
        if self._beginning is None:  # Append if is empty
            self._beginning = new_cell
            self._end = new_cell
        else:             
            self._end.next = new_cell  # The next Cell now is new_cell
            new_cell.previous = self._end  # The previous Cell now is the last cell (self._end)
            self._end = new_cell  # The last cell now is the new cell
        self.length += 1  # Increment length
    
    def insert(self, data, position):
        if (-1 > position) or (self.length <= position):  # If position is out of the range
            raise IndexError(position)
            
        new_cell = Cell(None, data, None)  # Create a new Cell with data
        if position == 0:  # insert at the beginning
            new_cell.next = self._beginning
            self._beginning.previous = new_cell
            self._beginning = new_cell
            self.length += 1
        elif (position == self.length - 1) or (position == -1):  # insert at the end
            self.append(data)
        else:  # insert between
            seeing_cell = self._beginning.next 
            for c in range(1, self.length - 1):
                if c == position:
                    seeing_cell.previous.next = new_cell                    
                    new_cell.previous = seeing_cell.previous
                    seeing_cell.previous = new_cell
                    new_cell.next = seeing_cell
                    break
                seeing_cell = seeing_cell.next
            self.length += 1
                    
    def remove(self, data):
        if self.is_empty():  # if is empty raise and erro
            raise ValueError('ChainedList.remove(x): x not in list') 
            
        seeing_cell = self._beginning  # Starting with the beginning Cell
        while True:
            if seeing_cell.data == data:  # Comparing the seeing_cell with the data to remove
                if seeing_cell.previous is None:  # If is remove the first element
                    seeing_cell.next.previous = None
                    self._beginning = seeing_cell.next
                else:  # Removing others elements not considering the first
                    seeing_cell.previous.next = seeing_cell.next
                    if seeing_cell.next is not None:  # If remove the last element, there is no next element
                        seeing_cell.next.previous = seeing_cell.previous
                del seeing_cell  # Cleaning RAM
                self.length -= 1  # Controling the len(ChainedList)
                break
                
            if seeing_cell.next is None:  # Raise an erro is item doesn't exist in the ChainedList
                raise ValueError('ChainedList.remove(x): x not in list')
                
            seeing_cell = seeing_cell.next  # seeing_cell now is the next item/element
            
    def __len__(self):  # ChainedList length
        return self.length
    
    def __contains__(self, data):  # If x in ChainedList
        if self.is_empty():
            return False
        
        seeing_cell = self._beginning  # Starting with the beginning Cell
        while True:
            if seeing_cell.data == data:  # Comparing the seeing_cell with the data to remove
                return True
            if seeing_cell.next is None:  # Triger to stop
                break
            seeing_cell = seeing_cell.next  # next Cell
        
    
    def __repr__(self):  # Show
        if self.is_empty():
            return '[]'
        
        string = '['
        seeing_cell = self._beginning
        while True:
            # Printing the seeing_cell
            if isinstance(seeing_cell.data, str):
                string += "'%s'" % seeing_cell.data
            else:
                string += "%s"% seeing_cell.data
            # Strop triger
            if seeing_cell.next is None:
                string += ']'
                break
            else:
                string += ', '
            seeing_cell = seeing_cell.next  # seeing_cell now is the next Cell
        return string

    def __reversed__(self):  # show reversed
        if self.is_empty():
            return '[]'
        
        string = '['
        seeing_cell = self._end
        while True:
            # Printing the seeing_cell
            if isinstance(seeing_cell.data, str):
                string += "'%s'" % seeing_cell.data
            else:
                string += "%s"% seeing_cell.data
            # Strop triger
            if seeing_cell.previous is None:
                string += ']'
                break
            else:
                string += ', '
            seeing_cell = seeing_cell.previous  # seeing_cell now is the next Cell
        return string
