from skeld_structure import SkeldStructure
import numpy as np

class Impostor:
    def __init__(self, energy, sabotages, crewmates, search_algorithm):
        self.map = SkeldStructure()
        self.energy = energy
        self.room = np.random.choice(self.map.rooms)
        self.sabotages_left = sabotages
        self.crewmates = crewmates


    def see(self, perception):
        assert(len(self.crewmates) == len(perception))
        
        for i in range(len(perception)): 
            if perception[i] is not None and self.crewmates[i] is not None:
                self.crewmates[i] = perception[i]

    def select_action(self):
        """
        search_algorithm es un objeto callable (implementa __call__) que toma como argumento el estado del agente y 
        devuelve algunas de las acciones definidas en actions.py
        """
        return search_algorithm(room, energy, crewmates, sabotages_left)

    def succeded(self):
        return self.energy > 0 and all((c is None for c in self.crewmates)) and len(self.sabotages_left) == 0

    def failed(self):
        return self.energy == 0

def main():
    pass


if __name__ == "__main__":
    main()
