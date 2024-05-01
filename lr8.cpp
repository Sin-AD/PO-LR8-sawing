using System;
using System.Linq;

class MainClass
{
public static void Main(string[] args)
{
while (true)
{
int length = int.Parse(Console.ReadLine());
if (length == 0) break;

int numCuts = int.Parse(Console.ReadLine());
int[] cuts = Console.ReadLine().Split().Select(int.Parse).ToArray();

int[] extendedCuts = new int[numCuts + 2];
extendedCuts[0] = 0;
Array.Copy(cuts, 0, extendedCuts, 1, numCuts);
extendedCuts[numCuts + 1] = length;

int[,] dp = new int[numCuts + 2, numCuts + 2];

for (int size = 2; size <= numCuts + 1; size++)
{
for (int left = 0; left + size <= numCuts + 1; left++)
{
int right = left + size;
dp[left, right] = int.MaxValue;

for (int middle = left + 1; middle < right; middle++)
{
dp[left, right] = Math.Min(dp[left, right], dp[left, middle] + dp[middle, right] + extendedCuts[right] - extendedCuts[left]);
}
}
}

Console.WriteLine("The minimum cutting price is {0}.", dp[0, numCuts + 1]);
}
}
}
