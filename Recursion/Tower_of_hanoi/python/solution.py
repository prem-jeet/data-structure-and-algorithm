class Solution:
    def __init__(this):
        this.From = 'A'
        this.To = 'C'
        this.Aux = 'B'

    def toh(this, n):
        count = {
            "val": 0
        }
        this.solve(n, this.From, this.To, this.Aux, count)
        return count["val"]

    def solve(this, n, From, To, Aux, count):
        count["val"] += 1
        if(n == 1):
            print(From, " --> ", To)
            return
        this.solve(n-1, From, Aux, To, count)
        print(From, " --> ", To)
        this.solve(n-1, Aux, To, From, count)
