// /*#include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     char plaintext[1000], ch;
//     int key ;
//     int i = 0;
//     printf("Enter a message to encrypt: ");
//     scanf("%s", plaintext);
//     printf("Enter a key: ");
//     scanf("%d", &key);
//     for (i = 0; plaintext[i] != '\0'; i++)
//     {
//         ch = plaintext[i];
//         if (isalnum(ch))
//         {
//             if (islower(ch))
//             {
//                 ch = (ch - 'a' + key) % 26 + 'a';
//             }
//             if (isupper(ch))
//             {
//                 ch = (ch - 'A' + key) % 26 + 'A';    
//             }
//         }
//         else
//         {
//             printf("Invalid Message");
//         }
//         plaintext[i] = ch;
//     }
//     printf("%s", plaintext);
// }*/


// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     char plaintext[1000], ch;
//     int key ;
//     int i = 0;
//     printf("Enter a message to encrypt: ");
//     scanf("%s", plaintext);
//     printf("Enter a key: ");
//     scanf("%d", &key);
//     for (i = 0; plaintext[i] != '\0'; i++)
//     {
//         ch = plaintext[i];
//         if (isalnum(ch))
//         {
//             if (islower(ch))
//             {
//                 ch = (ch - 'a' - key) % 26 + 'a';
//             }
//             if (isupper(ch))
//             {
//                 ch = (ch - 'A' - key) % 26 + 'A';    
//             }
//         }
//         else
//         {
//             printf("Invalid Message");
//         }
//         plaintext[i] = ch;
//     }
//     printf("%s", plaintext);
// }
// #include <stdio.h>
// #include <stdbool.h>
// #include <math.h>

// bool is_prime(int num) {
//     if (num < 2) {
//         return false;
//     }
//     for (int i = 2; i <= sqrt(num); i++) {
//         if (num % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// int sum_of_primes(int n) {
//     int primes_sum = 0;
//     for (int num = 2; num <= n; num++) {
//         if (is_prime(num)) {
//             primes_sum += num;
//         }
//     }
//     return primes_sum;
// }

// int main() {
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     int result = sum_of_primes(n);
//     printf("Sum of prime numbers up to %d is %d\n", n, result);
//     return 0;
// }

#include <stdio.h>
int main(){
    printf("Hello World\n");
    return 0;
}