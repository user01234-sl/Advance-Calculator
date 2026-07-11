#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void write_to_log(char *text) {
    // Open the file in "append" mode ("a"). 
    // This adds new lines to the bottom without erasing past lines.
    FILE *file = fopen("calc_history.txt", "a");
    
    if (file != NULL) {
        fprintf(file, "%s\n", text); // Write the text and a newline
        fclose(file); // Safely close the file
    }
}

int main(int argc, char *argv[]) {
    
    char log_buffer[100]; // Holds up to 100 characters of text
    double result = 0;
    
    // BLOCK 1: Check if they typed at least the command
    if (argc < 2) {
        printf("Error: Missing arguments. Type 'calc help' for usage.\n");
        return 1;
    }
    
    // Grab the command early so the help menu check can use it safely!
    char *command = argv[1];
    
    // --- HELP MENU ---
    if (strcmp(command, "help") == 0) {
        printf("\n=== Termux Calculator Help Menu ===\n");
        printf("Usage: calc [command] [num1] [optional: num2]\n\n");
        printf("Single-Number Operations:\n");
        printf("  sqrt   - Calculate square root (e.g., calc sqrt 16)\n");
        printf("  round  - Round to nearest whole number (e.g., calc round 4.6)\n");
        printf("  ceil   - Force round UP (e.g., calc ceil 4.1)\n");
        printf("  floor  - Force round DOWN (e.g., calc floor 4.9)\n\n");
        printf("Two-Number Operations:\n");
        printf("  add    - Addition (e.g., calc add 5 10)\n");
        printf("  sub    - Subtraction\n");
        printf("  mul    - Multiplication\n");
        printf("  div    - Division\n");
        printf("  pow    - Exponents / Power\n");
        printf("===================================\n\n");
        return 0; // Exit successfully after showing help
    }

    // BLOCK 2: Initial Guard Rail
    // We need at least 3 words to run single number operations (e.g., "calc sqrt 16")
    if (argc < 3) {
        printf("Error: Missing arguments!\n");
        printf("Usage: calc [command] [num1] [optional: num2]\n");
        return 1;
    }
    
    // BLOCK 3: Data Extraction
    double num1 = atof(argv[2]);

    // BLOCK 4: Single-Number Operations Matrix
    if (strcmp(command, "sqrt") == 0) {
        if (num1 < 0) {
            printf("Error: Cannot calculate negative square root!\n");
            return 1;
        }
        result = sqrt(num1); // Save answer to result
        printf("Result: %.4f\n", result);
        sprintf(log_buffer, "sqrt(%.2f) = %.2f", num1, result);
        write_to_log(log_buffer);
        return 0; // Exits early because we are done
    }
    else if (strcmp(command, "round") == 0) {
        result = round(num1); // Save answer to result
        printf("Result: %.0f\n", result);
        sprintf(log_buffer, "round(%.2f) = %.0f", num1, result);
        write_to_log(log_buffer);
        return 0; // Exits early
    }
    else if (strcmp(command, "ceil") == 0) {
        result = ceil(num1); // Save answer to result
        printf("Result: %.0f\n", result);
        sprintf(log_buffer, "ceil(%.2f) = %.0f", num1, result);
        write_to_log(log_buffer);
        return 0; // Exits early
    }
    else if (strcmp(command, "floor") == 0) {
        result = floor(num1); // Save answer to result
        printf("Result: %.0f\n", result);
        sprintf(log_buffer, "floor(%.2f) = %.0f", num1, result);
        write_to_log(log_buffer);
        return 0; // Exits early
    }

    // BLOCK 5: Second Guard Rail
    // If we passed Block 4, we definitely need a second number (4 total arguments)
    if (argc < 4) {
        printf("Error: Command '%s' requires a second number!\n", command);
        return 1;
    }

    double num2 = atof(argv[3]);

    // BLOCK 6: Two-Number Operations Matrix
    if (strcmp(command, "add") == 0) {
        result = num1 + num2; // Save answer to result
        printf("Result: %.4f\n", result);
        sprintf(log_buffer, "%.2f + %.2f = %.2f", num1, num2, result);
        write_to_log(log_buffer);
    }
    else if (strcmp(command, "sub") == 0) {
        result = num1 - num2; // Save answer to result
        printf("Result: %.4f\n", result);
        sprintf(log_buffer, "%.2f - %.2f = %.4f", num1, num2, result);
        write_to_log(log_buffer);
    }
    else if (strcmp(command, "mul") == 0) {
        result = num1 * num2; // Save answer to result
        printf("Result: %.4f\n", result);
        sprintf(log_buffer, "%.2f * %.2f = %.4f", num1, num2, result);
        write_to_log(log_buffer);
    }
    else if (strcmp(command, "pow") == 0) {
        result = pow(num1, num2); // Save answer to result
        printf("Result: %.4f\n", result);
        sprintf(log_buffer, "%.2f ^ %.2f = %.4f", num1, num2, result);
        write_to_log(log_buffer);
    }
    else if (strcmp(command, "div") == 0) {
        if (num2 == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        result = num1 / num2; // Save answer to result
        printf("Result: %.4f\n", result);
        sprintf(log_buffer, "%.2f / %.2f = %.4f", num1, num2, result);
        write_to_log(log_buffer);
    }
    else {
        printf("Unknown command: '%s'\n", command);
        return 1;
    }

    return 0;
}
