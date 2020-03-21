class Date:
    _day = _month = _year = None

    def __init__(self, day: int, month: int, year: int):
        self.day = day
        self.year = year
        self.month = month

    @property
    def day(self) -> int:
        return self._day

    @day.setter
    def day(self, value: int):
        if value > 31 or value < 1:
            raise ValueError('invalid date.')
        self._day = int(value)

    @property
    def month(self) -> int:
        return self._month

    @month.setter
    def month(self, value: int):
        if value > 12 or value < 1:
            raise ValueError('invalid date.')
        if value in (4, 6, 9, 11) and self.day > 30:
            raise ValueError('invalid date.')
        if value == 2 and self.day > 29:
            raise ValueError('invalid date.')
        if not self.is_leap_year(self.year) and self.day > 28:
            raise ValueError('invalid date.')
        self._month = int(value)

    @property
    def year(self) -> int:
        return self._year

    @year.setter
    def year(self, value: int):
        if value < 1:
            raise ValueError('invalid date.')
        self._year = int(value)

    @staticmethod
    def is_leap_year(year: int) -> bool:
        return (year % 4 == 0 and year % 100 != 0) or year % 400 == 0

    def __repr__(self):
        return f'{self.day:0>2}/{self.month:0>2}/{self.year:0>4}'
