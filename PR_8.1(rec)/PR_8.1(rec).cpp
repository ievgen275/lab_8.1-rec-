#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str, int i)
{
    if (strlen(str) < 2)
        return 0;

    if (str[i + 1] != 0)
    {
        if ((str[i] == 's' && str[i + 1] == 'q') ||
            (str[i] == 'q' && str[i + 1] == 's'))
            return 1 + Count(str, i + 2);
        else
            return Count(str, i + 1);
    }
    else
    {
        return 0;
    }
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i + 1] != 0)
    {
        if ((str[i] == 's' && str[i + 1] == 'q') ||
            (str[i] == 'q' && str[i + 1] == 's'))
        {
            *t++ = '*';
            *t++ = '*';
            *t++ = '*';
            return Change(dest, str, t, i + 2);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " groups of 'SQ or QS'" << endl;

    char* dest = new char[151];
    dest[0] = '\0';
    char* result = Change(dest, str, dest, 0);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << result << endl;

    delete[] dest;
    return 0;
}
