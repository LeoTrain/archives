namespace Helpers
{
    public class BaseConverter
    {
        private int BinaryBase = 2;
        private int DecimalBase = 10;
        private int HexadecimalBase = 16;

        private string number;
        private int numberBase;

        public BaseConverter(string number, int numberBase)
        {
            this.number = number.ToUpper();
            this.numberBase = numberBase;
        }

        public string ToBinary()
        {
            return ConvertToBase(BinaryBase);
        }

        public string ToDecimal()
        {
            return ConvertToBase(DecimalBase);
        }

        public string ToHexadecimal()
        {
            return ConvertToBase(HexadecimalBase).ToUpper();
        }

        private string ConvertToBase(int targetBase)
        {
            try
            {
                int decimalValue = Convert.ToInt32(number, numberBase);
                return Convert.ToString(decimalValue, targetBase);
            }
            catch (FormatException)
            {
                throw new ArgumentException("Invalid input number or base.");
            }
        }
    }
}
