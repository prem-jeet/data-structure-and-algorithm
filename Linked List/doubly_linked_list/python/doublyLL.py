class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class doublyLL:
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    # METHOD TO INSERT AT BEGINNING
    def insert_at_beginning(self, data):
        self.count += 1
        new_node = Node(data)

        if(self.count == 1):
            self.head = new_node
            self.tail = new_node
            return

        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    # METHOD TO INSERT AT END
    def insert_at_end(self, data):
        self.count += 1
        new_node = Node(data)

        if(self.count == 1):
            self.head = new_node
            self.tail = new_node
            return

        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    # METHOD TO INSERT AT GIVEN POSITION
    def insert_at_position(self, position, data):
        if(position < 1 or position > self.count+1):
            print("Incalid position.")
            return

        if position == 1:
            self.insert_at_beginning(data)
            return
        if position == self.count+1:
            self.insert_at_end(data)
            return

        ptr = self.head
        index = 1
        while(index != position):
            index += 1
            ptr = ptr.next

        new_node = Node(data)

        new_node.next = ptr
        new_node.prev = ptr.prev
        ptr.prev.next = new_node
        ptr.prev = new_node
        self.count += 1

    # METHOD TO DELETE FROM BEGINNING
    def delete_from_beginning(self):
        if(self.count == 0):
            print("Empty list.")
            return

        self.count -= 1
        self.head = self.head.next
        if(self.count != 0):
            self.head.prev = None

    # METHOD TO DELETE FROM END
    def delete_from_end(self):
        if(self.count == 0):
            print("Empty list.")
            return

        self.count -= 1
        self.tail = self.tail.prev
        if(self.count != 0):
            self.tail.next = None

    # METHOD TO DELETE FROM GIVEN POSITION
    def delete_from_position(self, position):
        if(position < 1 or position > self.count):
            print("Invalid Position.")
            return
        if(position == 1):
            self.delete_from_beginning()
            return
        if(position == self.count):
            self.delete_from_end()
            return

        index = 1
        ptr = self.head
        while(index != position):
            index += 1
            ptr = ptr.next

        ptr.prev.next = ptr.next
        ptr.next.prev = ptr.prev
        ptr.next = None
        ptr.prev = None
        self.count -= 1

    # METHOD PRINTS THE LIST
    def print_list(self):
        ptr = self.head
        while(ptr):
            print(ptr.data, " <--> ", end="")
            ptr = ptr.next
        print("NULL")

    # METHOD CLEARS THE LIST
    def clear_list(self):
        self.head = None
        self.tail = None
        self.count = 0

    # METHOD RETURNS THE NUMBER OF ELEMENTS IN THE LIST
    def size(self):
        return self.count
