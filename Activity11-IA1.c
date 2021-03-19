#include <stdio.h>

typedef struct studDetails {
    char name[100];
    int scores[100];
    float average;
    char grade;
}Student;

typedef struct reportCard {
    char subjectName[100];
    int no_scores, no_students;
    float weightage[100];
    Student student[100];
}Gradebook;

Student input_one_student(int no_scores)
{
    Student stud;

    scanf("%s", &stud.name);

    for (int i = 0; i < no_scores; i++)
        scanf("%d", &stud.scores[i]);

    return stud;
}

Gradebook input_one_gradebook()
{
    Gradebook subject;

    scanf("%s", &subject.subjectName);
    scanf("%d %d", &subject.no_students, &subject.no_scores);

    for (int i = 0; i < subject.no_scores; i++)
        scanf("%f", &subject.weightage[i]);

    for (int i = 0; i < subject.no_students; i++)
        subject.student[i] = input_one_student(subject.no_scores);

    return subject;
}

void input_n_gradebooks(int n, Gradebook gb[])
{
    for (int i = 0; i < n; i++)
        gb[i] = input_one_gradebook();
}

char compute_grade(Student stud)
{
    if (stud.average >= 0 && stud.average < 60)
        stud.grade = 'F';
    else if (stud.average >= 60 && stud.average < 70)
        stud.grade = 'D';
    else if (stud.average >= 70 && stud.average < 80)
        stud.grade = 'C';
    else if (stud.average >= 80 && stud.average < 90)
        stud.grade = 'B';
    else
        stud.grade = 'A';

    return stud.grade;
}

void compute_one_gradebook(Gradebook *pg)
{
    float sum = 0, weightSum = 0;

    for (int i = 0; i < pg->no_scores; i++)
        weightSum += pg->weightage[i];

    for (int i = 0; i < pg->no_students; i++)
    {
        sum = 0;

        for (int j = 0; j < pg->no_scores; j++)
            sum += pg->student[i].scores[j] * pg->weightage[j];

        pg->student[i].average = sum / weightSum;
        pg->student[i].grade = compute_grade(pg->student[i]);
    }
}

void compute_n_gradebooks(int n, Gradebook gb[n])
{
    for (int i = 0; i < n; i++)
        compute_one_gradebook(&gb[i]);
}

void print_one_student(Student stud)
{
    printf("%s %.2f %c\n", stud.name, stud.average, stud.grade);
}

void print_n_student(int n, Gradebook gb[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", gb[i].subjectName);

        for (int j = 0; j < gb[i].no_students; j++)
            print_one_student(gb[i].student[j]);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    Gradebook gb[n];

    input_n_gradebooks(n, gb);
    compute_n_gradebooks(n, gb);
    print_n_student(n, gb);

    return 0;
}