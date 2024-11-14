import unittest
from typing import List
from collections import Counter


class DiceTester(unittest.TestCase):
    def test_grande(self):
        solution = DiceSolver([5, 5, 5, 5, 5])
        self.assertEqual(solution.solution, "grande")

    def test_poker(self):
        solution = DiceSolver([4, 4, 1, 4, 4])
        self.assertEqual(solution.solution, "poker")

    def test_full_house(self):
        solution = DiceSolver([3, 5, 5, 3, 5])
        self.assertEqual(solution.solution, "full_house")

    def test_tripple(self):
        solution = DiceSolver([4, 5, 5, 3, 5])
        self.assertEqual(solution.solution, "tripple")

    def test_doppel_zwi(self):
        solution = DiceSolver([4, 5, 4, 3, 5])
        self.assertEqual(solution.solution, "doppel_zwi")

    def test_zwi(self):
        solution = DiceSolver([4, 5, 6, 3, 5])
        self.assertEqual(solution.solution, "zwi")

    def test_strasse(self):
        solution = DiceSolver([1, 2, 3, 4, 5])
        self.assertEqual(solution.solution, "strasse")

        solution = DiceSolver([2, 3, 4, 5, 6])
        self.assertEqual(solution.solution, "strasse")


class DiceSolver:
    COMBINATIONS = {
        5: "grande",
        4: "poker",
    }

    def __init__(self, dices: List[int]) -> None:
        if len(dices) != 5:
            raise ValueError("List must have 5 int")
        if not all(isinstance(dice, int) for dice in dices):
            raise TypeError("List indices must be integers")
        self.dices = dices
        self._calculate_hits()
        self._find_solution()

    def _calculate_hits(self):
        self.hits = Counter(self.dices)

    def _find_solution(self) -> None:
        solution = ""
        pair_count = 0
        three_of_a_kind = False

        for count in self.hits.values():
            if count in self.COMBINATIONS:
                solution = self.COMBINATIONS[count]
                break
            elif count == 3:
                three_of_a_kind = True
            elif count == 2:
                pair_count += 1

        if not solution:
            if three_of_a_kind and pair_count == 1:
                solution = "full_house"
            elif three_of_a_kind:
                solution = "tripple"
            elif pair_count == 2:
                solution = "doppel_zwi"
            elif pair_count == 1:
                solution = "zwi"
            elif self._is_straight():
                solution = "strasse"

        self.solution = solution

    def _is_straight(self) -> bool:
        sorted_dices = sorted(self.dices)
        return sorted_dices == list(range(1, 6)) or sorted_dices == list(range(2, 7))


if __name__ == "__main__":
    unittest.main()
