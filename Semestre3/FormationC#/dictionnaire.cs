namespace SmurfGetaway.Fundamentals.Collections;

public class Library
{
    public static void RegisterBook(Dictionary<int, string> collection, (int, string) book)
    {
          if (collection.ContainsKey(book.Item1))
            {
                throw new ArgumentException("Book with the same serial number already exists.");
            }

            collection.Add(book.Item1, book.Item2);
    }

    public static Dictionary<int, string> InitCollection(List<(int, string)> books)
    {
        Dictionary<int, string> collection = new Dictionary<int, string>();

        foreach (var book in books)
        {
            if (collection.ContainsKey(book.Item1))
            {
                throw new ArgumentException("Duplicate serial number found: " + book.Item1);
            }

            collection.Add(book.Item1, book.Item2);
        }

        return collection;

    }

    

}