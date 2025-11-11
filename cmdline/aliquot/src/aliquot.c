#include<stdio.h>
#include<stdlib.h>

#define MAX_SUPPORTED 1000000000000000ULL //10^15
#define MAX_STEPS 1000000 // Όριο για την αποφυγή άπειρων βρόχων 

// Συνάρτηση που υπολογίζει το άθροισμα των γνήσιων διαιρετών 
unsigned long long sum_proper_divisors(unsigned long long n) {
    if (n < 2)
    return 0;
unsigned long long sum = 1; // 1 είναι πάντα γνήσιος διαιρέτης

for (unsigned long long i = 2; i*i <= n; i++) 
{
    if (n % i == 0) {
        unsigned long long other = n / i;
        if (i==other) 
        sum += i;
    else
    sum += i + other;

    }
}
return sum;
}

int main() {
    char a;
    unsigned long long n, l;
    printf("Please give the number to start the aliquot sequence from: ");
    if (scanf("%llu" , &n) != 1) {
        fprintf(stderr, "Invalid input. \n");
        exit(1);
    
    }
    printf(" Provide the max aliquot length to look for (0 for unlimited):");
    if (scanf("%llu" , &l) != 1) {
        fprintf(stderr , "Invalind input. \n");
        exit(1);

    }
    printf( "Do you want to print the full sequence ('f') or just the length ('l') ? ");
    if (scanf(" %c" , &a) != 1 || ( a != 'f' && a != 'l')) {
        fprintf(stderr , "Invalid input. \n");
        exit(1);
    
    }

    unsigned long long current = n;
    unsigned long long count = 0;
    
    while (1) {
        // Έμφανιση του τρέχοντος αριθμού αν ζητήθηκε πλήρης εκτύπωση 
    

        if  ( a == 'f') {
            printf("%llu\n" , current);

        }
        count++;

        //Έλεγχος υπέρβασης μήκους 
        if (l !=0 && count >= l) {
            if (a == 'l') 
            printf("Length of aliquot sequence: %llu\n" , count);
            else 
            exit(0);

        }
        unsigned long long next = sum_proper_divisors(current);

        if (next > MAX_SUPPORTED) {
            printf( "Number exceeds maximum supported integer (%llu).Stopping.\n" , MAX_SUPPORTED );
            exit (1);

        }
        //Αν φτάσουμε στο 0 τερματίζουμε
        if (next == 0) {
            if (a == 'l')
            printf ( "Length of aliquot sequence: %llu\n" , count);
        else
        printf("0\n");
        exit (0);

        }
        current = next; // Συνέχιση με τον επόμενο αριθμό

    }
    return 0;
}

