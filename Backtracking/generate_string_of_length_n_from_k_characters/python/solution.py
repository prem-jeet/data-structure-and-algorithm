class Solution:
    def generate_string(this, input_array, string_length):
        output_array = [0 for i in range(string_length)]
        this.generate_string_helper(input_array, output_array, string_length)

    def generate_string_helper(this, input_array, output_array, string_length):
        if(not string_length):
            this.print_array(output_array)
            return

        for item in input_array:
            output_array[len(output_array) - string_length] = item
            this.generate_string_helper(
                input_array, output_array, string_length-1)

    def print_array(this, arr):
        [print(item, end="") for item in arr]
        print()
