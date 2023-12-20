using System;
using System.Dynamic;

namespace cs1;

class Program
{
    private static int[,] matrix = new int[20, 20];
    private static int x = 1;
    private static int y = 1;
    private static Random rand = new Random();

    public static void Main(string[] args)
    {
        

        int score = 0;

        Console.WriteLine("How much fruits?");
        int fruits = int.Parse(Console.ReadLine()!);

        for (int i = 0; i < fruits; i++)
        {
            RandomItems();
        }


        Console.Clear();


        MatrixSetBorder();

        

        matrix[y, x] = 1;
            
        while (true)
        {
            Console.CursorVisible = false;
            ClearConsole();
            //Console.Clear();
            OutMatrix();
            Console.WriteLine($"Score: {score}");
            var key = Console.ReadKey().Key;

            if (key == ConsoleKey.RightArrow)
            {
                int nextX = x == matrix.GetLength(1) - 2 ? 1 : x + 1;

                if (matrix[y, nextX] == 5)
                {
                    score++;
                }

                Right();
            }

            if (key == ConsoleKey.LeftArrow)
            {
                int nextX = x == 1 ? matrix.GetLength(1) - 2 : x - 1;

                if (matrix[y, nextX] == 5)
                {
                    score++;
                }

                Left();
            }

            if (key == ConsoleKey.UpArrow)
            {

                int nextY = y == 1 ? matrix.GetLength(1) - 2 : y - 1;

                if (matrix[nextY, x] == 5)
                {
                    score++;
                }

                Up();
            }

            if (key == ConsoleKey.DownArrow)
            {

                int nextY = y == matrix.GetLength(1) - 2 ? 1 : y + 1;

                if (matrix[nextY, x] == 5)
                {
                    score++;
                }


                Down();
            }

            if (key == ConsoleKey.Q)
            {
                break;
            }

            if (score == fruits)
            {
                Console.WriteLine("YOU WIN!!");
            }
        }
    }

    private static void ClearConsole()
    {
        Console.SetCursorPosition(0, 0);
    }

    public static void MatrixSetBorder()
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                if (i == 0 || i == matrix.GetLength(0) - 1)
                {
                    matrix[i, j] = 2;
                }
                else
                {
                    matrix[i, 0] = 3;
                    matrix[i, matrix.GetLength(0) - 1] = 3;
                    break;
                }
            }
        }
    }

    public static void OutMatrix()
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                if (matrix[i, j] == 0)
                {
                    Console.Write(" ");
                }
                else if (matrix[i, j] == 1)
                {
                    Console.Write("♥");
                }
                else if (matrix[i, j] == 2)
                {
                    Console.Write("-");
                }
                else if (matrix[i, j] == 3)
                {
                    Console.Write("|");
                }
                else if (matrix[i, j] == 5)
                {
                    Console.Write("♣");
                }

            }
            Console.WriteLine();
        }

    }

    //public static void ClearMatrix()
    //{
    //    for (int i = 0; i < matrix.GetLength(0); i++)
    //    {
    //        for (int j = 0; j < matrix.GetLength(1); j++)
    //        {
    //            matrix[i, j] = 0;
    //        }
    //    }
    //}

    public static void Up()
    {
        // ClearMatrix();
        int nextY = y == 1 ? matrix.GetLength(1) - 2 : y - 1;

        if (matrix[nextY, x] == 1)
        {
            Console.WriteLine("CRASHHHH!!! YOU ARE DEAD!!!");
            System.Environment.Exit(1);
        }

        if (y == 1)
        {
            y = matrix.GetLength(0) - 2;
        }
        else
        {
            y -= 1;
        }
        
        matrix[y, x] = 1;
    }
    public static void Down()
    {
        //  ClearMatrix();
        int nextY = y == matrix.GetLength(1) - 2 ? 1 : y + 1;

        if (matrix[nextY, x] == 1)
        {
            Console.WriteLine("CRASHHHH!!! YOU ARE DEAD!!!");
            System.Environment.Exit(1);
        }


        if (y == matrix.GetLength(1) - 2)
        {
            y = 1;
        }
        else
        {
            y += 1;
        }
        matrix[y, x] = 1;
    }
    public static void Right()
    {
        //  ClearMatrix();
        int nextX = x == matrix.GetLength(1) - 2 ? 1 : x + 1;

        if (matrix[y, nextX] == 1)
        {
            Console.WriteLine("CRASHHHH!!! YOU ARE DEAD!!!");
            System.Environment.Exit(1);
        }

        if (x == matrix.GetLength(1) - 2)
        {
            x = 1;
        }
        else 
        {
            x += 1;
        }
        matrix[y, x] = 1;
    }
    public static void Left()
    {
        // ClearMatrix();

        int nextX = x == 1 ? matrix.GetLength(1) - 2 : x - 1;    

        if ( matrix[y, nextX] == 1 )
        {
            Console.WriteLine("CRASHHHH!!! YOU ARE DEAD!!!");
            System.Environment.Exit(1);
        }

        if (x == 1)
        {
            x = matrix.GetLength(1) - 2;
        }
        else
        {
            x -= 1;
        }
        matrix[y, x] = 1;
    }

    static int count = 0;

    public static void RandomItems()
    {
        while (true)
        {
            int itemX = rand.Next(2, matrix.GetLength(0) - 1);
            int itemY = rand.Next(2, matrix.GetLength(1) - 1);

            if (matrix[itemX, itemY] == 5)
            {
                continue;
            }
            else 
            {
                count++;
                matrix[itemX, itemY] = 5;
                return;
            }

        }
    }
}