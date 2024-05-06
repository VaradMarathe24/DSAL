class HashTableSeparateChaining:
    def __init__(self, size=100):
        self.size = size
        self.table = [[] for _ in range(size)]  # Initialize an array of lists

    def hash_function(self, key):
        # Simple hash function using modulo operator
        return hash(key) % self.size

    def insert(self, key, value):
        # Insert key-value pair into the hash table
        index = self.hash_function(key)
        # Check if key already exists and update value if necessary
        for pair in self.table[index]:
            if pair[0] == key:
                pair[1] = value
                return
        # Otherwise, append a new key-value pair
        self.table[index].append([key, value])

    def remove(self, key):
        # Remove a key-value pair from the hash table
        index = self.hash_function(key)
        for i, pair in enumerate(self.table[index]):
            if pair[0] == key:
                del self.table[index][i]
                return

    def find(self, key):
        # Find a key in the hash table
        index = self.hash_function(key)
        comparisons = 0
        for pair in self.table[index]:
            comparisons += 1
            if pair[0] == key:
                return pair[1], comparisons
        return None, comparisons

# Usage of HashTableSeparateChaining
ht_separate_chaining = HashTableSeparateChaining()

# Insert clients and their telephone numbers
clients = [
    ("Alice", "123-456-7890"),
    ("Bob", "234-567-8901"),
    ("Charlie", "345-678-9012"),
    # Add more clients as needed
]

# Inserting clients into the hash table
for client, number in clients:
    ht_separate_chaining.insert(client, number)

# Finding telephone numbers and counting comparisons
keys_to_find = ["Alice", "Bob", "Charlie", "Unknown"]
for key in keys_to_find:
    result, comparisons = ht_separate_chaining.find(key)
    print(f"Finding {key}: Number {result}, Comparisons: {comparisons}")
class HashTableOpenAddressing:
    def __init__(self, size=100):
        self.size = size
        self.table = [None] * size  # Initialize the hash table with None

    def hash_function(self, key):
        # Simple hash function using modulo operator
        return hash(key) % self.size

    def linear_probe(self, index):
        # Linear probing function
        return (index + 1) % self.size

    def insert(self, key, value):
        # Insert key-value pair into the hash table
        index = self.hash_function(key)
        while self.table[index] is not None and self.table[index][0] != key:
            index = self.linear_probe(index)
        self.table[index] = (key, value)

    def remove(self, key):
        # Remove a key-value pair from the hash table
        index = self.hash_function(key)
        while self.table[index] is not None:
            if self.table[index][0] == key:
                self.table[index] = None
                return
            index = self.linear_probe(index)

    def find(self, key):
        # Find a key in the hash table
        index = self.hash_function(key)
        comparisons = 0
        while self.table[index] is not None:
            comparisons += 1
            if self.table[index][0] == key:
                return self.table[index][1], comparisons
            index = self.linear_probe(index)
        return None, comparisons

# Usage of HashTableOpenAddressing
ht_open_addressing = HashTableOpenAddressing()

# Inserting clients into the hash table
for client, number in clients:
    ht_open_addressing.insert(client, number)

# Finding telephone numbers and counting comparisons
for key in keys_to_find:
    result, comparisons = ht_open_addressing.find(key)
    print(f"Finding {key}: Number {result}, Comparisons: {comparisons}")
