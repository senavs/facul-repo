from datetime import datetime

from date import Date
from timer import Time


class DateTime:

    @classmethod
    def now(cls):
        return datetime.now()

    @property
    def date(self) -> 'Date':
        now = self.now()
        return Date(now.day, now.month, now.year)

    @property
    def time(self) -> 'Time':
        now = self.now()
        return Time(now.hour, now.minute, now.second)

    def __repr__(self):
        return f'{self.date.__repr__()} {self.time.__repr__()}'
