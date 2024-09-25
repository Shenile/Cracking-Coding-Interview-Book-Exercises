from Singly_Linked_List import LinkedList

# list intialization ..
list = LinkedList()
for i in range(10):
    list.insert_at_end(i)
list.print_linked_list()

# optimal solution
def find_kth_element2(k, list):

    slow, fast = list.head, list.head

    for _ in range(k):
        while fast is None:
            raise IndexError('Index out of bounds')
        fast = fast.next
#   k = 2
#   [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
#    |     |
#    slow  fast

    while fast is not None:
        fast = fast.next
        slow = slow.next
#   loop will run until fast is not none, typically to the last one
#   [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] None
#                            |     |
#                            slow  fast    -> slow points the answer

    return slow.val if slow else None

print(find_kth_element2(2, list))


