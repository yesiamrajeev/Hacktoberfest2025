public Dictionary<char, int> CountCharacters(string s)
{
    var freq = new Dictionary<char, int>();
    foreach (char c in s)
    {
        if (freq.ContainsKey(c)) freq[c]++;
        else freq[c] = 1;
    }
    return freq;
}
