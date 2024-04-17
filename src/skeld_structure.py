from room import Room

class SkeldStructure:
    def __init__(self):
        self.map = {}
        upper_engine = Room("upper_engine")
        cafeteria = Room("cafeteria")
        weapons = Room("weapons")
        reactor = Room("reactor")
        security = Room("security")
        medbay = Room("medbay")
        o2 = Room("o2")
        navigation = Room("navigation")
        lower_engine = Room("lower_engine")
        electrical = Room("electrical")
        storage = Room("storage")
        admin = Room("admin")
        communication = Room("communication")
        shields = Room("shields")
        self.rooms = [upper_engine, cafeteria, weapons, reactor, security, medbay, o2, navigation,
                      lower_engine, electrical, storage, admin, communication, shields]
        self.add_edge(navigation, o2)
        self.add_edge(navigation, weapons)
        self.add_edge(navigation, shields)
        self.add_edge(o2, weapons)
        self.add_edge(o2, shields)
        self.add_edge(weapons, shields)
        self.add_edge(weapons, cafeteria)
        self.add_edge(admin, cafeteria)
        self.add_edge(admin, storage)
        self.add_edge(communication, shields)
        self.add_edge(communication, storage)
        self.add_edge(shields, storage)
        self.add_edge(storage, cafeteria)
        self.add_edge(storage, electrical)
        self.add_edge(storage, lower_engine)
        self.add_edge(electrical, lower_engine)
        self.add_edge(cafeteria, medbay)
        self.add_edge(cafeteria, upper_engine)
        self.add_edge(medbay, upper_engine)
        self.add_edge(upper_engine, security)
        self.add_edge(upper_engine, reactor)
        self.add_edge(upper_engine, lower_engine)
        self.add_edge(lower_engine, security)
        self.add_edge(lower_engine, reactor)
        self.add_edge(reactor, security)

    def add_edge(self, a, b, weight=1):
        if a not in self.map:
            self.map[a] = []
        if b not in self.map:
            self.map[b] = []

        self.map[a].append((b, weight))
        self.map[b].append((a, weight))

    def get_neighbors(self, node):
        if node not in self.map:
            raise Exception("Room not in Map")

        return [room[0] for room in self.map[node]]

def main():
    s = SkeldStructure()
    print(s.get_neighbors(Room("weapons")))
if __name__ == "__main__":
    main()

