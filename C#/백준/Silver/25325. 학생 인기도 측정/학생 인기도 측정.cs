using System.Text;

namespace CSharpSolve
{
    internal class Program
    {
        static void Main()
        {
            int nStudent = int.Parse(Console.ReadLine());
            string[] students = Console.ReadLine().Split(new[] { ' ' }, 
                StringSplitOptions.RemoveEmptyEntries);

            var likeCount = new Dictionary<string, int>();
            foreach (var name in students)
            {
                likeCount[name] = 0;
            }

            for (int i = 0; i < nStudent; ++i)
            {
                string[] likes = Console.ReadLine().Split(new[] { ' ' }, 
                    StringSplitOptions.RemoveEmptyEntries);

                foreach (var likedName in likes)
                {
                    likeCount[likedName] += 1;
                }
            }

            var result = new List<KeyValuePair<string, int>>(likeCount);
            result.Sort((a, b) =>
            {
                int cmp = b.Value.CompareTo(a.Value);
                return cmp != 0 ? cmp : string.Compare(a.Key, b.Key, StringComparison.Ordinal);
            });

            foreach (var kv in result)
            {
                Console.WriteLine($"{kv.Key} {kv.Value}");
            }
        }
    }
}