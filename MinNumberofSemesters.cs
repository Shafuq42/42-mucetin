using System;
using System.Collections.Generic;

public class Solution
{
    public static void Main()
    {
        Console.Write(
         "###############################################################################################\n\n"
        + "                           Minimum dönem sayıcıya hoş geldiniz!\n"
        + "                                Örnek bir kullanım şekli:\n"
        + "                              Toplam kurs sayısı: 5 (enter)\n"
        + "                   Bir sömesterde en fazla kaç kurs olabilir: 2 (enter)\n"
        + "                           Kaç kurs birbiriyle bağlantılıdır: 4 \n"
        + "  Bağlantılı kursları giriniz (Örnek: 1,2) : 2,1 (enter) 3,1 (enter) 4,1 (enter) 1,5 (enter) \n"
        + "                              Çıktı: Minimum dönem sayısı: 4\n\n"
        + "###############################################################################################\n\n");

        Console.Write("Toplam kurs sayısı: ");
        int n = Convert.ToInt32(Console.ReadLine());  // toplam kurs adedini al

        Console.Write("Bir sömesterde en fazla kaç kurs olabilir: ");
        int k = Convert.ToInt32(Console.ReadLine());  // Sömester başı maksimum kurs adedini al

        Console.Write("Kaç adet kurs birbiriyle bağlantılıdır: ");
        int r = Convert.ToInt32(Console.ReadLine());  // Kaç tane relations indeksi 

        int[][] relations = new int[r][];

        for (int i = 0; i < r; i++) {
            Console.Write("Baglantili kurslari giriniz (Örnek 1,2) : ");
            string[] input = Console.ReadLine().Split(',');
            int x = Convert.ToInt32(input[0]) - 1;
            int y = Convert.ToInt32(input[1]) - 1;
            relations[i] = new int[] { x, y };
        }

        int semester = MinNumberOfSemesters(n, relations, k);

        Console.WriteLine($"Minimum dönem sayisi: {semester}");
    }

    public static int MinNumberOfSemesters(int n, int[][] relations, int k)
    {
        HashSet<int> taken = new HashSet<int>();
        List<int>[] prevCourse = new List<int>[n];
        List<int>[] nextCourse = new List<int>[n];
        int[] w = new int[n];
        int semester = 0;

        for (int i = 0; i < n; i++) {
            prevCourse[i] = new List<int>();
            nextCourse[i] = new List<int>();
        }

        foreach (int[] relation in relations) {
            int x = relation[0];
            int y = relation[1];
            prevCourse[y].Add(x);
            nextCourse[x].Add(y);
        }

        int[] weight = new int[n];

        for (int i = 0; i < n; i++) {
            foreach (int x in prevCourse[i]) {
                weight[x] = Math.Max(weight[x], prevCourse[i].Count);
            }
        }

        while (taken.Count < n) {
            List<int[]> courses = new List<int[]>();

            for (int i = 0; i < n; i++) {
                if (prevCourse[i].Count == 0 && !taken.Contains(i)) {
                    courses.Add(new int[] { i, w[i] });
                }
            }

            if (courses.Count > k) {
                courses.Sort((x, y) => y[1].CompareTo(x[1]));
                courses = courses.GetRange(0, k);
            }

            semester++;

            foreach (int[] x in courses) {
                foreach (int y in nextCourse[x[0]]) {
                    prevCourse[y].Remove(x[0]);
                }
                nextCourse[x[0]].Clear();
                taken.Add(x[0]);
            }
        }

        return semester;
    }
}
