class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    # Inserting a value at the beginning
    def insert_at_beginning(self, val):
        new_node = Node(val)
        new_node.next = self.head
        self.head = new_node

    # Insertion at the end
    def insert_at_end(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            return
        current = self.head
        while current.next is not None:
            current = current.next
        current.next = new_node

    # Insertion at a specific position
    def insert_at(self, index, val):
        if index == 0:
            self.insert_at_beginning(val)
            return
        new_node = Node(val)
        current = self.head
        i = 0
        while current is not None and i < index - 1:
            current = current.next
            i += 1
        if current is None:
            raise IndexError("Index out of bounds")  # Changed to raise an exception
        new_node.next = current.next
        current.next = new_node

    # Traversing a linked list
    def print_linked_list(self):
        current = self.head
        while current is not None:
            print(current.val, end=" -> ")
            current = current.next
        print("None")

    # Searching an element in a linked list
    def search_element(self, target):
        current = self.head
        while current is not None:
            if current.val == target:
                return True
            current = current.next
        return False

    # Finding the length of the linked list
    def length(self):
        count = 0
        current = self.head
        while current is not None:
            count += 1
            current = current.next
        return count

    # Deletion at the beginning
    def delete_first_element(self):
        if self.head is None:
            raise IndexError("List is empty")  # Changed to raise an exception
        self.head = self.head.next

    # Deletion at the end
    def delete_at_end(self):  # Renamed from pop_element to delete_at_end
        if self.head is None:
            raise IndexError("List is empty")  # Changed to raise an exception
        if self.head.next is None:
            self.head = None
            return
        current = self.head
        while current.next.next is not None:
            current = current.next
        current.next = None

    # Deletion at an arbitrary index
    def delete_at(self, index):
        if self.head is None:
            raise IndexError("List is empty")  # Changed to raise an exception
        if index == 0:
            self.delete_first_element()
            return
        current = self.head
        i = 0
        while current is not None and i < index - 1:
            current = current.next
            i += 1
        if current is None or current.next is None:
            raise IndexError("Index out of bounds")  # Changed to raise an exception
        current.next = current.next.next

    def update(self, index, val):
        new_node = Node(val)
        current = self.head
        i = 0
        if(index == 0):
            temp = self.head
            self.head = new_node
            new_node.next = temp
        while current is not None and i < index-1:
            current = current.next
            i += 1
        temp = current.next
        current.next = new_node
        new_node.next = temp
