from Contact import Contact
from Event import Event

"""
This class represents a tuple of 1 Event and 1 Contact object, meaning the Contact is attending the Event.
This is its own class because there will be attributes associated to a contact attending an event, e.g.
whether they need a parking pass, special accommodations, etc. 

For now, the "memo" attribute is a catch-all for these, but in the future, more attributes will be added.
"""


class EventAttendee:
    def __init__(self, event: Event, contact: Contact):
        self.__event = event
        self.__contact = contact
        self.__memo = ""


    @property
    def event(self) -> Event:
        return self.__event

    @property
    def contact(self) -> Contact:
        return self.__contact

    @property
    def memo(self) -> str:
        return self.__memo

    @event.setter
    def event(self, event: Event):
        self.__event = event

    @contact.setter
    def contact(self, contact: Contact):
        self.__contact = contact

    @memo.setter
    def memo(self, memo: str):
        self.__memo = memo

    # This function defines what happens when you print the object as text, i.e. print(event_attendee)
    # PRINTS IN THE FORM "John Smith attending Data Science League Meeting"
    def __str__(self):
        """
        python has a few ways of streamlining concatenation of strings.
        each time there's a {} in the string that represents a variable.
        notice at the end of the string, ".format()"
        the variables passed into this function will replace each {} (in order)
        """
        return "{} {}\nattending\n{}".format(self.contact.firstname, self.contact.lastname, self.event.name)
