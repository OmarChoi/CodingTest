using System;
using System.Collections;

class Program
{
    static void Main()
    {
        int nCard = int.Parse(Console.ReadLine());
        string inputStr = Console.ReadLine();
        string[] inputs = inputStr.Split(' ');

        List<int> cards = new List<int>();
        for (int i = 0; i < inputs.Length; ++i)
        {
            cards.Add(int.Parse(inputs[i]));
        }
        
        List<int> increaseArray = new List<int>();
        for (int i = 0; i < cards.Count; ++i)
        {
            int cardIndex = increaseArray.BinarySearch(cards[i]);
            if (cardIndex < 0)
            {
                cardIndex = -(cardIndex + 1);
            }

            if (cardIndex >= increaseArray.Count)
            {
                increaseArray.Add(cards[i]);
            }
            else
            {
                increaseArray[cardIndex] = cards[i];
            }
        }
        Console.WriteLine(increaseArray.Count);
    }
}