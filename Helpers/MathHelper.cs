namespace Helpers
{
    public class MathHelper
    {

        public int Factorial(int targetNumber)
        {
            int result = 1;

            if (targetNumber <= 0) return 0;

            do
            {
                result = result * targetNumber;
                targetNumber--;
            }
            while (targetNumber > 0);

            return result;
        }
    }
}
