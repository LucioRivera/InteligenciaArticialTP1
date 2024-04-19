from skeld_structure import SkeldStructure
import numpy as np


class Impostor:

    def __init__(self, energy, sabotages):
        self.map = SkeldStructure()
        self.energy = energy
        self.room = np.random.choice(self.map.rooms)
        self.sabotages_left = sabotages
        self.crewmates = None

    def see(self, perception):
        self.room = perception[0]
        self.energy = perception[1]
        self.sabotages_left = perception[2]

        percept_crewmates = percecption[3]
        # Inicializar los crewmates en la primera percepcion. Se asume que la primera de estas siempre es completa
        if self.crewmates == None:
            assert(None not in percept_crewmates)
            self.crewmates = percept_crewmates
        
        assert(len(percept_crewmates) == len(self.crewmates))
        for i in range(len(percept_crewmates)): 
            if percept_crewmates[i] is not None:
                self.crewmates[i] = percept_crewmates[i]

        # Metodo que tiene que actualizar el estado interno con perception
        # Perception (ImpostorRoom, ImpostorEnergy, RoomSabotagesLeft, CrewmatesRooms)
        pass
    def select_action(self):
        """
        Probablemente agregar algo, quiza al constructor estilo "bfs","mcu","astar"... para tomar la decision
        de busqueda en base a ese parametro que tenga el agente ya definido.
        El agente debe devolver una accion con su estado interno.
        Definir como se va a manejar el paso de acciones
        """
        pass

    def succeded(self):
        return self.energy > 0 and all(c is None for c in self.crewmates) and len(self.sabotages_left) == 0


    def failed(self):
        return self.energy == 0

def main():
    pass


if __name__ == "__main__":
    main()
