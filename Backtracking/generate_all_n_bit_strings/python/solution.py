class Solution:
    def generate_string(this, n):
        arr = [0 for i in range(n)]
        this.generate_string_helper(arr, n, n)

    def generate_string_helper(this, arr, n, size):
        if(not n):
            this.print_array(arr, size)
            return

        arr[size-n] = 0
        this.generate_string_helper(arr, n-1, size)
        arr[size-n] = 1
        this.generate_string_helper(arr, n-1, size)

    def print_array(this, arr, size):
        [print(arr[i], end="") for i in range(size)]
        print()
