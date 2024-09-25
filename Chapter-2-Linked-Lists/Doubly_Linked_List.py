
# Doubly Linked List Intialization
class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

class Doubly_linked_list:
    def __init__(self):
        self.head = None
        self.tail = None

    # Inserting a value at the beginning
    def insert_at_beginning(self, val):
        new_node = Node(val)

        if self.head is None:
            self.head = new_node
            new_node.prev = None
            self.tail = new_node
            return
        else:
            temp = self.head
            self.head = new_node
            new_node.prev = None
            new_node.next = temp
            temp.prev = new_node

    # Insertion at the end
    def insert_at_end(self, val):
        new_node = Node(val)

        if self.tail is None:
            self.insert_at_beginning(val)
            return
        current = self.tail
        current.next = new_node
        new_node.prev = current
        self.tail = new_node

    # Insertion at a specific position
    def insert_at(self, index, val):
        new_node = Node(val)
        if index == 0:
            self.insert_at_beginning(val)
            return
        current = self.head
        i = 0
        while current is not None and i < index:
            current = current.next
            i += 1
        if current is None:  # If index is out of bounds
            print(f"Index {index} is out of bounds")
            return
        if current.prev is None:  # If we're inserting at the end
            self.insert_at_end(val)
            return
        prev_node = current.prev  # Get the previous node
        new_node.prev = prev_node
        new_node.next = current
        prev_node.next = new_node
        current.prev = new_node

    # Deletion at the beginning
    def delete_at_beginning(self):
        if(self.head == self.tail):
            self.head = None
            self.tail = None
            return
        current = self.head
        self.head = current.next
        self.head.prev = None

    # Deletion at the end
    def delete_at_end(self):

        if (self.head == self.tail):
            self.head = None
            self.tail = None

        current = self.tail.prev
        current.next = None
        self.tail = current

    # Deletion at an arbitrary index or specific index
    def delete_at(self, index):

        if(index == 0):
            self.delete_at_beginning()
            return
        current = self.head
        i = 0
        while current is not None and i < index:
            current = current.next
            i += 1
        if current is None:
            raise IndexError("index out of bounds")
        if(current == self.tail):
            self.delete_at_end()
            return
        prev_node = current.prev
        next_node = current.next
        prev_node.next = next_node
        next_node.prev = prev_node
        return

    # Traversing a linked list
    def printList(self):

        current = self.head
        while current is not None:
            print(f'{current.val} ->', end='')
            current = current.next
        print('None')

    # Traversing a linked list from tail or Backwards
    def traverse_from_end(self):

        current = self.tail
        while current is not None:
            print(f'{current.val} ->', end= '')
            current = current.prev
        print('None')

    # Finding the length of the linked list
    def length(self):
        count = 0
        current = self.head
        while current is not None:
            current = current.next
            count += 1
        return count

    # Searching an element in a linked list
    def search(self, val):

        current = self.head
        count = 0
        while current is not None:
            if(current.val == val):
                return f"the value found at index {count}"
            current = current.next
            count += 1
        return "the val doesn\'t exist in the list"

