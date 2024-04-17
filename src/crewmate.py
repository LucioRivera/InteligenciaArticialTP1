import numpy as np


class Crewmate:
    def __init__(self, actual_room):
        self.actual_room = actual_room
        self.move_timer = np.random.randint(1, 4)

    # Reveer
    def take_action(self, map):
        if self.move_timer == 0:
            neighbors = map.get_neighbors(self.actual_room)
            move_to = np.random.choice(neighbors)[0]
            self.actual_room = move_to
            self.move_timer = np.random.randint(1, 4)
        else:
            self.move_timer -= 1

def main():
    pass

if __name__ == "__main__":
    main()