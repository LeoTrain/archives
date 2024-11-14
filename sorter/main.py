class Sorter:
    def swap(self, a, b, to_swap):
        temp = to_swap[a]
        to_swap[a] = to_swap[b]
        to_swap[b] = temp

    def replace(self, l1, l2) -> None:
        for i in range(len(l2)):
            l1[i] = l2[i]

    def bubble(self, to_sort) -> None:
        sorted = True
        i = 0

        for i in range(len(to_sort) - 1):
            if to_sort[i] > to_sort[i+1]:
                sorted = False

        while not sorted:
            if to_sort[i] > to_sort[i + 1]:
                self.swap(i, i + 1, to_sort)
                i = 0
            else:
                i += 1
                if i == len(to_sort) - 1:
                    sorted = True

    def insertion(self, to_sort) -> None:
        sorted_list = []
        for i in range(len(to_sort)):
            to_place = to_sort[i]
            if not sorted_list:
                sorted_list.append(to_place)
            else:
                placed = False
                for j in range(len(sorted_list)):
                    if to_place < sorted_list[j]:
                        sorted_list.insert(j, to_place)
                        placed = True
                        break
                if not placed:
                    sorted_list.append(to_place)
        self.replace(to_sort, sorted_list)


if __name__ == "__main__":
    sorter = Sorter()
    ages = [10, 20, 33, 40, 50]
    print(*ages)
    sorter.bubble(ages)
    print(*ages)
