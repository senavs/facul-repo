from date_time import DateTime


class Clock:
    _instance = None

    def __new__(cls):
        if not cls._instance:
            cls._instance = DateTime()
        return super().__new__(cls)

    @property
    def instance(self) -> DateTime:
        return self._instance
