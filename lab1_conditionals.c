#include <stdio.h>
#include <ctype.h> // for tolower

char inputStudentDetails(char studentFirstname[50], char studentLastname[50]) {
   // function to ask the user to enter a student's firstname and lastname and then combine them to be displayed later.

   printf("Enter the student's first name: ");
   scanf("%s", studentFirstname);

   printf("Enter the student's last name: ");
   scanf("%s", studentLastname);
}

int validateMarks() {
   // helper function to validate input for marks.

   int marks;

   while (1) {
      if (scanf("%d", &marks) == 1 && marks >= 0 && marks <= 100) {
            break; }  // valid input breaks the loop
      else {
         printf("\nInvalid input. Please enter a number between 0 and 100: ");
         while (getchar() != '\n'); // clears the input buffer
      }
   }

   return marks;
}

void inputStudentGrades(char moduleNames[][50], int moduleMarks[], int numberOfModules) {
   // function to repeatedly ask the user to input the module name and associated marks until all 5 have been inputted. The inputs are stored in the corresponding arrays.

   // loop to input module name and module marks
   for (int i = 0; i < numberOfModules; i++) {
        printf("\nEnter name of module %d: ", i + 1);
        scanf("%s", moduleNames[i]);  // store the module name in the array

        printf("Enter marks (0-100) for %s: ", moduleNames[i]);
        moduleMarks[i] = validateMarks(); // validate input and store the validated marks in the array
    }
}

float calculateAverage(int moduleMarks[], int numberOfModules) {
   // function to calculate the average score of the module. This will be used to determine the award.

   int total = 0;

    for (int i = 0; i < numberOfModules; i++) {
        total += moduleMarks[i];  // add the score to the total
    }

    return total / (float)numberOfModules;  // return the average as a float
}

int determineGradeClassification(float finalGrade) {
   // function to determine a student's final award based on their final grade. Returns a number that correlates to the grade classification.

   /*
   1 = "1st (First-Class)"
   2 = "2.1 (Upper Second-Class)"
   3 = "2.2 (Lower Second-Class)
   4 = "3rd"
   5 = "FAIL"
   */

   int gradeClass;

   if (finalGrade >= 69.5) {
      gradeClass = 1; } // "1st (First-Class)"
   else if ((finalGrade >= 59.5) && (finalGrade < 69.5)) {
      gradeClass = 2; } // "2.1 (Upper Second-Class)"
   else if ((finalGrade >= 49.5) && (finalGrade < 59.5)) {
      gradeClass = 3; } // "2.2 (Lower Second-Class)
   else if ((finalGrade >= 39.5) && (finalGrade < 49.5)) {
      gradeClass = 4; } // "3rd"
   else {
      gradeClass = 5; } // "FAIL"

    return gradeClass;
}

int determineAward (int gradeClass) {
   // function to determine if a student is eligible for an award using their grade classification.
   if (gradeClass == 1) {
    return 1;  // true
} else {
    return 0;  // false
   }
}

void displayResults(char studentFirstname[50], char studentLastname[50], char moduleNames[][50], int moduleMarks[], int numberOfModules, float finalGrade, int gradeClass, int eligibleForAward) {
   // function to display the student's results for each module, their final grade and whether or not they receive an award.

   printf("-------------------------\n");
   printf("---UoS Student Results---\n");
   printf("-------------------------\n");

   // display the student's full name.
   printf("Student Name: %s %s\n", studentFirstname, studentLastname);

   // display the Module names and marks for each.
   for (int i = 0; i < numberOfModules; i++) {
    printf("\nModule Name: %s\n", moduleNames[i]);
    printf("Marks: %d\n", moduleMarks[i]);
    }

   // display student's final grade.
   printf("\nFinal Grade: %.2f\n", finalGrade);

   // display grade classification.
   if (gradeClass == 1) {
      printf("Classification: 1st (First-Class)\n"); }
   else if (gradeClass == 2) {
      printf("Classification: 2.1 (Upper Second-Class)\n"); }
   else if (gradeClass == 3) {
      printf("Classification: 2.2 (Lower Second-Class)\n"); }
   else if (gradeClass == 4) {
      printf("Classification: 3rd\n"); }
   else {
      printf("Classification: FAIL\n"); }

   // display award eligibility.
   if (eligibleForAward == 1) {
    printf("\nThis student is eligible for an award.\n");
   } else {
    printf("\nThis student is not eligible for an award.\n");
   }

   printf("-------------------------");
}

char askToRepeat() {
    // function to ask the user if they want to run the program again. 'y' runs the program again and 'n' ends it.

    char choice;
    while (1) {
        printf("\nDo you want to enter another set of scores? (y/n): ");
        scanf("%c", &choice);
        choice = tolower(choice); // converts 'Y' or 'N' to lowercase.

        if (choice == 'y' || choice == 'n') {
            break;  // Valid input breaks the loop
        } else {
            printf("Invalid input. Please enter 'y' for yes or 'n' for no.\n");
            while (getchar() != '\n'); // clears the input buffer
        }
    }
    return choice;
}

int main() {
   char studentFirstname[50];
   char studentLastname[50];
   char moduleNames[5][50];
   int moduleMarks[5];
   int numberOfModules = 5;

   while (1) {
      inputStudentDetails(studentFirstname, studentLastname);

      inputStudentGrades(moduleNames, moduleMarks, numberOfModules);

      float finalGrade = calculateAverage(moduleMarks, numberOfModules);

      int gradeClass = determineGradeClassification(finalGrade);

      int eligibleForAward = determineAward(gradeClass);

      displayResults(studentFirstname, studentLastname, moduleNames, moduleMarks, numberOfModules, finalGrade, gradeClass, eligibleForAward);

      char choice = askToRepeat();

      if (choice == 'n') {
            printf("Exiting program. Goodbye!\n");
            break;  // Exit the while loop if user enters 'n' or 'N'
        }
   }

   return 0;
}
