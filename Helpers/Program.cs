namespace Helpers
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*TestBaseConverter();*/
            /*TestMath();*/
            TestSorters();
        }

        static void TestMath()
        {
            MathHelper math = new MathHelper();

            Console.WriteLine(math.Factorial(3));
            Console.WriteLine(math.Factorial(4));
        }

        static void TestBaseConverter()
        {
            BaseConverter converter = new BaseConverter("1F", 16);

            Console.WriteLine(converter.ToDecimal());
            Console.WriteLine(converter.ToBinary());
            Console.WriteLine(converter.ToHexadecimal());
        }

        static void TestSorters()
        {
          Sorter sorter = new Sorter();
          int[] sortedArrayBubble = sorter.Bubble([10, 2, 7, 3, 1, 5]);
          foreach (int nbr in sortedArrayBubble) Console.WriteLine(nbr);
          int[] sortedArrayQuick = sorter.Quick([10, 2, 7, 3, 1, 5]);
          foreach (int nbr in sortedArrayQuick) Console.WriteLine(nbr);
        }
    }
}
