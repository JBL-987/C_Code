#include <stdio.h>

void adjust_time(int *hh, int *mm) {
    // Subtract one hour for GMT+7 adjustment
    *hh -= 1;
}

int main() {
    char course_code[11];  // Course code up to 10 characters + null terminator
    int start_hh, start_mm, end_hh, end_mm;

    for (int i = 0; i < 5; i++) {
        // Read input in the format "Course code HH:MM-HH:MM"
        scanf("%s %d:%d-%d:%d", course_code, &start_hh, &start_mm, &end_hh, &end_mm);
        
        // Adjust start and end times from GMT+8 to GMT+7
        adjust_time(&start_hh, &start_mm);
        adjust_time(&end_hh, &end_mm);

        // Output in the same format "Course code HH:MM-HH:MM"
        printf("%s %02d:%02d-%02d:%02d\n", course_code, start_hh, start_mm, end_hh, end_mm);
    }

    return 0;
}

