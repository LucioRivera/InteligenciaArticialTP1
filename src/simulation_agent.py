from impostor import Impostor
from room import Room
from skeld import Skeld
import numpy as np

class SimulationAgent:
    def __init__(self, a_init_energy, crewmates, a_init_sabotageables):
        self.impostor = Impostor(a_init_energy, a_init_sabotageables)
        self.skeld = Skeld(crewmates, self.impostor.room, a_init_energy, a_init_sabotageables)

    def simulate(self):
        step = 0
        while step < 1000 and not self.skeld.agent_succeded() and not self.skeld.agent_failed():
            perception = self.skeld.get_perception()
            self.impostor.see(perception)
            action = self.impostor.select_action()
            if action == None:
                break;
            self.skeld.update(action)
            step += 1

        if self.skeld.agent_succeded():
            print("EL AGENTE GANOOO")
        else:
            print("EL AGENTE PERDIO SADGE PEPOSAD")

def main():
    initial_energy = np.random.randint(30, 151)
    initial_crewmates = np.random.randint(3, 6)
    sab_rooms = {Room("electrical"), Room("reactor"), Room("weapons")}
    sim_agent = SimulationAgent(initial_energy, initial_crewmates, sab_rooms)
    sim_agent.simulate()


if __name__ == "__main__":
    main()