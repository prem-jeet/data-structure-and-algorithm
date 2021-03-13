class Solution {
  constructor() {
    this.from = "A";
    this.to = "C";
    this.aux = "B";
  }

  toh(n) {
    this.count = 0;

    let solve = (m = n, from = this.from, to = this.to, aux = this.aux) => {
      this.count++;
      if (m == 1) {
        console.log(from, " --> ", to);
        return;
      }

      solve(m - 1, from, aux, to);
      console.log(from, " --> ", to);
      solve(m - 1, aux, to, from);
    };

    solve();

    return this.count;
  }
}

module.exports = {
  Solution,
};
