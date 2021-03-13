class Solution {
  generate_string(n) {
    let arr = new Array(n).fill(0);
    this.generate_string_helper(arr, n, n);
  }

  generate_string_helper(arr, n, size) {
    if (!n) {
      console.log(arr.join(""));
      return;
    }

    arr[size - n] = 0;
    this.generate_string_helper(arr, n - 1, size);
    arr[size - n] = 1;
    this.generate_string_helper(arr, n - 1, size);
  }
}

module.exports = {
  Solution,
};
