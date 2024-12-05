using System;
using Figgle;

namespace titleTest
{
    public class TitleGen
    {
        private string _title;
        private int _consoleWidth;
        private int _consoleHeight;
        private int[] _startingPosition;
        private int[] _currentPosition;

        public TitleGen(string title)
        {
            _title = title.ToUpper();
            _consoleWidth = Console.WindowWidth;
            _consoleHeight = Console.WindowHeight;
            _currentPosition = CalculateStartingPosition();
            _startingPosition = CalculateStartingPosition();
        }

        public void Run()
        {
            ClearAndColor();
            Generate();
            Console.SetCursorPosition(_consoleWidth, _consoleHeight);
        }

        private void Generate()
        {
            string currentDisplayedTitle = "";
            foreach (char targetChar in _title)
            {
                currentDisplayedTitle += targetChar;
                for (char currentChar = 'A'; currentChar <= targetChar; currentChar++)
                {
                    DisplayAsciiLetter(currentChar);
                    System.Threading.Thread.Sleep(100);
                }
                DisplayCurrentTitle(currentDisplayedTitle);

            }
        }

        private void DisplayCurrentTitle(string currentTitle)
        {
            _currentPosition[0] = _startingPosition[0];
            ClearAndColor();
            string asciiArt = FiggleFonts.Standard.Render(currentTitle);
            Console.ForegroundColor = ConsoleColor.Blue;
            foreach (string line in asciiArt.Split('\n'))
            {
                Console.SetCursorPosition(_currentPosition[0], _currentPosition[1]++);
                Console.Write(line);
            }
            _currentPosition[1] = _startingPosition[1];
            _currentPosition[0] = _startingPosition[0] + asciiArt.Split('\n')[0].Length;
        }

        private void DisplayAsciiLetter(char currentChar)
        {
            string asciiArt = FiggleFonts.Standard.Render(currentChar.ToString());
            Console.SetCursorPosition(_currentPosition[0], _currentPosition[1]);

            Console.ForegroundColor = ConsoleColor.Red;
            foreach (string line in asciiArt.Split('\n'))
            {
                Console.SetCursorPosition(_currentPosition[0], _currentPosition[1]++);
                Console.WriteLine(line);
            }
            _currentPosition[1] -= asciiArt.Split('\n').Length;
        }

        private void ClearAndColor()
        {
            Console.Clear();
            Console.BackgroundColor = ConsoleColor.Black;
        }

        private int[] CalculateStartingPosition()
        {
            string asciiSample = FiggleFonts.Standard.Render(_title);
            string[] lines = asciiSample.Split('\n');

            int letterWidth = lines.Max(str => str.Length);
            int letterHeight = lines.Length;

            int xStart = (_consoleWidth - letterWidth) / 2;
            int yStart = (_consoleHeight - letterHeight) / 2;

            return new[] { xStart, yStart };
        }
    }
}

