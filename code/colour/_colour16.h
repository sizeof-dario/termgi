/*****************************************************************************
 * 
 * Module name:
 * 
 *      colour16.h
 * 
 * Sinopsis:
 * 
 *      Contains the typedef of the colour16_t type and its associated macros.
 * 
 *****************************************************************************/

#ifndef COLOUR16_H
#define COLOUR16_H

/************************************************/
/*                                              */
/*  0  1 2 3 4 5 6 → 7 characters → 7 bytes     */
/*  \e [ - - - m \0                             */
/*                                              */
    #define COLOUR16_TYPESIZE 7                 //
/*                                              */
    typedef char colour16_t[COLOUR16_TYPESIZE]; //
/*                                              */     
/************************************************/

/************************************************/
/*                                              */
/*      ↓↓↓↓      Colours macros      ↓↓↓↓      */

        // Foreground non-bright colours

#define FOREGROUND_BLACK            "\e[030m"
#define FOREGROUND_RED              "\e[031m"
#define FOREGROUND_GREEN            "\e[032m"
#define FOREGROUND_YELLOW           "\e[033m"
#define FOREGORUND_BLUE             "\e[034m"
#define FOREGROUND_MAGENTA          "\e[035m"
#define FOREGROUND_CYAN             "\e[036m"
#define FOREGROUND_WHITE            "\e[037m"

        // Foreground default

#define FOREGROUND_DEFAULT          "\e[039m"

        // Background non-bright colours

#define BACKGROUND_BLACK            "\e[040m"
#define BACKGROUND_RED              "\e[041m"
#define BACKGROUND_GREEN            "\e[042m"
#define BACKGROUND_YELLOW           "\e[043m"
#define BACKGORUND_BLUE             "\e[044m"
#define BACKGROUND_MAGENTA          "\e[045m"
#define BACKGROUND_CYAN             "\e[046m"
#define BACKGROUND_WHITE            "\e[047m"

        // Background default

#define BACKGROUND_DEFAULT          "\e[049m"

        // Foreground bright colours

#define FOREGROUND_BRIGHT_BLACK     "\e[090m"
#define FOREGROUND_BRIGHT_RED       "\e[091m"
#define FOREGROUND_BRIGHT_GREEN     "\e[092m"
#define FOREGROUND_BRIGHT_YELLOW    "\e[093m"
#define FOREGORUND_BRIGHT_BLUE      "\e[094m"
#define FOREGROUND_BRIGHT_MAGENTA   "\e[095m"
#define FOREGROUND_BRIGHT_CYAN      "\e[096m"
#define FOREGROUND_BRIGHT_WHITE     "\e[097m"

        // Background bright colours

#define BACKGROUND_BRIGHT_BLACK     "\e[100m"
#define BACKGROUND_BRIGHT_RED       "\e[101m"
#define BACKGROUND_BRIGHT_GREEN     "\e[102m"
#define BACKGROUND_BRIGHT_YELLOW    "\e[103m"
#define BACKGORUND_BRIGHT_BLUE      "\e[104m"
#define BACKGROUND_BRIGHT_MAGENTA   "\e[105m"
#define BACKGROUND_BRIGHT_CYAN      "\e[106m"
#define BACKGROUND_BRIGHT_WHITE     "\e[107m"

/*      ↑↑↑↑      Colours macros      ↑↑↑↑      */
/*                                              */
/************************************************/

// There is not reason to define colour8_t in another header file
//  since it uses the same escape sequences of colour16_t.
// Moreover, it's unlikely someone will need to use the proper 8 colours set.
//
// However, just for the sake of completeness,
//  I'll add the following three lines of code:

#define COLOUR8_H
#define COLOUR8_TYPESIZE 7
typedef char colour8_t [COLOUR8_TYPESIZE];

// It took forever, like, 30 seconds at most.

#endif // COLOUR16_H