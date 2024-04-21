class CrewmateKill():
    def __init__(self, index):
        self.killed_crewmate = index
        self.is_consumable = False

    def update(self, skeld, impostor):
        skeld.crewmates[self.killed_crewmate] = None
        impostor.crewmates[self.killed_crewmate] = None


class SabotagedRoom():
    def __init__(self, room):
        self.sabotaged_room = room
        self.is_consumable = False

    def update(self, skeld, impostor):
        impostor.sabotages_left.remove(self.room)


class MoveToRoom():
    def __init__(self, room):
        self.transition_room = room
        self.is_consumable = True

    def update(self, skeld, impostor):
        impostor.room = self.transition_room
        impostor.energy = impostor.energy - 1
