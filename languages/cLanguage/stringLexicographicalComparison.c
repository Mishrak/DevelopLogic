#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Performs a standard lexicographical comparison.
 * Similar to memcmp, but handles the length logic explicitly.
 */
int standardLexicographicalComparison(const void *s1, int len1, const void *s2, int len2)
{
    // Senior Guard: Safety check
    if (!s1 || !s2)
    {
        return 0; 
    }

    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    int min_length = ((len1 < len2) ? len1 : len2);

    for (int i = 0; i < min_length; i++)
    {
        if (p1[i] < p2[i])
        {
            return -1;
        }
        if (p1[i] > p2[i])
        {
            return 1;
        }
        // If equal, the loop continues to the next character
    }

    // If all characters up to min_length are equal, the longer string is "greater"
    if (len1 < len2)
    {
        return -1;
    }
    if (len1 > len2)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief Compares two version strings (e.g., "4.2.1" and "4.10.5").
 * Uses a pointer-based approach to handle versions with any number of dots.
 */
int versionLexicographicalComparison(const char *s1, const char *s2)
{
    if (!s1 || !s2)
    {
        return 0;
    }

    const char *p1 = s1;
    const char *p2 = s2;

    while (*p1 != '\0' || *p2 != '\0')
    {
        int num1 = 0;
        int num2 = 0;

        // Extract numeric part from first string
        while (*p1 != '\0' && *p1 != '.')
        {
            num1 = num1 * 10 + (*p1 - '0');
            p1++;
        }

        // Extract numeric part from second string
        while (*p2 != '\0' && *p2 != '.')
        {
            num2 = num2 * 10 + (*p2 - '0');
            p2++;
        }

        if (num1 < num2) return -1;
        if (num1 > num2) return 1;

        // Skip the dot if we are at one
        if (*p1 == '.') p1++;
        if (*p2 == '.') p2++;
    }

    return 0;
}

int main(void)
{
    // Case where standard string comparison fails but version comparison succeeds
    char s1[] = "4.2.25";
    char s2[] = "4.10.25";

    printf("Comparing Versions: %s and %s\n", s1, s2);
    printf("--------------------------------------\n");

    // 1. Standard Comparison (will say 4.2.25 > 4.10.25 because '2' > '1')
    int res1 = standardLexicographicalComparison(s1, strlen(s1), s2, strlen(s2));
    printf("Standard String Result: %s\n", 
            (res1 < 0) ? "4.10.25 is greater" : "4.2.25 is greater");

    // 2. Version Comparison (will correctly say 4.10.25 > 4.2.25)
    int res2 = versionLexicographicalComparison(s1, s2);
    printf("Logical Version Result: %s\n", 
            (res2 < 0) ? "4.10.25 is greater" : "4.2.25 is greater");

    return 0;
}