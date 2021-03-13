class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Linklist:
    def __init__(self):
        self.head = None
        self.count = 0

    # METHOD TO INSERT AT THE START
    def insert_at_beginning(self, data):
        new_node = Node(data)
        self.count += 1

        if(self.head == None):
            self.head = new_node
            return

        new_node.next = self.head
        self.head = new_node

    # METHOD TO INSERT AT THE END
    def insert_at_end(self, data):
        new_node = Node(data)
        self.count += 1

        if(self.head == None):
            self.head = new_node
            return

        ptr = self.head

        while(ptr.next):
            ptr = ptr.next

        ptr.next = new_node

    # METHIOD TO INSERT AT ANY ARBITARY POSITION
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
        new_node = Node(data)
        ptr = self.head
        index = 1
        position -= 1
        while(index != position):
            index += 1
            ptr = ptr.next

        new_node.next = ptr.next
        ptr.next = new_node

    # METHOD TO DELETE FROM BEGINNING
    def delete_from_start(self):
        if(self.count == 0):
            print("The list is empty.")
            return

        self.count -= 1
        self.head = self.head.next

    # METHOD TO DELETE FROM THE END
    def delete_from_end(self):
        if(self.count == 0):
            print("The list is empty.")
            return

        self.count -= 1
        if(self.count == 1):
            self.head = None
            return

        ptr = self.head
        while ptr.next.next:
            ptr = ptr.next
        ptr.next = None

    # METHOD TO DELETE FROM ANY ARBITARY POSITION
    def delete_from_position(self, position):
        if(position < 1 or position > self.count):
            print("Invalid position.")
            return

        if(position == 1):
            self.delete_from_start()
            return
        if(position == self.count):
            self.delete_from_end()
            return

        self.count -= 1
        ptr = self.head
        index = 1
        position -= 1
        while index != position:
            index += 1
            ptr = ptr.next
        ptr.next -= ptr.next.next

    # METHOD TO RETRIEVE DATA FROM POSITION
    def get_data_from(self, position):
        if(position < 1 or position > self.count):
            print("Invalid position.")
            return None

        ptr = self.head
        index = 1
        while(index != position):
            index += 1
            ptr = ptr.next

        return ptr.data
    # METHOD TO PRINT THE LIST

    @staticmethod
    def print_list(list):
        temp = list.head
        while(temp):
            print(temp.data, " --> ", end="")
            temp = temp.next
        print("NULL")

    # METHOD RETURS THE NUMBER OF ELEMETS IN THE LIST
    def size(self):
        return self.count

    # METHOD TO CLAR THE LIST
    @staticmethod
    def clear(list):
        list.head = None
        list.count = 0
