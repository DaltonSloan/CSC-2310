from EventAttendee import EventAttendee
from Event import Event
from Contact import Contact

'''
This file is where the bulk of your work will be done. 
I have listed each category of method you will need to create in the comments.
I have also listed how many methods will appear in each category.
'''


class EventManager:
    """
    This class is meant to manage the Events, Contacts, and Event_Attendees.
    This class also directly communicates with the GUI as the GUI "has" an EventManager object (aggregation).
    This class has a list of Event objects, a list of Contact objects, and a list of EventAttendee objects.
    """

    # constructor (1 method)
    def __init__(self):
        self.__contacts = []
        self.__events = []
        self.__event_attendees = []
        self.__eventUID = 0
        self.__contactUID = 0

    # getters (5 methods)
    @property
    def contacts(self):
        return self.__contacts

    @property
    def events(self):
        return self.__events

    @property
    def event_attendees(self):
        return self.__event_attendees

    @property
    def eventUID(self):
        return self.__eventUID

    @property
    def contact_uid(self):
        return self.__contactUID

    # setters (5 methods)
    @contacts.setter
    def contacts(self, contacts):
        self.__contacts = contacts

    @events.setter
    def events(self, events):
        self.__events = events

    @event_attendees.setter
    def event_attendees(self, event_attendees):
        self.__event_attendees = event_attendees

    @eventUID.setter
    def eventUID(self, eventUID):
        self.__eventUID = eventUID

    @contact_uid.setter
    def contact_uid(self, contactUID):
        self.__contactUID = contactUID

    # other methods (6 methods)
    def add_event(self, event_dict: dict) -> None:
        event = Event(event_dict)
        self.__events.append(event)
        self.__eventUID += 1
        self._sort_events()

    def add_contact(self, contact_dict: dict) -> None:
        contact = Contact(contact_dict)
        self.__contacts.append(contact)
        self.__contactUID += 1
        self._sort_contacts()

    def is_attending(self, contact: Contact, event: Event) -> bool:
        for attendee in self.__event_attendees:
            if attendee.contact == contact and attendee.event == event:
                return True
        return False

    def add_event_attendee(self, event: Event, contact: Contact) -> None:
        if not self.is_attending(contact, event):
            event_attendee = EventAttendee(event, contact)
            self.__event_attendees.append(event_attendee)

    def uid_to_event(self, uid: int):
        for event in self.__events:
            if event.uid == uid:
                return event
            else:
                return None

    def uid_to_contact(self, uid: int):
        for contact in self.__contacts:
            if contact.uid == uid:
                return contact
            else:
                return None

    # pre-existing methods (2 methods; they are already here; no need to touch them)

    def _sort_contacts(self) -> None:
        """
        Sort contacts by their last name
        :returns: None
        """
        # sort the list by lastname (alphabetically)
        self.contacts.sort(key=lambda x: x.lastname)

    def _sort_events(self) -> None:
        """
        Sort the stored events by date
        :returns: None
        """
        self.events.sort(key=lambda x: x.date, reverse=False)
