#include <bits/stdc++.h>   // সব প্রয়োজনীয় লাইব্রেরি
using namespace std;      // std না লিখে সরাসরি ব্যবহার করার জন্য

int main()
{
    int arraySize;        
    cin >> arraySize;     // array এর size ইনপুট নিচ্ছে

    int integerArray[arraySize];   // array তৈরি করা

    for (int i = 0; i < arraySize; i++)
    {
        cin >> integerArray[i];   // array এর সব মান ইনপুট নিচ্ছে
    }

    int desiredNumber;    
    cin >> desiredNumber;   // যে সংখ্যাটা খুঁজবো সেটার ইনপুট

    bool flag = false;   // প্রথমে ধরা হলো সংখ্যা পাওয়া যায়নি

    for (int i = 0; i < arraySize; i++)
    {
        // পুরো array এক এক করে চেক করছে
        if (integerArray[i] == desiredNumber)
        {
            flag = true;   // যদি মিলে যায় তাহলে flag true
            break;         // পেয়ে গেলে আর খোঁজার দরকার নেই
        }
    }

    if (flag == true)
    {
        cout << "Yes\n";   // সংখ্যা পাওয়া গেলে Yes
    }
    else
    {
        cout << "No\n";    // না পেলে No
    }

    return 0;   // প্রোগ্রাম শেষ
}
