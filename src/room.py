class Room:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name

    def __eq__(self, other):
        if isinstance(other, Room):
            return self.name == other.name
        else:
            return False

    def __hash__(self):
        return hash(self.name)

def main():
    r = Room("hola")
    a = Room("hola")
    l = [r]
    print(r == a)

if __name__ == "__main__":
    main()