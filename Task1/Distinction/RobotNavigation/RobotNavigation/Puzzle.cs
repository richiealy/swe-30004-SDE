using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PriorityQueue
{
    class Puzzle
    {
        private int lineCount;
        private int rowCount, columnCount;
        private int startX, startY;
        private int endX, endY;
        private string[,] PuzzleMap;

        public Puzzle(){}

        public Puzzle(string aFileName)
        {
            lineCount = 0;
            rowCount = 0; columnCount = 0;
            startX = 0; startY = 0;
            endX = 0; endY = 0;

            string[] lines = File.ReadAllLines(aFileName);

            // Read Puzzle Specifications from file
            char[] removeThese = { '(', ')', '[', ']' }; // characters to ignore in file

            int[,] Walls = new int[lines.Length - 3, 4]; // Match wall array to size of file minus the size,start and end to get amount of walls

            foreach (string line in lines)
            {
                string[] newLines = line.Split(new char[] { ',' });

                for (int i = 0; i < newLines.Length; i++)
                {
                    newLines[i] = newLines[i].Trim(removeThese); // Use char array to remove unwanted characters
                }

                switch (lineCount)
                {
                    case 0:
                        rowCount = Int32.Parse(newLines[0]);
                        columnCount = Int32.Parse(newLines[1]);
                        break;
                    case 1:
                        startX = Int32.Parse(newLines[0]);
                        startY = Int32.Parse(newLines[1]);
                        break;
                    case 2:
                        endX = Int32.Parse(newLines[0]);
                        endY = Int32.Parse(newLines[1]);
                        break;
                    default:
                        Walls[lineCount - 3, 0] = Int32.Parse(newLines[0]);
                        Walls[lineCount - 3, 1] = Int32.Parse(newLines[1]);
                        Walls[lineCount - 3, 2] = Int32.Parse(newLines[2]);
                        Walls[lineCount - 3, 3] = Int32.Parse(newLines[3]);
                        break;
                }
                lineCount++;
            }

            // Construct Puzzle
            PuzzleMap = new string[columnCount, rowCount];

            // Assign values to start and end coordinates
            PuzzleMap[startX, startY] = "S";
            PuzzleMap[endX, endY] = "E";

            // Assign wall
            for (int w = 0; w < Walls.GetLength(0); w++)
            {
                PuzzleMap[Walls[w, 0], Walls[w, 1]] = "#";

                for (int j = 1; j < Walls[w, 2]; j++) // Width
                    PuzzleMap[Walls[w, 0] + j, Walls[w, 1]] = "#";

                for (int i = 1; i < Walls[w, 3]; i++) // Height
                {
                    PuzzleMap[Walls[w, 0], Walls[w,1] + i] = "#";
                    for (int j = 1; j < Walls[w, 2]; j++) // Width
                        PuzzleMap[Walls[w,0]+j , Walls[w, 1] +i] = "#";
                }

            }

            // Assign empty spaces           
            for (int i = 0; i < PuzzleMap.GetLength(1); i++)
            {
                for (int j = 0; j < PuzzleMap.GetLength(0); j++)
                {
                    if (PuzzleMap[j, i] == null)
                        PuzzleMap[j, i] = " ";
                }
            }

            // Draw Map
            for (int i = 0; i < PuzzleMap.GetLength(0) +2 ; i++)
                Console.Write("#");
            Console.WriteLine(" ");
            
            for (int i = 0; i < PuzzleMap.GetLength(1); i++)
            {
                Console.Write("#");
                for (int j = 0; j < PuzzleMap.GetLength(0); j++)
                    Console.Write(PuzzleMap[j, i]);

                Console.Write("#");
                Console.WriteLine(" ");
            }
            
            for (int i = 0; i < PuzzleMap.GetLength(0) + 2; i++)
                Console.Write("#");
            Console.WriteLine(" ");
        }

        public string[,] theMap
        {
            get
            {
                return PuzzleMap;
            }
        }
    }

}
