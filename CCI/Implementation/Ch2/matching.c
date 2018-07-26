
/*  Gale-Shapley Propose-and-Reject Algorithm, in C  */

#include <stdio.h>

void ignore() { ; }

#ifdef NDEBUG
#define TRACE ignore
#else
#define TRACE printf
#endif


#define N 6
int husband[N] = {0,  0, 0, 0, 0, 0 };
int wife[N]    = {0,  0, 0, 0, 0, 0 };
int choice[N]  = {0,  0, 0, 0, 0, 0 };

int mens_wife_preferences[N][N] = {{},
   {0,   2, 1, 4, 5, 3 },
   {0,   4, 2, 1, 3, 5 },
   {0,   2, 5, 3, 4, 1 },
   {0,   1, 4, 3, 2, 5 },
   {0,   2, 4, 1, 5, 3 }
};
int womens_husband_preferences[N][N] = {{},
   {0,   5, 1, 2, 4, 3 },
   {0,   3, 2, 4, 1, 5 },
   {0,   2, 3, 4, 5, 1 },
   {0,   1, 5, 4, 3, 2 },
   {0,   4, 2, 5, 3, 1 }
};
int mens_wife_orderings[N][N];
int womens_husband_orderings[N][N];

int i, j, r;

int dumped_guy;

static void make_next_choice_proposal(int i) {
   while ((wife[i] == 0) && choice[i]<N) {
      choice[i] += 1;
      j = mens_wife_preferences[i][choice[i]];   /* i proposes to j, his next choice */
      TRACE("man %d proposes to woman %d, his #%d choice\n", i, j, choice[i]);
      /* i proposes to j */
      if (husband[j] == 0) {    /*  woman j doesn't have a husband yet, so she accepts i  */
         TRACE("      woman %d accepts man %d\n", j, i);
         husband[j] = i;
         wife[i] = j;
      } else {
         if (womens_husband_orderings[j][i] < womens_husband_orderings[j][husband[j]] ) {
            dumped_guy = husband[j];
            TRACE("      woman %d dumps her present man %d, since she prefers man %d\n", j, dumped_guy, i);
            wife[dumped_guy] = 0;  /* dump the previous (less-preferred) husband of j */
            husband[j] = i;
            wife[i] = j;
            make_next_choice_proposal(dumped_guy);  /* the dumped guy makes another proposal */
         } else {
            TRACE("      woman %d rejects man %d\n", j, i);
         }
      }
   }
   TRACE("\n");
}

static void print_matrix(char * name, int A[N][N]) {
   printf("\n%s", name);
   for (i=1; i<N; i++) {
      printf("\n");
      for (j=1; j<N; j++) printf("%d ", A[i][j] );
   }
   printf("\n");
}

int main() {
   for (i=1; i<N; i++)  for (j=1; j<N; j++)   mens_wife_orderings[i][   mens_wife_preferences[i][j]] = j;
   for (j=1; j<N; j++)  for (i=1; i<N; i++)   womens_husband_orderings[j][womens_husband_preferences[j][i]] = i;

   print_matrix( "mens_wife_preferences",    mens_wife_preferences );
   print_matrix( "mens_wife_orderings",       mens_wife_orderings );
   print_matrix( "womens_husband_preferences", womens_husband_preferences );
   print_matrix( "womens_husband_orderings",    womens_husband_orderings );

   printf("\n");
   for (i=1; i<N; i++)   make_next_choice_proposal(i);      /* each man i makes his next proposal */

   printf("\n");
   for (i=1; i<N; i++) printf( " wife of %d is %d\n", i, wife[i] );

   printf("\n");
   for (j=1; j<N; j++) printf( " husband of %d is %d\n", j, husband[j] );

   return 0;
}

/* 
   OUTPUT

mens_wife_preferences
2 1 4 5 3 
4 2 1 3 5 
2 5 3 4 1 
1 4 3 2 5 
2 4 1 5 3 

mens_wife_orderings
2 1 5 3 4 
3 2 4 1 5 
5 1 3 4 2 
1 4 3 2 5 
3 1 5 2 4 

womens_husband_preferences
5 1 2 4 3 
3 2 4 1 5 
2 3 4 5 1 
1 5 4 3 2 
4 2 5 3 1 

womens_husband_orderings
2 3 5 4 1 
4 2 1 3 5 
5 1 2 3 4 
1 5 4 3 2 
5 2 4 1 3 

man 1 proposes to woman 2, his #1 choice
      woman 2 accepts man 1

man 2 proposes to woman 4, his #1 choice
      woman 4 accepts man 2

man 3 proposes to woman 2, his #1 choice
      woman 2 dumps her present husband 1, since she prefers man 3
man 1 proposes to woman 1, his #2 choice
      woman 1 accepts man 1


man 4 proposes to woman 1, his #1 choice
      woman 1 rejects man 4
man 4 proposes to woman 4, his #2 choice
      woman 4 dumps her present husband 2, since she prefers man 4
man 2 proposes to woman 2, his #2 choice
      woman 2 rejects man 2
man 2 proposes to woman 1, his #3 choice
      woman 1 rejects man 2
man 2 proposes to woman 3, his #4 choice
      woman 3 accepts man 2


man 5 proposes to woman 2, his #1 choice
      woman 2 rejects man 5
man 5 proposes to woman 4, his #2 choice
      woman 4 dumps her present husband 4, since she prefers man 5
man 4 proposes to woman 3, his #3 choice
      woman 3 rejects man 4
man 4 proposes to woman 2, his #4 choice
      woman 2 rejects man 4
man 4 proposes to woman 5, his #5 choice
      woman 5 accepts man 4



 wife of 1 is 1
 wife of 2 is 3
 wife of 3 is 2
 wife of 4 is 5
 wife of 5 is 4

 husband of 1 is 1
 husband of 2 is 3
 husband of 3 is 2
 husband of 4 is 5
 husband of 5 is 4

*/
