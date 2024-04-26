class Event:
    def __init__(self, event_list: dict):
        self.__uid = event_list.get('UID', -1)

        self.__name = event_list.get('Name', 'N/A')

        self.__date = event_list.get('Date', 'N/A')

        self.__start_time = event_list.get('StartTime', 'N/A')

        self.__location = event_list.get('Location', 'N/A')

        self.__duration = event_list.get('Duration', 0)

    @property
    def uid(self) -> int:
        return self.__uid

    @property
    def name(self) -> str:
        return self.__name

    @property
    def date(self) -> str:
        return self.__date

    @property
    def start_time(self) -> str:
        return self.__start_time

    @property
    def location(self) -> str:
        return self.__location

    @property
    def duration(self) -> int:
        return self.__duration

    # This function defines what happens when you print the object as text i.e., print(Event)
    def __str__(self) -> str:
        """
        python has a few ways of streamlining concatenation of strings.
        each time there's a {} in the string that represents a variable.
        notice at the end of the string, ".format()"
        the variables passed into this function will replace each {} (in order)
        """
        return "Event: {}\nDate: {}\nStart time: {}\nDuration: {} hours\nLocation: {}" \
            .format(self.name, self.date, self.start_time, self.duration, self.location)

    def __eq__(self, other: 'Event') -> bool:
        return self.__name == other.name and \
            self.__uid == other.uid and \
            self.__date == other.date and \
            self.__start_time == other.start_time and \
            self.__location == other.location and \
            self.__duration == other.duration
