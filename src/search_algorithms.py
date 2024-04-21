from copy import copy
class Node():
    def __init__(agent_room, agent_energy, crewmates_room, agent_sabotage_left, node_action=None, weight=0):
        self.agent_room = agent_room
        self.agent_energy = agent_energy
        self.crewmates_room = crewmates_room
        self.agent_sabotage_left = agent_sabotage_left
        self.weight = weight
        self.node_action = node_action

    def __hash__(self):
        return hash((self.agent_room, self.agent_energy, tuple(self.crewmates_room), agent_sabotage_left))

    def __eq__(self, other):
        if isinstance(other, Node):
            return hash(self) == hash(other)
        else:
            return False

    def has_succeded(self):
        return self.agent_energy > 0 and all((c is None for c in self.crewmates_room)) and len(self.agent_sabotage_left) == 0

    def succeded_unreacheable(self):
        return self.agent_energy == 0

    def expand(self):
        expanded_nodes = {}

        #Expancion por sabotaje
        sabotaged_room = None
        for room_to_sabotage in agent_sabotage_left:
            if self.agent_room == room_to_sabotage:
                sabotaged_room = room_to_sabotage
                break

        expanded_nodes.add(Node(self.agent_room,
            self.agent_energy,
            self.crewmates_room,
            copy(self.agent_sabotage_left).pop(room_to_sabotage))

def bfs(agent_room, agent_energy, crewmates_room, agent_sabotage_left):

