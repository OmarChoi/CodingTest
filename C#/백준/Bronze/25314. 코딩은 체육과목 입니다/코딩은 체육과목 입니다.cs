using System;

class Program
{
    static void Main()
    {
        string input = Console.ReadLine();
        int inputByte = int.Parse(input);
        
        int nLong = inputByte / 4;
        string answer = "";
        for (int i = 0; i < nLong; ++i) {
            answer += "long ";
        }
        answer += "int";
        
        Console.WriteLine(answer);
    }
}