from skeld_structure import SkeldStructure
import numpy as np


class Impostor:

    def __init__(self, energy, sabotages):
        self.map = SkeldStructure()
        self.energy = energy
        self.room = np.random.choice(self.map.rooms)
        self.sabotages_left = sabotages
        self.crewmates = []

    def see(self, perception):
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


def main():
    pass


if __name__ == "__main__":
    main()
