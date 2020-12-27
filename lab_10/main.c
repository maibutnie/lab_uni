#include "hghgh.h"

int main()
{
    int n;
    input_size(&n);
    Student* group = memory_for_group(n);
    input_group(group, n);
    Student** all_groups = make_place();
    int for_marks[4] = {0};
    making_groups(all_groups, group, for_marks, n);
    average_for_all(all_groups, for_marks);
    counting_fs(all_groups, for_marks);
    sorting_students(all_groups, for_marks);
    output_group(all_groups, for_marks);
    return 0;
}
