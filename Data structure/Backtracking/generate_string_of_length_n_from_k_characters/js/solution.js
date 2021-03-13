class Solution {
  generate_string(input_array, string_length) {
    let output_array = new Array(string_length);

    this.generate_string_helper(
      input_array,
      output_array,
      string_length,
      string_length
    );
  }

  generate_string_helper(input_array, output_array, index, string_length) {
    if (!index) {
      this.print_array(output_array);
      return;
    }

    for (let item in input_array) {
      output_array[string_length - index] = input_array[item];
      this.generate_string_helper(
        input_array,
        output_array,
        index - 1,
        string_length
      );
    }
  }

  print_array(arr) {
    console.log(arr.join(""));
  }
}

module.exports = {
  Solution,
};
