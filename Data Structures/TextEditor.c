#include <unistd.h>  // Header file for POSIX API, provides access to POSIX operating system API, including read() function for reading input
#include <termios.h> // Header file for POSIX terminal I/O, provides terminal control functions like tcgetattr() and tcsetattr()
#include <stdlib.h>  // Header file for standard library functions, provides memory allocation and other utility functions like exit()
#include <errno.h>   // Header file for error handling, defines macros for reporting errors
#include <stdio.h>   // Header file for standard input/output functions, provides functions like printf()
#include <ctype.h>   // Header file for character classification functions, provides functions like iscntrl()

/**** defines - macros ****/

#define CTRL_KEY(k) ((k) & 0x1f)  // Macro to handle Ctrl key combinations, masks the character with 0x1f (31 in decimal)

/**** data ****/

struct termios orig_termios;  // Structure to store the original terminal attributes

/**** terminal ****/

// Function to handle fatal errors
void die(const char *s)
{
    perror(s);  // Print error message related to the last system call
    exit(1);    // Terminate the program with exit status 1
}

// Function to disable raw mode and restore original terminal attributes
void disableRawMode()
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)  // Set terminal attributes to original values, flushing data
    {
        die("tcsetattr");  // Call die() function with error message if tcsetattr() fails
    }   
}

// Function to enable raw mode by modifying terminal attributes
void enableRawMode()
{
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)  // Get current terminal attributes and store them in orig_termios
    {
        die("tcgetattr");  // Call die() function with error message if tcgetattr() fails
    }

    atexit(disableRawMode);  // Register disableRawMode() function to be called automatically on program exit

    struct termios raw = orig_termios;  // Create a copy of original terminal attributes
    
    // Modify terminal attributes for raw mode
    raw.c_iflag &= ~(BRKINT | INPCK | ICRNL | ISTRIP | IXON);  // Disable special input processing
    raw.c_oflag &= ~(OPOST);  // Disable output processing
    raw.c_cflag |= (CS8);     // Set character size to 8 bits per byte
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);  // Disable echo, canonical mode, and special characters
    raw.c_cc[VMIN] = 0;       // Set the minimum number of characters for non-canonical read to return
    raw.c_cc[VTIME] = 1;      // Set the timeout for non-canonical read in tenths of a second
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);  // Apply modified terminal attributes

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)  // Check if setting terminal attributes failed
    {   
        die("tcsetattr");  // Call die() function with error message if tcsetattr() fails
    } 
}

/**** init ****/

int main()
{
    enableRawMode();  // Call enableRawMode() function to enable raw mode for terminal input

    while (1)  // Infinite loop to read input characters and display their ASCII values
    {
        char c = '\0';  // Initialize character variable to store input character

        // Read one character from standard input and store it in c
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)  // Check for read error and non-blocking read condition
        {
            die("read");  // Call die() function with error message if read() fails
        }

        // Check if the character is a control character
        if (iscntrl(c))
        {
            printf("%d\r\n", c);  // Print the ASCII value of the control character
        }
        else
        {
            printf("%d ('%c')\r\n", c, c);  // Print the ASCII value and character itself
        }

        // Check if Ctrl+Q is pressed to exit the program
        if (c == CTRL_KEY('q'))
        {
            break;  // Exit the while loop and terminate the program
        }
    }
    
    return 0;  // Return 0 to indicate successful program execution
}
#include <unistd.h>  // Header file for POSIX API, provides access to POSIX operating system API, including read() function for reading input
#include <termios.h> // Header file for POSIX terminal I/O, provides terminal control functions like tcgetattr() and tcsetattr()
#include <stdlib.h>  // Header file for standard library functions, provides memory allocation and other utility functions like exit()
#include <errno.h>   // Header file for error handling, defines macros for reporting errors
#include <stdio.h>   // Header file for standard input/output functions, provides functions like printf()
#include <ctype.h>   // Header file for character classification functions, provides functions like iscntrl()

/**** defines - macros ****/

#define CTRL_KEY(k) ((k) & 0x1f)  // Macro to handle Ctrl key combinations, masks the character with 0x1f (31 in decimal)

/**** data ****/

struct termios orig_termios;  // Structure to store the original terminal attributes

/**** terminal ****/

// Function to handle fatal errors
void die(const char *s)
{
    perror(s);  // Print error message related to the last system call
    exit(1);    // Terminate the program with exit status 1
}

// Function to disable raw mode and restore original terminal attributes
void disableRawMode()
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)  // Set terminal attributes to original values, flushing data
    {
        die("tcsetattr");  // Call die() function with error message if tcsetattr() fails
    }   
}

// Function to enable raw mode by modifying terminal attributes
void enableRawMode()
{
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)  // Get current terminal attributes and store them in orig_termios
    {
        die("tcgetattr");  // Call die() function with error message if tcgetattr() fails
    }

    atexit(disableRawMode);  // Register disableRawMode() function to be called automatically on program exit

    struct termios raw = orig_termios;  // Create a copy of original terminal attributes
    
    // Modify terminal attributes for raw mode
    raw.c_iflag &= ~(BRKINT | INPCK | ICRNL | ISTRIP | IXON);  // Disable special input processing
    raw.c_oflag &= ~(OPOST);  // Disable output processing
    raw.c_cflag |= (CS8);     // Set character size to 8 bits per byte
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);  // Disable echo, canonical mode, and special characters
    raw.c_cc[VMIN] = 0;       // Set the minimum number of characters for non-canonical read to return
    raw.c_cc[VTIME] = 1;      // Set the timeout for non-canonical read in tenths of a second
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);  // Apply modified terminal attributes

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)  // Check if setting terminal attributes failed
    {   
        die("tcsetattr");  // Call die() function with error message if tcsetattr() fails
    } 
}

/**** init ****/

int main()
{
    enableRawMode();  // Call enableRawMode() function to enable raw mode for terminal input

    while (1)  // Infinite loop to read input characters and display their ASCII values
    {
        char c = '\0';  // Initialize character variable to store input character

        // Read one character from standard input and store it in c
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)  // Check for read error and non-blocking read condition
        {
            die("read");  // Call die() function with error message if read() fails
        }

        // Check if the character is a control character
        if (iscntrl(c))
        {
            printf("%d\r\n", c);  // Print the ASCII value of the control character
        }
        else
        {
            printf("%d ('%c')\r\n", c, c);  // Print the ASCII value and character itself
        }

        // Check if Ctrl+Q is pressed to exit the program
        if (c == CTRL_KEY('q'))
        {
            break;  // Exit the while loop and terminate the program
        }
    }
    
    return 0;  // Return 0 to indicate successful program execution
}
