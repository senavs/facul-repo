class Time:
    _hour = _minute = _second = None

    def __init__(self, hour: int, minute: int, second: int):
        self.hour = hour
        self.minute = minute
        self.second = second

    @property
    def hour(self) -> int:
        return self._hour

    @hour.setter
    def hour(self, value: int):
        if value > 23 or value < 0:
            raise ValueError('invalid time')
        self._hour = int(value)

    @property
    def minute(self) -> int:
        return self._minute

    @minute.setter
    def minute(self, value: int):
        if value > 59 or value < 0:
            raise ValueError('invalid time')
        self._minute = int(value)

    @property
    def second(self) -> int:
        return self._second

    @second.setter
    def second(self, value: int):
        if value > 59 or value < 0:
            raise ValueError('invalid time')
        self._second = int(value)

    def __repr__(self):
        return f'{self.hour:0>2}:{self.minute:0>2}:{self.second:0>2}'
