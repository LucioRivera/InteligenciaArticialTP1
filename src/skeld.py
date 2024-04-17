from skeld_structure import SkeldStructure
from crewmate import Crewmate
import numpy as np

class Skeld:
	def __init__(self, crewmate_ammount, agent_room, agent_energy, agent_sab_rooms):
		self.map = SkeldStructure()
		rooms = self.map.rooms
		self.crewmates = [Crewmate(np.random.choice(rooms)) for _ in range(crewmate_ammount)]
		self.agent_room = agent_room
		self.agent_energy = agent_energy
		self.agent_sab_rooms = agent_sab_rooms
		self.agent_sensor_timer = 0

	def update(self, action):
		pass

	def get_perception(self):
		if self.agent_sensor_timer == 0:
			return (self.agent_room, self.agent_energy, self.agent_sab_rooms, self.crewmates)
		else:
			adjacency = self.map.get_neighbors(self.agent_room) + self.agent_room
			return (self.agent_room, self.agent_energy, self.agent_sab_rooms,
				[c if c in adjacency else None for c in self.crewmates])

	def agent_succeded(self):
		return self.agent_energy>0 and all(c is None for c in self.crewmates) and len(self.agent_sab_rooms)==0

	def agent_failed(self):
		return self.agent_energy == 0

def main():
	pass
	#s = Skeld(5)
	#print([str(c.actual_room) for c in s.crewmates])

if __name__ == "__main__":
	main()