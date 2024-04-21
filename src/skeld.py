from skeld_structure import SkeldStructure
from crewmate import Crewmate
import numpy as np

class Skeld:
	def __init__(self, crewmate_ammount):
		self.map = SkeldStructure()
		rooms = self.map.rooms
		self.crewmates = [Crewmate(np.random.choice(rooms)) for _ in range(crewmate_ammount)]
		self.agent_sensor_timer = 0


	def get_perception(self):
		if self.agent_sensor_timer == 0:
			self.agent_sensor_timer = np.random.randint(3, 6)
			return self.crewmates
		else:
			adjacency = self.map.get_neighbors(self.agent_room) + self.agent_room
			return [c if c in adjacency else None for c in self.crewmates]


def main():
	pass
	#s = Skeld(5)
	#print([str(c.actual_room) for c in s.crewmates])

if __name__ == "__main__":
	main()
