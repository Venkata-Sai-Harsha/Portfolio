import random

class Node:
    def __init__(self, id, m):
        self.id = id
        self.m = m
        self.finger_table = [None] * m
        self.predecessor = None

    def __str__(self):
        return str(self.id)

class ChordRing:
    def __init__(self, m):
        self.m = m
        self.ring = []

    def initialize_ring(self, initial_nodes):
        for node_id in initial_nodes:
            self.add_node(node_id)

    def add_node(self, node_id):
        new_node = Node(node_id, self.m)
        if not self.ring:
            new_node.predecessor = new_node
            for i in range(self.m):
                new_node.finger_table[i] = new_node
            self.ring.append(new_node)
        else:
            for node in self.ring:
                if node.id == node_id:
                    print(f"Node {node_id} already exists in the ring.")
                    return
            self.ring.append(new_node)
            self.ring.sort(key=lambda x: x.id)
            self.update_finger_tables()

    def remove_node(self, node_id):
        for node in self.ring:
            if node.id == node_id:
                self.ring.remove(node)
                self.update_finger_tables()
                return
        print(f"Node {node_id} not found in the ring.")

    def lookup(self, key, start_node_id):
        start_node = next((node for node in self.ring if node.id == start_node_id), None)
        if not start_node:
            print(f"Error: Node {start_node_id} not found in the ring.")
            return None, None

        path = [start_node_id]
        current_node = start_node
        while True:
            if current_node.id == key:
                return path, current_node.id
            for i in range(self.m):
                if current_node.finger_table[i].id >= key:
                    next_node = current_node.finger_table[i]
                    break
            else:
                next_node = current_node.finger_table[0]
            if next_node.id == key or next_node.id == start_node.id:
                return path, next_node.id
            path.append(next_node.id)
            current_node = next_node

    def update_finger_tables(self):
        for node in self.ring:
            for i in range(self.m):
                start = (node.id + 2**i) % (2**self.m)
                node.finger_table[i] = self.find_successor(start)

    def find_successor(self, key):
        for node in self.ring:
            if node.id >= key:
                return node
        return self.ring[0]

    def display_finger_table(self, node_id):
        node = next((node for node in self.ring if node.id == node_id), None)
        if not node:
            print(f"Node {node_id} not found in the ring.")
            return
        print(f"Finger table for node {node_id}:")
        for i, finger in enumerate(node.finger_table):
            print(f"Start: {(node.id + 2**i) % (2**self.m)}, Successor: {finger.id}")

    def display_ring(self):
        print("Current Chord ring:")
        for node in self.ring:
            print(f"Node {node.id}, Predecessor: {node.predecessor.id if node.predecessor else None}, Finger table: {[f.id for f in node.finger_table]}")

def main():
    m = 6  # Identifier space is 6 bits, so we have 2^6 = 64 possible node IDs
    chord = ChordRing(m)
    initial_nodes = random.sample(range(2**m), 5)
    chord.initialize_ring(initial_nodes)
    chord.display_ring()

    while True:
        print("\n1. Look up a key")
        print("2. Add a node to the ring")
        print("3. Remove a node from the ring")
        print("4. Display the finger table for a given node")
        print("5. Exit the ring")
        choice = input("Enter your choice: ")

        if choice == "1":
            key = int(input("Enter the key to look up: "))
            start_node = int(input("Enter the initial node id: "))
            path, responsible_node = chord.lookup(key, start_node)
            if path and responsible_node:
                print(f"Key {key} is handled by node {responsible_node}. Path: {path}")
        elif choice == "2":
            node_id = int(input("Enter the node id to add: "))
            chord.add_node(node_id)
            chord.display_ring()
        elif choice == "3":
            node_id = int(input("Enter the node id to remove: "))
            chord.remove_node(node_id)
            chord.display_ring()
        elif choice == "4":
            node_id = int(input("Enter the node id to display finger table: "))
            chord.display_finger_table(node_id)
        elif choice == "5":
            print("Exiting simulation.")
            break
        else:
            print("Invalid choice. Please try again.")

    print("Name: sai harsha")
    print("Roll Number: AM.EN.U4CSE21443")

if __name__ == "__main__":
    main()
