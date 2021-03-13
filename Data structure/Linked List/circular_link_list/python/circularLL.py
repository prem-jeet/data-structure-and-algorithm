class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class circularLL:
    def __init__(self):
        self.head = None
        self.count = 0

    # METHOD TO INSERT AT BEGINNING
    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = new_node

        self.count += 1

        if(self.head == None):
            self.head = new_node
            return

        ptr = self.head
        while(ptr.next != self.head):
            ptr = ptr.next

        new_node.next = self.head
        ptr.next = new_node
        self.head = new_node

    # METHOF TO INSERT AT END
    def insert_at_end(self, data):
        new_node = Node(data)
        new_node.next = new_node

        self.count += 1

        if(self.head == None):
            self.head = new_node
            return

        ptr = self.head
        while(ptr.next != self.head):
            ptr = ptr.next

        new_node.next = self.head
        ptr.next = new_node

    # METHOD TO INSERT AT GIVEN POSITION
    def insert_at_position(self, position, data):
        if(position < 1 or position > self.count+1):
            print("Invalid position.")
            return

        if(position == 1):
            self.insert_at_beginning(data)
            return

        if(position == self.count+1):
            self.insert_at_end(data)
            return

        self.count += 1
        index = 1
        position -= 1
        new_node = Node(data)

        while(index != position):
            index += 1
            ptr = ptr.next

        new_node.next = ptr.next
        ptr.next = new_node

    # METHOD TO DELETE FROM BEGINNING
    def delete_from_beginning(self):
        if(self.count == 0):
            print("empty list.")
            return

        self.count -= 1

        if(self.count == 0):
            self.head = None
            return

        ptr = self.head
        while(ptr.next != self.head):
            ptr = ptr.next

        ptr.next = self.head.next
        self.head = ptr.next

    # METHOD TO DELET FROM END
    def delete_from_end(self):
        if(self.count == 0):
            print("empty list.")
            return

        self.count -= 1

        if(self.count == 0):
            self.head = None
            return

        ptr = self.head
        while(ptr.next.next != self.head):
            ptr = ptr.next

        ptr.next.next = None
        ptr.next = self.head

    # METHOD TO DELETE FROM A GIVEN POSITION
    def delete_from_position(self, position):
        if(position < 1 or position > self.count):
            print("Invalid position.")
            return

        if(position == 1):
            self.delete_from_beginning()
            return

        if(position == self.count):
            self.delete_from_end()
            return

        self.count -= 1
        index = 1
        position -= 1
        ptr = self.head
        while(index != position):
            index += 1
            ptr = ptr.next

        ptr.next = ptr.next.next

    # METHOD TO PRINT THE LIST
    def print_list(self):
        if self.count == 0:
            print("Empty list")
            return

        ptr = self.head
        print(ptr.data, " -> ", end="")

        while(ptr.next != self.head):
            ptr = ptr.next
            print(ptr.data, " -> ", end="")
        print()
