/**************************************************************************************************//**
 * 
 * @file colour16.h
 * 
 * @brief Contains the typedef of the @ref colour16_t type, along with the macro definition of its size
 *        and intended possible values.
 * 
 * @details The @ref colour16_t type is based on the 8–16 colours set.
 *          Such set contains 34 ANSI escape codes that tell the terminal to change its background or
 *          foreground colours.
 *          The 8-16 colours codes are not absolute, that is, their appereance can slightly vary,
 *          depending on the terminal.
 *          These are the 8 non-bright colours that will be displayed in an Ubuntu virtual terminal:
 *          <pre>
 *          Black:   <span class = "color-swatch" style = "background-color: #010101;"></span>
 *          Red:     <span class = "color-swatch" style = "background-color: #DE382B;"></span>
 *          Green:   <span class = "color-swatch" style = "background-color: #39B54A;"></span>
 *          Yellow:  <span class = "color-swatch" style = "background-color: #FFC706;"></span>
 *          Blue:    <span class = "color-swatch" style = "background-color: #006FB8;"></span>
 *          Magenta: <span class = "color-swatch" style = "background-color: #6E2671;"></span>
 *          Cyan:    <span class = "color-swatch" style = "background-color: #2CB5E9;"></span>
 *          White:   <span class = "color-swatch" style = "background-color: #CCCCCC;"></span>
 *          </pre>
 *          
 *          These are their bright counterparts (still as in an Ubuntu virtual terminal):
 *          <pre>
 *          Bright black:   <span class = "color-swatch" style = "background-color: #808080;"></span>
 *          Bright red:     <span class = "color-swatch" style = "background-color: #FF0000;"></span>
 *          Bright green:   <span class = "color-swatch" style = "background-color: #00FF00;"></span>
 *          Bright yellow:  <span class = "color-swatch" style = "background-color: #FFFF00;"></span>
 *          Bright blue:    <span class = "color-swatch" style = "background-color: #0000FF;"></span>
 *          Bright magenta: <span class = "color-swatch" style = "background-color: #FF00FF;"></span>
 *          Bright cyan:    <span class = "color-swatch" style = "background-color: #00FFFF;"></span>
 *          Bright white:   <span class = "color-swatch" style = "background-color: #FFFFFF;"></span>
 *          </pre>
 * 
 ******************************************************************************************************/

#ifndef COLOUR16_H
#define COLOUR16_H

#define C16_SIZE 6 /**< Size of the @ref colour16_t type. */

/**
 * Type intended to assume one of the 34 possible ANSI escape codes that allow for
 * setting the colour of terminal cells accordingly to the 8-16 colour set.
 */
typedef char colour16_t[C16_SIZE];

#define C16_FG_BLACK      "\e[030m"
#define C16_FG_RED        "\e[031m"
#define C16_FG_GREEN      "\e[032m"
#define C16_FG_YELLOW     "\e[033m"
#define C16_FG_BLUE       "\e[034m"
#define C16_FG_MAGENTA    "\e[035m"
#define C16_FG_CYAN       "\e[036m"
#define C16_FG_WHITE      "\e[037m"

#define C16_FG_DEFAULT    "\e[039m"

#define C16_BG_BLACK      "\e[040m"
#define C16_BG_RED        "\e[041m"
#define C16_BG_GREEN      "\e[042m"
#define C16_BG_YELLOW     "\e[043m"
#define C16_BG_BLUE       "\e[044m"
#define C16_BG_MAGENTA    "\e[045m"
#define C16_BG_CYAN       "\e[046m"
#define C16_BG_WHITE      "\e[047m"

#define C16_BG_DEFAULT    "\e[049m"

#define C16_FG_BR_BLACK   "\e[090m"
#define C16_FG_BR_RED     "\e[091m"
#define C16_FG_BR_GREEN   "\e[092m"
#define C16_FG_BR_YELLOW  "\e[093m"
#define C16_FG_BR_BLUE    "\e[094m"
#define C16_FG_BR_MAGENTA "\e[095m"
#define C16_FG_BR_CYAN    "\e[096m"
#define C16_FG_BR_WHITE   "\e[097m"

#define C16_BG_BR_BLACK   "\e[100m"
#define C16_BG_BR_RED     "\e[101m"
#define C16_BG_BR_GREEN   "\e[102m"
#define C16_BG_BR_YELLOW  "\e[103m"
#define C16_BG_BR_BLUE    "\e[104m"
#define C16_BG_BR_MAGENTA "\e[105m"
#define C16_BG_BR_CYAN    "\e[106m"
#define C16_BG_BR_WHITE   "\e[107m"

#endif // COLOUR16_H