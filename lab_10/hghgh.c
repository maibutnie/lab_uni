#include "hghgh.h"

void average_calculation(Student** groups, int amount, int index)
{
    float mid;
    for (int i = 0; i < amount; i++)
    {
        mid = 0;
        for (int j = 0; j < MARKS; j++)
            mid += groups[index][i].marks[j];
        groups[index][i].average = mid / MARKS;
    }
}

void average_for_all(Student** all_groups, int* for_marks)
{
    for (int i = 0; i < GROUPS; i++)
        average_calculation(all_groups, for_marks[i], i);
}

int doesitexist(Student* stud, int mark_it)
{
    for (int i = 0; i < MARKS; i++)
    {
        if (stud->marks[i] == mark_it)
            return 1;
    }
    return 0;
}

void swap(Student* first_element, Student* second_element)
{
    Student temp = *first_element;
    *first_element = *second_element;
    *second_element = temp;
}

void creating_mas(Student** groups, Student* mas)
{
    for (int i = 0; i < GROUPS; i++)
    {
        groups[i] = mas + i * GROUPS;
    }
}

Student** make_place()
{
    Student* mas = (Student*)calloc(GROUPS * MARKS, sizeof (Student));
    Student** groups = (Student**)calloc(MARKS, sizeof (Student*));
    creating_mas(groups, mas);
    return groups;
}

void input_size(int* n)
{
    printf("Enter amount of students:\n");
    scanf("%d", n);
    while (*n <= 0)
    {
        printf("Think better\n");
        printf("Enter amount of students:\n");
        scanf("%d", n);
    }
}

Student input_student()
{
    Student result;
    printf("Enter name of student:\n");
    scanf("%s", result.name);
    getchar();
    printf("Enter 5 of his marks:\n");
    for (int j = 0; j < MARKS; j++)
        scanf("%d", result.marks + j);
    printf("\n");
    return result;
}

void input_group(Student* group, int n)
{
    for (int i = 0; i < n; i++)
    {
        group[i] = input_student();
    }
}

Student* memory_for_group(int amount)
{
    return (Student*)calloc(amount, sizeof (Student));
}

void making_groups(Student** all_groups, Student* group, int* for_marks, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (doesitexist(group + i, 2))
        {
            all_groups[0][for_marks[0]] = group[i];
            for_marks[0]++;
        }
        else
        if (doesitexist(group + i, 3))
        {
            all_groups[1][for_marks[1]] = group[i];
            for_marks[1]++;
        }
        else
        if (doesitexist(group + i, 4))
        {
            all_groups[2][for_marks[2]] = group[i];
            for_marks[2]++;
        }
        else
        {
            all_groups[3][for_marks[3]] = group[i];
            for_marks[3]++;
        }
    }
}

int cmp_names(Student* s1, Student* s2)
{
    return strcmp(s1->name, s2->name) > 0;
}

void sorting(Student* group, int amount, int index)
{
    for (int i = 0; i < amount - 1; i++)
    {
        for (int j = i + 1; j < amount; j++)
        {
            if (cmp_names(group + i, group + j))
            {
                swap(group + i, group + j);
            }
        }
    }
}

void sorting_students(Student** all_groups, int* k)
{
    for (int i = 0; i < GROUPS; i++)
    {
        if (i == 0 && k[i] != 0)
            sorting(*(all_groups + i) + 0, k[i], i);
        else
        if (i == 1 && k[i] != 0)
            sorting(*(all_groups + i) + 0, k[i], i);
        else
        if (i == 2 && k[i] != 0)
            sorting(*(all_groups + i) + 0, k[i], i);
        else
        if (i == 3 && k[i] != 0)
            sorting(*(all_groups + i) + 0, k[i], i);
    }
}

void counting_fs(Student** groups, int* k)
{
    int count;
    for (int i = 0; i < k[0]; i++)
    {
        count = 0;
        for (int j = 0; j < MARKS; j++)
        {
            if (groups[0][i].marks[j] == 2)
                count++;
        }
        if (count > 2)
            groups[0][i].average = 0;
    }
}

void output_student(Student** groups, int for_marks, int index)
{
    for (int i = 0; i < for_marks + 1; i++)
    {
        if (groups[index][i].average != 0)
        {
            printf("Name: %s Marks: ", groups[index][i].name);
            for (int k = 0; k < MARKS; k++)
                printf("%d ", groups[index][i].marks[k]);
            printf("Average: %f\n", groups[index][i].average);
        }
    }
}

void output_group(Student** all_groups, int* for_marks)
{
    for (int i = 0; i < GROUPS; i++)
    {
        switch (i)
        {
            case 0:
                printf("Really bad: \n");
                output_student(all_groups, for_marks[0], 0);
                break;
            case 1:
                printf("Not so bad: \n");
                output_student(all_groups, for_marks[1], 1);
                break;
            case 2:
                printf("Pretty good: \n");
                output_student(all_groups, for_marks[2], 2);
                break;
            case 3:
                printf("Well done: \n");
                output_student(all_groups, for_marks[3], 3);
                break;
        }
    }
}
