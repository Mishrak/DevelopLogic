#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief Checks if two strings are anagrams of each other.
 * * Anagram logic: 
 * Two strings are anagrams if they have the same characters with 
 * the same frequencies.
 * * @param s1 First null-terminated string.
 * @param s2 Second null-terminated string.
 * @return true if anagram, false otherwise.
 */
bool is_anagram(const char *s1, const char *s2)
{
    // 1. Senior Optimization: Early exit if strings are NULL
    if (!s1 || !s2)
    {
        return false;
    }

    // 2. Early exit if lengths differ
    int len1 = (int)strlen(s1);
    int len2 = (int)strlen(s2);

    if (len1 != len2)
    {
        return false;
    }

    /**
     * 3. Use a frequency array instead of a Hash Table.
     * Since char values are limited (0-255), an array is O(1) space 
     * and much faster than heap-allocated nodes.
     */
    int counts[256] = { 0 };

    // 4. Single-pass frequency update
    for (int i = 0; i < len1; i++)
    {
        // Increment for string 1, decrement for string 2
        // Casting to unsigned char prevents negative indexing
        counts[(unsigned char)s1[i]]++;
        counts[(unsigned char)s2[i]]--;
    }

    // 5. Final validation: all counts must be zero
    for (int i = 0; i < 256; i++)
    {
        if (counts[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    // Input validation
    if (argc != 3)
    {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return -1;
    }

    // Process and report
    if (is_anagram(argv[1], argv[2]))
    {
        printf("'%s' and '%s' are anagrams.\n", argv[1], argv[2]);
    }
    else
    {
        printf("'%s' and '%s' are NOT anagrams.\n", argv[1], argv[2]);
    }

    return 0;
}