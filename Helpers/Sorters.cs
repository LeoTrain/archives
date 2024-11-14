namespace Helpers
{
    public class Sorter
    {
        public Sorter()
        {
        }

        public int[] Bubble(int[] arrayToSort)
        {
             for (int i = 0; i < arrayToSort.Length - 1; i++)
             {
               if (arrayToSort[i] > arrayToSort[i+1])
               {
                  int swap = arrayToSort[i];
                  arrayToSort[i] = arrayToSort[i+1];
                  arrayToSort[i+1] = swap;
                  i = -1;
               }
             }
             return arrayToSort;
        }

        public int[] Quick(int[] array)
        {
          if (array.Length <= 1) return array;
          int pivot = array[array.Length / 2];
          int[] left = array.Where(x => x < pivot).ToArray();
          int[] middle = array.Where(x => x == pivot).ToArray();
          int[] right = array.Where(x => x > pivot).ToArray();
          return Quick(left).Concat(middle).Concat(Quick(right)).ToArray();
        }
    }
}
